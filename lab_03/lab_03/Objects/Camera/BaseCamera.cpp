#include "BaseCamera.h"

BaseCamera::BaseCamera() {}

BaseCamera::BaseCamera(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

BaseCamera::BaseCamera(const BaseCamera& other)
{
    _x = other.get_x();
    _y = other.get_y();
    _z = other.get_z();
}

double& BaseCamera::get_x()
{
    return _x;
}

double& BaseCamera::get_y()
{
    return _y;
}

double& BaseCamera::get_z()
{
    return _z;
}


double BaseCamera::get_x() const
{
    return _x;
}

double BaseCamera::get_y() const
{
    return _y;
}

double BaseCamera::get_z() const
{
    return _z;
}


void BaseCamera::set_x(double elem)
{
    _x = elem;
}

void BaseCamera::set_y(double elem)
{
    _y = elem;
}

void BaseCamera::set_z(double elem)
{
    _z = elem;
}
