#ifndef POINTCREATOR_H
#define POINTCREATOR_H

#include "ObjectCreator.h"
#include "Objects/Point/Point.h"


class PointCreator : public ObjectCreator
{
public:
    PointCreator();
    PointCreator(double x, double y, double z) : _x(x), _y(y), _z(z) {}

    virtual ~PointCreator();

    virtual unique_ptr<SceneObject> create()
    {
        return unique_ptr<SceneObject>(new Point(_x, _y, _z));
    }

private:
    double _x, _y, _z;
};

#endif // POINTCREATOR_H
