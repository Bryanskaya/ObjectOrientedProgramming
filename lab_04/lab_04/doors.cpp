#include "doors.h"

Doors::Doors()
{
    _status = CLOSED;

    //QObject::connect(this, SIGNAL)
}

void Doors::slot_close()
{
    if (_status == CLOSING)
    {

        _status = CLOSED;
        emit DoorsClosed();

        cout << ">> Doors CLOSED!" << endl;
    }
}

void Doors::slot_open()
{
    if (_status == OPENING)
    {
        _status = OPENED;
        //time
        emit DoorsOpened();

        cout << ">> Doors OPENED!" << endl;
    }
}

void Doors::slot_closing()
{
    if (_status == OPENED)
    {
        _status = CLOSING;
        //time

        cout << ">> Doors CLOSING!" << endl;
    }
}

void Doors::slot_opening()
{
    if (_status == CLOSED)
    {
        _status = OPENING;
        //time

        cout << ">> Doors OPENING!" << endl;
    }
}
