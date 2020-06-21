#include "transform.h"

rotate_t init_rotate(double ax, double ay, double az)
{
    rotate_t rotate;
    rotate.ax = ax;
    rotate.ay = ay;
    rotate.az = az;
    return rotate;
}

scale_t init_scale(double kx, double ky, double kz)
{
    scale_t scale;
    scale.kx = kx;
    scale.ky = ky;
    scale.kz = kz;
    return scale;
}

double to_radians(double angle)
{
    return angle * PI / 180;
}

