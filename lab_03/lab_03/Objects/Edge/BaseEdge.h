#ifndef BASEEDGE_H
#define BASEEDGE_H

#include "Objects/simpleobject.h"
#include "Objects/Point/basepoint.h"

class BaseEdge : public VisibleObject
{
public:
    BaseEdge();
    BaseEdge(const BasePoint& point1, const BasePoint& point2);
    explicit BaseEdge(const BaseEdge& other);
    virtual ~BaseEdge() = default;

    BasePoint& get_point1();
    BasePoint& get_point2();

    const BasePoint& get_point1() const;
    const BasePoint& get_point2() const;

    void set_point1(BasePoint& point);
    void set_point2(BasePoint& point);


private:
    BasePoint _point1, _point2;
};

#endif // BASEEDGE_H
