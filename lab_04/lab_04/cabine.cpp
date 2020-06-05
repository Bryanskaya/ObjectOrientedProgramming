#include "cabine.h"

LiftCabine::LiftCabine(size_t floors, double delay_move)
{
    _status = SIGNAL_WAITING;
    _cur_floor = floors;
    _aim_floor = floors;
    _dir_moving = STAY;

    time_moving.setInterval(int(delay_move * 1000));

    QWidget::connect(this, SIGNAL(open_doors()),
                     &_doors, SLOT(slot_opening()));
    QWidget::connect(&_doors, SIGNAL(DoorsClosed()),
                     this, SLOT(slot_start()));
    QWidget::connect(&time_moving, SIGNAL(timeout()),
                     this, SLOT(slot_moving()));

    QWidget::connect(this, SIGNAL(start_moving()),
                     this, SLOT(slot_start()));
    QWidget::connect(this, SIGNAL(moving()),
                     this, SLOT(slot_moving()));
    QWidget::connect(this, SIGNAL(stop_moving()),
                     this, SLOT(slot_stop()));
    QWidget::connect(this, SIGNAL(wait_request()),
                     this, SLOT(slot_request()));
}

void LiftCabine::slot_close(size_t floor_num)
{
    if (_status != SIGNAL_WAITING || floor_num == _cur_floor)      return;

    _status = CLOSE_WAITING;

    _aim_floor = floor_num;

    if (_doors.is_closed())
        emit start_moving();
}

void LiftCabine::slot_start()
{
    if (_status != CLOSE_WAITING || !_doors.is_closed())    return;

    _status = START;

    cout << ">> Elevator started moving" << endl;

    if (_cur_floor < _aim_floor)    _dir_moving = UP;
    else    _dir_moving = DOWN;

    emit moving();
}

void LiftCabine::slot_moving()
{
    if (_status == MOVING)
    {
        if (_dir_moving == UP)      _cur_floor += 1;
        else if (_dir_moving == DOWN)   _cur_floor -= 1;

        cout << ">> Current floor is " << _cur_floor << endl;

        if (_cur_floor == _aim_floor)
            emit stop_moving();
        else
            time_moving.start();
    }
    else if (_status == START)
    {
        _status = MOVING;
        time_moving.start();
    }
}

void LiftCabine::slot_stop()
{
    if (_status != MOVING)      return;

    _status = STOP;

    cout << ">> Elevator stoped" << endl;
    cout << endl << ">> " << _aim_floor << " floor ARRIVED" << endl << endl;

    Direction dir_temp = _dir_moving;
    _dir_moving = STAY;

    emit open_doors();
    emit wait_request();
    emit achieved_floor(_aim_floor, dir_temp);
}


void LiftCabine::slot_request(size_t floor_num)
{
    if (_status == STOP)
    {
        _status = SIGNAL_WAITING;
    }
    else if (_status == SIGNAL_WAITING && (floor_num == _cur_floor))
    {
        emit open_doors();
        emit achieved_floor(floor_num, _dir_moving);
    }
}
