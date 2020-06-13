#ifndef CAMERACREATOR_H
#define CAMERACREATOR_H

#include "ObjectCreator.h"
#include "Objects/Camera/Camera.h"


class CameraCreator : public ObjectCreator
{
public:
    CameraCreator();
    CameraCreator(double x, double y, double z) : _x(x), _y(y), _z(z) {}

    virtual ~CameraCreator();

    virtual unique_ptr<SceneObject> create()
    {
        return unique_ptr<SceneObject>(new Camera(_x, _y, _z));
    }

private:
    double _x, _y, _z;
};

#endif // CAMERACREATOR_H
