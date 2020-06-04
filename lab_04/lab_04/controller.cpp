#include "controller.h"

Controller::Controller(size_t num, QWidget *parent) : QWidget(parent), _btn_box()
{
    _amount_floors = num;

    this->setLayout(&_btn_box);

    // порядок
    for (size_t i = static_cast<size_t>(_amount_floors); i > 0; i--)
    {
        LiftButton *button = new LiftButton(i, this);
        _btn_box.addWidget(button);
        _btn_arr.push_back(shared_ptr<LiftButton>(button));
    }
}


