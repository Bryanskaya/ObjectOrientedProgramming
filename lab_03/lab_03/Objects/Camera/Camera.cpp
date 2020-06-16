#include "Camera.h"

Camera::Camera() {}

Camera::Camera(double x, double y, double z) : BaseCamera(x, y, z) {}

Camera::Camera(const Camera& other) : BaseCamera(other) {}

void Camera::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

SceneObject *Camera::clone()
{
    return new Camera(*this);
}

