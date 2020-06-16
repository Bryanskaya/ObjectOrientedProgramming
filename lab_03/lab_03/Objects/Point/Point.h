#ifndef POINT_H
#define POINT_H

#include "basepoint.h"
#include "Visitors/ObjectVisitor.h"

class Point : public BasePoint
{
public:
    Point();
    Point(double x, double y, double z);
    explicit Point(const Point& other);
    virtual ~Point();

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual SceneObject* clone();
};

#endif // POINT_H
