#include "testcalibration.h"
#include <QtSensors/QCompass>
#include <QDebug>

TestCalibration::TestCalibration(QObject *parent)
    : QObject(parent),
      stamp(0),
      numberReadings(0)
{
    timer = new QElapsedTimer();
    sensor = new QCompass(this);
    sensor->connectToBackend();
    sensor->setDataRate(100);
    sensor->setProperty("alwaysOn",true);
    connect(sensor,SIGNAL(readingChanged()),this,SLOT(readingChanged()));
    timer->start();
    sensor->start();
    if (!sensor->isActive()) {
        qWarning("Compass sensor didn't start!");
    }
}

TestCalibration::~TestCalibration()
{
    if (sensor->isActive())
        sensor->stop();
    delete timer;
}

void TestCalibration::readingChanged()
{
    QCompassReading *reading = sensor->reading();
    qWarning() << "calibration level:" << reading->calibrationLevel();

    qWarning() << timer->elapsed() << "milliseconds, readings: " << numberReadings;
    if (reading->calibrationLevel() < 1) {
        numberReadings++;
    } else {
        qWarning() << "<<<<<<<<<<<<<<<<<<<<<< Calibration finished >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
        qWarning() << "The calibration took" << timer->elapsed() << "milliseconds";
        qWarning() << "Number of readings" << numberReadings << "at dataRate" << sensor->dataRate();
        sensor->stop();
    }
}
