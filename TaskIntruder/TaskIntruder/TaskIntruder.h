#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskIntruder.h"

class TaskIntruder : public QMainWindow
{
    Q_OBJECT

public:
    TaskIntruder(QWidget *parent = nullptr);
    ~TaskIntruder();

private:
    Ui::TaskIntruderClass ui;
};
