#ifndef DRAW_INTERFACE_H
#define DRAW_INTERFACE_H

#include <QGraphicsScene>
#include "global_attributes.h"

#define COLOR_NODE      Qt::red
#define COLOR_EDGE      Qt::black
#define POINT_R         7

typedef struct
{
    QGraphicsScene *scene;

    QBrush brush;
    QPen pen;

    int point_r;

    QPen pen_axis;
}draw_params_t;

draw_params_t init_draw(QGraphicsScene *scene);
code_t clean_scene(draw_params_t &param);
code_t draw_dash_line(draw_params_t &param, double x_1, double y_1, double x_2, double y_2);
code_t draw_point(double x, double y, draw_params_t &param);
code_t draw_line(double x_1, double y_1, double x_2, double y_2, draw_params_t &param);

#endif // DRAW_INTERFACE_H
