#include "BaseEdge.h"

BaseEdge::BaseEdge() {}

BaseEdge::BaseEdge(const BasePoint& point1, const BasePoint& point2)
{
    _point1 = point1;
    _point2 = point2;
}

BaseEdge::BaseEdge(const BaseEdge& other)
{
    _point1 = other.get_point1();
    _point2 = other.get_point2();
}


BasePoint& BaseEdge::get_point1()
{
    return _point1;
}

BasePoint& BaseEdge::get_point2()
{
    return _point2;
}


const BasePoint& BaseEdge::get_point1() const
{
    return _point1;
}

const BasePoint& BaseEdge::get_point2() const
{
    return _point2;
}


void BaseEdge::set_point1(BasePoint &point)
{
    _point1 = point;
}

void BaseEdge::set_point2(BasePoint &point)
{
    _point2 = point;
}
