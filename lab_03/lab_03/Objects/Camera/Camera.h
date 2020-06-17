#ifndef CAMERA_H
#define CAMERA_H

#include "BaseCamera.h"
#include "Visitors/ObjectVisitor.h"


class Camera : public BaseCamera
{
public:
    Camera();
    Camera(double x, double y, double z);
    explicit Camera(const Camera& other);
    virtual ~Camera();

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual SceneObject* clone();
};

#endif // CAMERA_H
