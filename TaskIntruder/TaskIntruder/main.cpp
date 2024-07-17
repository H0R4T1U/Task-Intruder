#include "TaskIntruder.h"
#include <QtWidgets/QApplication>
#include "enum.hpp"
#include<QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    qputenv("QT_ASSUME_STDERR_HAS_CONSOLE", "1");

    qInfo() << enumerate();
    QApplication a(argc, argv);
    TaskIntruder w;
    w.show();
    return a.exec();
}
