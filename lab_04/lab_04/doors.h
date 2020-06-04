#ifndef DOORS_H
#define DOORS_H

#include <QObject>

#include <iostream>

using namespace std;

class Doors : public QObject
{
    Q_OBJECT

    enum DoorsStatus
    {
        CLOSED,
        OPENING,
        OPENED,
        CLOSING
    };

public:
    Doors();

    virtual ~Doors() {}//

public slots:
    void slot_open();
    void slot_close();

private slots: //
    void slot_opening();
    void slot_closing();

signals:
    void DoorsOpened();
    void DoorsClosed();

private:
    DoorsStatus _status;
};

#endif // DOORS_H
