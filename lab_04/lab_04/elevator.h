#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>

#include "controller.h"

class Elevator : public QObject
{
    Q_OBJECT

public:
    Elevator(size_t floor_num);
    virtual ~Elevator() {} //

    QWidget* get_qwidget();

private:
    Controller _controller;
};

#endif // ELEVATOR_H
