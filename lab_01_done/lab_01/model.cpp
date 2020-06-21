#include "model.h"

model_t init_model(void)
{
    model_t model;

    model.points = init_points();
    model.edges = init_edges();

    return model;
}

code_t delete_model(model_t &model)
{
    delete_points_data(model.points);
    delete_edges_data(model.edges);
    return CORRECT_WORK;
}

code_t load_model(model_t &model, const char* filename)
{
    FILE *f = fopen(filename, "r");
    if (!f) return OPEN_FILE_ERROR;

    model_t model_new = init_model();
    code_t code = scan_points_data(model_new.points, f);
    if (!code)
    {
        code = scan_edges_data(model_new.edges, f);
        if (code)
            delete_points_data(model_new.points);
    }

    fclose(f);

    if (!code)
    {
        delete_model(model);
        model = model_new;
    }

    return code;
}

code_t move_model(model_t &model, const transform_t &transf)
{
    return move_points_data(model.points, transf);
}

code_t rotate_model(model_t &model, const transform_t &transf)
{
    return rotate_points_data(model.points, transf);
}

code_t scale_model(model_t &model, const transform_t &transf)
{
    return scale_points_data(model.points, transf);
}

code_t draw_model_edges(const model_t &model, const point_t &view_point,
                        draw_params_t &param)
{
    return draw_edges_data(model.edges, model.points, view_point, param);
}

code_t draw_model(const model_t &model, const point_t &view_point, draw_params_t &param)
{
    code_t code = clean_scene(param);
    if (!code)
        code = draw_axis(param, view_point);
    if (!code)
        code = draw_model_edges(model, view_point, param);
    if (!code)
        code = draw_points_data(model.points, view_point, param);

    return code;
}
