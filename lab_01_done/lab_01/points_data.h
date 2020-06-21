#ifndef POINTS_DATA_H
#define POINTS_DATA_H

#include "points.h"
#include "transform.h"

typedef struct
{
    unsigned int num_p;
    arr_points_t arr_p;
}points_data_t;

points_data_t init_points(void);
code_t scan_points_data(points_data_t &points_data_t, FILE *f);
void delete_points_data(points_data_t &points);
code_t move_points_data(points_data_t &points, const transform_t &transf);
code_t rotate_points_data(points_data_t &points, const transform_t &transf);
code_t scale_points_data(points_data_t &points, const transform_t &transf);

code_t draw_points_data(const points_data_t &points, const point_t &view_point, draw_params_t &param);

#endif // POINTS_DATA_H
