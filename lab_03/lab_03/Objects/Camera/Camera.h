#ifndef POINT_H
#define POINT_H

#include "BaseCamera.h"

class ObjectVisitor; //

class Camera : public BaseCamera
{
public:
    Camera();
    Camera(double x, double y, double z);
    explicit Camera(const Camera& other);
    virtual ~Camera() {}

    virtual void accept(shared_ptr<ObjectVisitor>); //
    virtual unique_ptr<SceneObject> clone();
};

#endif // POINT_H
