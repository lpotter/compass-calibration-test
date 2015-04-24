#ifndef TESTCALIBRATION_H
#define TESTCALIBRATION_H

#include <QObject>
#include <QtSensors/QCompass>
#include <QElapsedTimer>

class TestCalibration : public QObject
{
    Q_OBJECT
public:
    explicit TestCalibration(QObject *parent = 0);
    ~TestCalibration();
    QCompass *sensor;
signals:

public slots:
     void readingChanged();

private:
     qtimestamp stamp;
     QElapsedTimer *timer;
     int numberReadings;
};

#endif // TESTCALIBRATION_H
