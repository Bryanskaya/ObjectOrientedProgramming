#include "doors.h"

Doors::Doors(double delay_opening, double delay_closing,
             double delay_open)
{
    _status = CLOSED;

    time_opening.setInterval(int(delay_opening * 1000));
    time_closing.setInterval(int(delay_closing * 1000));
    time_open.setInterval(int(delay_open * 1000));

    QWidget::connect(&time_opening, SIGNAL(timeout()),
                     this, SLOT(slot_open()));
    QWidget::connect(&time_open, SIGNAL(timeout()),
                     this, SLOT(slot_closing()));
    QWidget::connect(&time_closing, SIGNAL(timeout()),
                     this, SLOT(slot_close()));
}

void Doors::slot_close()
{
    if (_status == CLOSING)
    {

        _status = CLOSED;
        cout << ">> Doors CLOSED!" << endl;

        emit DoorsClosed();
    }
}

void Doors::slot_open()
{
    if (_status == OPENING)
    {
        _status = OPENED;
        cout << ">> Doors OPENED!" << endl;

        emit DoorsOpened();
        time_open.start();
    }
}

void Doors::slot_closing()
{
    if (_status == OPENED)
    {
        _status = CLOSING;
        cout << ">> Doors CLOSING!" << endl;

        time_closing.start();
    }
}

void Doors::slot_opening()
{
    if (_status == CLOSED)
    {
        _status = OPENING;
        cout << ">> Doors OPENING!" << endl;

        time_opening.start();
    }
}

bool Doors::is_closed()
{
    return _status == CLOSED;
}
