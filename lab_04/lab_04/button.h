#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QObject>
#include <iostream>

using namespace std;

class LiftButton : public QPushButton
{
    Q_OBJECT

    enum ButtonStatus
    {
        PRESSED,
        RELEASED
    };

public:
    LiftButton(size_t floor_num, QWidget *parent = nullptr);//explicit
    virtual ~LiftButton() {}

public slots:
    void slot_pressed();
    void slot_released();

signals:
    void btn_pressed(size_t floor_num);

private:
    size_t _floor_num;
    ButtonStatus _status;
};

#endif // BUTTON_H
