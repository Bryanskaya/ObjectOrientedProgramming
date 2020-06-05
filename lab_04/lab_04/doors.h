#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QWidget>
#include <QTimer>

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
    Doors(double delay_opening = 1.5, double delay_closing = 1.5,
          double delay_open = 2);

    virtual ~Doors() {}

    bool is_closed();

public slots:
    void slot_open();
    void slot_close();

private slots:
    void slot_opening();
    void slot_closing();

signals:
    void DoorsOpened();
    void DoorsClosed();

private:
    DoorsStatus _status;

    QTimer time_opening;
    QTimer time_closing;

    QTimer time_open;
};

#endif // DOORS_H
