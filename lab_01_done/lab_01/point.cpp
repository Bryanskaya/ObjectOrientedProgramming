#include "point.h"
#include "transform.h"

point_t create_point(double x, double y, double z)
{
    point_t point;
    point.x = x;
    point.y = y;
    point.z = z;
    return point;
}

point_t init_view_point(void)
{
    point_t point;
    point.x = DX;
    point.y = DY;
    point.z = DZ;
    return point;
}

code_t scan_point(point_t &point, FILE *f)
{
    double x, y, z;

    int rc = fscanf(f, "%lf%lf%lf", &x, &y, &z);
    if (rc != 3) return INCORRECT_INPUT;

    point = create_point(x, y, z);

    return CORRECT_WORK;
}

void move_x(point_t &point, double x)
{
    point.x += x;
}

void move_y(point_t &point, double y)
{
    point.y += y;
}

void move_z(point_t &point, double z)
{
    point.z += z;
}

void move_point(point_t &point, const point_t &center)
{
    move_x(point, center.x);
    move_y(point, center.y);
    move_z(point, center.z);
}

void rotate_point_x(point_t &point, const point_t &center, const rotate_t &rotate)
{
    double ax = to_radians(rotate.ax);
    double y, z;

    y = center.y + (point.y - center.y) * cos(ax) +
                   (center.z - point.z) * sin(ax);
    z = center.z + (point.z - center.z) * cos(ax) +
                   (point.y - center.y) * sin(ax);
    point.y = y;
    point.z = z;
}

void rotate_point_y(point_t &point, const point_t &center, const rotate_t &rotate)
{
    double ay = to_radians(rotate.ay);
    double x, z;

    x = center.x + (point.x - center.x) * cos(ay) +
                   (point.z - center.z) * sin(ay);
    z = center.z + (point.z - center.z) * cos(ay) +
                   (center.x - point.x) * sin(ay);
    point.x = x;
    point.z = z;
}

void rotate_point_z(point_t &point, const point_t &center, const rotate_t &rotate)
{
    double az = to_radians(rotate.az);
    double x, y;

    x = center.x + (point.x - center.x) * cos(az) +
                   (point.y - center.y) * sin(az);
    y = center.y + (point.y - center.y) * cos(az) +
                   (center.x - point.x) * sin(az);
    point.x = x;
    point.y = y;
}

void rotate_point(point_t &point, const point_t &center, const rotate_t &rotate)
{
    rotate_point_x(point, center, rotate);
    rotate_point_y(point, center, rotate);
    rotate_point_z(point, center, rotate);
}

void scale_point_x(point_t &point, const point_t &center, const scale_t &scale)
{
    point.x = scale.kx * (point.x - center.x) + center.x;
}

void scale_point_y(point_t &point, const point_t &center, const scale_t &scale)
{
    point.y = scale.ky * (point.y - center.y) + center.y;
}

void scale_point_z(point_t &point, const point_t &center, const scale_t &scale)
{
    point.z = scale.kz * (point.z - center.z) + center.z;
}

void scale_point(point_t &point, const point_t &center, const scale_t &scale)
{
    scale_point_x(point, center, scale);
    scale_point_y(point, center, scale);
    scale_point_z(point, center, scale);
}

void projection_point(point_t &point, const point_t &view_point)
{
    double k;
    double z0 = 0;

    if (fabs(view_point.z - point.z) < EPS)
        k = TRANSF_CONST;
    else
        k = view_point.z / (view_point.z - point.z);

    point.x = view_point.x + k * (point.x - view_point.x);
    point.y = -(view_point.y + k * (point.y - view_point.y));
    point.z = z0;
}

code_t draw_axis_line(draw_params_t &param, const point_t &point_1,
                                            const point_t &point_2)
{
    return draw_dash_line(param, point_1.x, point_1.y, point_2.x, point_2.y);
}

code_t draw_axis(draw_params_t &param, const point_t &view_point)
{
    point_t point_1, point_2;
    code_t code;

    point_1 = create_point(0, 0, 0);
    projection_point(point_1, view_point);

    point_2 = create_point(MAX_XYZ, 0, 0);
    projection_point(point_2, view_point);
    code = draw_axis_line(param, point_1, point_2);

    point_2 = create_point(0, MAX_XYZ, 0);
    projection_point(point_2, view_point);
    code = draw_axis_line(param, point_1, point_2);

    point_2 = create_point(0, 0, MAX_XYZ);
    projection_point(point_2, view_point);
    code = draw_axis_line(param, point_1, point_2);

    return code;
}

code_t draw_point_general(const point_t &point, draw_params_t &param)
{
    return draw_point(point.x, point.y, param);
}
