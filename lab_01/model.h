#ifndef MODEL_H
#define MODEL_H

#include "points.h"
#include "edges.h"
#include "points_data.h"
#include "edges_data.h"
#include "global_attributes.h"
#include "transform.h"

typedef struct
{
    points_data_t points;
    edges_data_t edges;
}model_t;

model_t init_model(void);
code_t read_file(model_t &model, const char* filename);
code_t move_model(model_t &model, const transform_t &transf);
code_t rotate_model(model_t &model, const transform_t &transf);
code_t scale_model(model_t &model, const transform_t &transf);
code_t draw_model(const model_t &model, const point_t &view_point, draw_params_t &param);
code_t delete_model(model_t &model);


#endif // MODEL_H
