#ifndef FUNC_POINT_H
#define FUNC_POINT_H

#define DX                 350
#define DY                 350
#define DZ                1000

#include "global_attributes.h"
#include "draw_interface.h"
#include "operations.h"

typedef struct
{
    double x, y, z;
}point_t;

point_t create_point(double x, double y, double z);
point_t init_view_point(void);
code_t scan_point(point_t &point, FILE *f);
void move_point(point_t &point, const point_t &center);
void rotate_point(point_t &point, const point_t &center, const rotate_t &rotate);
void scale_point(point_t &point, const point_t &center, const scale_t &scale);

code_t draw_axis(draw_params_t &param, const point_t &view_point);
code_t draw_point_general(const point_t &point, draw_params_t &param);

void projection_point(point_t &point, const point_t &view_point);




#endif // FUNC_POINT_H
