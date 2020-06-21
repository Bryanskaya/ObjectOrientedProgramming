#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>

#include "controller.h"
#include "cabine.h"


class Elevator : public QObject
{
    Q_OBJECT

public:
    Elevator(size_t floor_num, QWidget *parent = nullptr);
    virtual ~Elevator() {}

    QWidget* get_qwidget();

private:
    Controller _controller;
    LiftCabine _cabine;
};

#endif // ELEVATOR_H
