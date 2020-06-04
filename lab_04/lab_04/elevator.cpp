#include "elevator.h"

Elevator::Elevator(size_t num) : _controller(num) {}

QWidget* Elevator::get_qwidget()
{
    return &_controller;
}
