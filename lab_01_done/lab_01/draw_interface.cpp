#include "draw_interface.h"

draw_params_t init_draw(QGraphicsScene *scene)
{
    draw_params_t draw_param;
    draw_param.scene = scene;
    draw_param.pen = QPen(COLOR_EDGE);
    draw_param.brush = QBrush(COLOR_NODE);
    draw_param.point_r = POINT_R;
    draw_param.pen_axis = QPen(COLOR_EDGE);
    draw_param.pen_axis.setStyle(Qt::DashLine);

    return draw_param;
}

code_t clean_scene(draw_params_t &param)
{
    code_t code = CORRECT_WORK;

    if (param.scene)
        param.scene->clear();
    else
        code = INCORRECT_DATA;
    return code;
}

code_t draw_dash_line(draw_params_t &param, double x_1, double y_1,
                                            double x_2, double y_2)
{
    if (!param.scene) return INCORRECT_DATA;

    param.scene->addLine(x_1, y_1, x_2, y_2, param.pen_axis);
    return CORRECT_WORK;
}

code_t draw_point(double x, double y, draw_params_t &param)
{
    if (!param.scene) return INCORRECT_DATA;

    param.scene->addEllipse(x - 3, y - 3, param.point_r, param.point_r,
                            param.pen, param.brush);
    return CORRECT_WORK;
}

code_t draw_line(double x_1, double y_1,
                 double x_2, double y_2, draw_params_t &param)
{
    if (!param.scene) return INCORRECT_DATA;

    param.scene->addLine(x_1, y_1, x_2, y_2, param.pen);
    return CORRECT_WORK;
}
