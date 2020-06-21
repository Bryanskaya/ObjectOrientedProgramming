#include "elevator.h"

Elevator::Elevator(size_t num, QWidget *parent) :
    QObject(parent), _controller(num), _cabine(1)
{
    QWidget::connect(&_controller, SIGNAL(send_aim(size_t)),
                     &_cabine, SLOT(slot_request(size_t)));
    QWidget::connect(&_controller, SIGNAL(send_aim(size_t)),
                     &_cabine, SLOT(slot_close(size_t)));

    QWidget::connect(&_cabine, SIGNAL(achieved_floor(size_t, Direction)),
                     &_controller, SLOT(achieved_floor(size_t, Direction)));

    cout << endl << "Elevator on the 1 floor" << endl << endl;
}

QWidget* Elevator::get_qwidget()
{
    return &_controller;
}
