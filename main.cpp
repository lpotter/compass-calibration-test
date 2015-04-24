#include <QCoreApplication>
#include "testcalibration.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestCalibration test(&a);
    return a.exec();
}
