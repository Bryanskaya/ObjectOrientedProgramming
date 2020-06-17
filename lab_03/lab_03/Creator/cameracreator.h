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

    virtual shared_ptr<SceneObject> create()
    {
        shared_ptr<SceneObject> temp(new Camera(_x, _y, _z));
        //return shared_ptr<SceneObject>(new Camera(_x, _y, _z));
        return temp;
    }

private:
    double _x, _y, _z;
};

#endif // CAMERACREATOR_H
