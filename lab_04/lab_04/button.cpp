#include "button.h"

LiftButton::LiftButton(size_t num, QWidget *parent) : QPushButton(parent)
{
    _status = RELEASED;
    _floor_num = num;

    QObject::connect(this, SIGNAL(clicked()),
                     this, SLOT(slot_pressed()));
    QObject::connect(this, SIGNAL(released()),
                     this, SLOT(slot_released()));

    QString info;
    info.append(std::to_string(num).c_str());
    this->setText(info);
}

void LiftButton::slot_pressed()
{
    if (_status == RELEASED)
    {
        _status = PRESSED;
        emit btn_pressed(_floor_num);
    }
}

void LiftButton::slot_released()
{
    if (_status == PRESSED)
        _status = RELEASED;
}
