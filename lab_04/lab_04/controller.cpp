#include "controller.h"

Controller::Controller(size_t num, QWidget *parent) : QWidget(parent), _btn_box()
{
    _amount_floors = num;

    this->setLayout(&_btn_box);

    QWidget::connect(this, SIGNAL(next_aim(size_t)),
                     this, SLOT(get_new_aim(size_t)));

    for (size_t i = 1; i <= static_cast<size_t>(_amount_floors); i++)
    {
        LiftButton *button = new LiftButton(i, this);

        QWidget::connect(button, SIGNAL(btn_pressed(size_t)),
                         this, SLOT(get_new_aim(size_t)));

        _btn_arr.push_back(shared_ptr<LiftButton>(button));
        _request_arr.push_back(false);
    }

    for (int i = int(_amount_floors) - 1; i >= 0; i--)
    {
        shared_ptr<LiftButton> ptr = _btn_arr[size_t(i)];
        _btn_box.addWidget(ptr.get());
    }
}

void Controller::achieved_floor(size_t floor_num, Direction dir)
{
    _status = WAITING_SIGNAL;
    _request_arr[floor_num - 1] = false;

    size_t next_floor = find_next_request(floor_num, dir);

    if (next_floor <= _amount_floors)
    {
        cout << ">> Next request is " << next_floor << " floor" << endl;

        emit next_aim(next_floor);
    }
}

void Controller::get_new_aim(size_t floor_num)
{
    _status = HANDLING_SIGNAL;

    _request_arr[floor_num - 1] = true;

    cout << ">> Request " << floor_num << " floor" << endl;

    emit send_aim(floor_num);
}

size_t Controller::find_next_request(size_t floor_num, Direction dir)
{
    if (!dir) dir = UP;

    for (int i = int(floor_num) - 1; 0 <= i && i < int(_amount_floors); i += dir)
        if (_request_arr[size_t(i)])    return size_t(i) + 1;

    for (int i = int(floor_num) - 1; 0 <= i && i < int(_amount_floors); i -= dir)
        if (_request_arr[size_t(i)])    return size_t(i) + 1;

    return _amount_floors + 1;
}
