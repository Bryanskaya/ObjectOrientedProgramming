#ifndef POINT_H
#define POINT_H

#include "basepoint.h"

class ObjectVisitor; //

class Point : public BasePoint
{
public:
    Point();
    Point(double x, double y, double z);
    explicit Point(const Point& other);
    virtual ~Point() {}

    virtual void accept(shared_ptr<ObjectVisitor>); //
    virtual unique_ptr<SceneObject> clone();
};

#endif // POINT_H
