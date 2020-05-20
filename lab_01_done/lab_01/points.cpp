#include "points.h"

/*code_t alloc_points(arr_points_t &arr, unsigned int num)
{
    if (!num) return INCORRECT_DATA;

    arr = alloc_memory(num);
    if (!arr) return MEMORY_ERROR;

    arr = static_cast<arr_points_t>(malloc(sizeof(point_t) * num));
    if (!arr) return MEMORY_ERROR;

    return CORRECT_WORK;
}*/

/*void delete_point_arr(arr_points_t &arr)
{
    free(arr);
    arr = nullptr;
}*/

code_t scan_point_arr(arr_points_t &arr, unsigned int &num, FILE *f)
{
    if (!num || !arr) return INCORRECT_DATA;

    code_t code = CORRECT_WORK;
    for (unsigned int i = 0; !code && i < num; i++)
        code = scan_point(arr[i], f);
    return code;
}

code_t draw_points(const arr_points_t &arr, unsigned int num,
                   const point_t &view_point, draw_params_t &param)
{
    if (!num || !arr) return INCORRECT_DATA;

    point_t point;
    for (unsigned int i = 0; i < num; i++)
    {
        point = arr[i];
        projection_point(point, view_point);
        draw_point_general(point, param);
    }

    return CORRECT_WORK;
}

code_t get_point(point_t &point, arr_points_t &arr, unsigned int i)
{
    if (!arr) return INCORRECT_DATA;
    point = arr[i];
    return CORRECT_WORK;
}

code_t set_point(arr_points_t &arr, point_t &point, unsigned int i)
{
    if (!arr) return INCORRECT_DATA;
    arr[i] = point;
    return CORRECT_WORK;
}

