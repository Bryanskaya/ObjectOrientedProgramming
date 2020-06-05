#ifndef CABINE_H
#define CABINE_H

#include <QObject>
#include <QTimer>

#include "doors.h"

enum Direction
{
    UP = 1,
    STAY = 0,
    DOWN = -1
};

class LiftCabine : public QObject
{
    Q_OBJECT

    enum LiftCabineStatus
    {
        START,
        MOVING,
        STOP,
        SIGNAL_WAITING,
        CLOSE_WAITING
    };

public:
    LiftCabine(size_t floors, double delay_move = 2);
    virtual ~LiftCabine() {}

signals:
    void start_moving();
    void moving();
    void stop_moving();

    void open_doors();
    void wait_request();
    void achieved_floor(size_t floor_num, Direction dir);

public slots:
    void slot_close(size_t floor_num);
    void slot_request(size_t floor_num = 0);

private slots:
    void slot_start();
    void slot_moving();
    void slot_stop();

private:
    LiftCabineStatus _status;

    size_t _cur_floor;
    size_t _aim_floor;

    Direction _dir_moving;

    Doors _doors;

    QTimer time_moving;

};

#endif // CABINE_H
