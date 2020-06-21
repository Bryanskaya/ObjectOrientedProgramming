#ifndef POINTS_H
#define POINTS_H

#include "point.h"
#include "transform.h"

typedef point_t* arr_points_t;

code_t alloc_points(arr_points_t &arr, unsigned int num);
code_t scan_point_arr(arr_points_t &arr, unsigned int &num, FILE *f);
void delete_point_arr(arr_points_t &arr);
code_t move_points(arr_points_t &arr, unsigned int num, const point_t &center);
code_t rotate_points(arr_points_t &arr, unsigned int num, const transform_t &transf);
code_t scale_points(arr_points_t &arr, unsigned int num, const transform_t &transf);

code_t draw_points(const arr_points_t &arr, unsigned int num, const point_t &view_point, draw_params_t &param);


code_t get_point(point_t &point, arr_points_t &arr, unsigned int i);
code_t set_point(arr_points_t &arr, point_t &point, unsigned int i);

#endif // POINTS_H
