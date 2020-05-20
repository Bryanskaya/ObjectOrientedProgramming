#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "point.h"
#include "operations.h"
#include "global_attributes.h"

typedef struct
{
    point_t center;
    rotate_t rotate;
    scale_t scale;
}transform_t;

rotate_t init_rotate(double ax, double ay, double az);
scale_t init_scale(double kx, double ky, double kz);
double to_radians(double angle);

#endif // TRANSFORM_H
