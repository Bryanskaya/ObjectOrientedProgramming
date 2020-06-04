#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>

#include <memory>

#include "button.h"

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
    virtual ~Controller()
    {
        /*for (unsigned int i = 0; i < _amount_floors; i++)
            delete _btn_arr[i];

        delete _btn_box;*/
    }

/*public slots:
    //

signals:*/
    //

private:
    ControllerStatus _status;
    size_t _cur_floor; //
    size_t _amount_floors;

    list<shared_ptr<LiftButton>> _btn_arr;

    QVBoxLayout _btn_box;
};

#endif // CONTROLLER_H
