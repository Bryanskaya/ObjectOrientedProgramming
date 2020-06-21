#include "points_data.h"
#include "memory.h"

points_data_t init_points(void)
{
    points_data_t points;

    points.num_p = 0;
    points.arr_p = nullptr;

    return points;
}

code_t scan_points_num(unsigned int &num, FILE *f)
{
    if (!f) return EMPTY_FILE;

    unsigned int temp;
    int rc = fscanf(f, "%u", &temp);

    if (rc != 1 || !temp) return INCORRECT_INPUT;

    num = temp;
    return CORRECT_WORK;
}

code_t alloc_points_data(points_data_t &data, unsigned int num)
{
    if (!num) return INCORRECT_DATA;

    data.arr_p = alloc_points_memory(num);
    if (!data.arr_p) return MEMORY_ERROR;

    data.num_p = num;

    return CORRECT_WORK;
}

code_t scanning_points(points_data_t &data_points, FILE *f)
{
    if (!data_points.num_p) return INCORRECT_DATA;

    point_t point;
    code_t code = CORRECT_WORK;
    for (unsigned int i = 0; !code && i < data_points.num_p; i++)
    {
        code = scan_point(point, f);
        if (!code)
            code = set_point(data_points.arr_p, point, i);
    }
    return code;
}

code_t scan_points_data(points_data_t &old_data, FILE *f)
{
    points_data_t buf = init_points();
    unsigned int num_temp;

    code_t code = scan_points_num(num_temp, f);
    if (code) return code;

    code = alloc_points_data(buf, num_temp);
    if (code) return code;

    code = scanning_points(buf, f);
    if (code)
        delete_points_data(buf);
    else
    {
        delete_points_data(old_data);
        old_data = buf;
    }

    return code;
}

void delete_points_data(points_data_t &points)
{
    points.num_p = 0;
    delete_point_arr(points.arr_p);
}

code_t move_points_data(points_data_t &data_points, const transform_t &transf)
{
    if (!data_points.num_p) return INCORRECT_DATA;

    point_t point;
    code_t code = CORRECT_WORK;
    for (unsigned int i = 0; !code && i < data_points.num_p; i++)
    {
        code = get_point(point, data_points.arr_p, i);
        if (!code)
        {
            move_point(point, transf.center);
            code = set_point(data_points.arr_p, point, i);
        }
    }

    return code;
}

code_t rotate_points_data(points_data_t &data_points, const transform_t &transf)
{
    if (!data_points.num_p) return INCORRECT_DATA;

    point_t point;
    code_t code = CORRECT_WORK;
    for (unsigned int i = 0; !code && i < data_points.num_p; i++)
    {
        code = get_point(point, data_points.arr_p, i);
        if (!code)
        {
            rotate_point(point, transf.center, transf.rotate);
            code = set_point(data_points.arr_p, point, i);
        }
    }

    return code;
}

code_t scale_points_data(points_data_t &data_points, const transform_t &transf)
{
    if (!data_points.num_p) return INCORRECT_DATA;

    point_t point;
    code_t code = CORRECT_WORK;
    for (unsigned int i = 0; !code && i < data_points.num_p; i++)
    {
        code = get_point(point, data_points.arr_p, i);
        if (!code)
        {
            scale_point(point, transf.center, transf.scale);
            code = set_point(data_points.arr_p, point, i);
        }
    }

    return code;
}

code_t draw_points_data(const points_data_t &points, const point_t &view_point,
                        draw_params_t &param)
{
    return draw_points(points.arr_p, points.num_p, view_point, param);
}
