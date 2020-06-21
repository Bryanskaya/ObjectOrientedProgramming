#include "Point.h"

Point::Point() {}

Point::~Point() {}


Point::Point(double x, double y, double z) : BasePoint(x, y, z) {}

Point::Point(const Point& other) : BasePoint(other) {}

void Point::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

SceneObject *Point::clone()
{
    return new Point(*this);
}

