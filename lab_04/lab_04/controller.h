#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>

#include <memory>

#include "button.h"
#include "cabine.h"

using namespace std;

class Controller : public QWidget
{
    Q_OBJECT

    enum ControllerStatus
    {
        WAITING_SIGNAL,
        HANDLING_SIGNAL
    };

public:
    Controller(size_t floor_num, QWidget *parent = nullptr);
    virtual ~Controller() {}

public slots:
    void achieved_floor(size_t floor_num, Direction dir);

private slots:
    void get_new_aim(size_t floor_num);

signals:
    void send_aim(size_t floor_num);
    void next_aim(size_t floor_num);

private:
    ControllerStatus _status;
    size_t _amount_floors;

    vector<shared_ptr<LiftButton>> _btn_arr;
    vector<bool> _request_arr;

    QVBoxLayout _btn_box;

    size_t find_next_request(size_t floor_num, Direction dir);
};

#endif // CONTROLLER_H
