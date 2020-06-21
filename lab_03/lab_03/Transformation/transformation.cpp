#include "Transformation.h"


Transformation::Transformation() {}

Transformation::~Transformation() {}


Move::Move(double dx, double dy, double dz) : _dx(dx), _dy(dy), _dz(dz) {}

void Move::execute(double &x, double &y, double &z)
{
    x += _dx;
    y += _dy;
    z += _dz;
}


Rotate::Rotate(double ax, double ay, double az) : _ax(ax), _ay(ay), _az(az) {}

void Rotate::execute(double &x, double &y, double &z)
{
    Rotate::rotate_x(x, y, z);
    Rotate::rotate_y(x, y, z);
    Rotate::rotate_z(x, y, z);
}

double to_radians(double angle)
{
    return angle * PI / 180;
}

void Rotate::rotate_x(double&, double &y, double &z)
{
    double ax = to_radians(_ax);
    double y_temp, z_temp;

    y_temp = y * cos(ax) + z * sin(ax);
    z_temp = z * cos(ax) - y * sin(ax);
    y = y_temp;
    z = z_temp;
}

void Rotate::rotate_y(double &x, double&, double &z)
{
    double ay = to_radians(_ay);
    double x_temp, z_temp;

    x_temp = x * cos(ay) - z * sin(ay);
    z_temp = z * cos(ay) + x * sin(ay);
    x = x_temp;
    z = z_temp;
}

void Rotate::rotate_z(double &x, double &y, double&)
{
    double az = to_radians(_az);
    double x_temp, y_temp;

    x_temp = x * cos(az) + y * sin(az);
    y_temp = y * cos(az) - x * sin(az);
    x = x_temp;
    y = y_temp;
}


Scale::Scale(double kx, double ky, double kz) : _kx(kx), _ky(ky), _kz(kz) {}

void Scale::execute(double &x, double &y, double &z)
{
    x *= _kx;
    y *= _ky;
    z *= _kz;
}
