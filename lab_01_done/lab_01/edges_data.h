#ifndef EDGES_DATA_H
#define EDGES_DATA_H

#include "global_attributes.h"
#include "edges.h"

typedef struct
{
    unsigned int num_ed;
    arr_edges_t arr_ed;
}edges_data_t;

edges_data_t init_edges(void);
code_t scan_edges_data(edges_data_t &edges_data, FILE *f);
void delete_edges_data(edges_data_t &edges);
code_t draw_edges_data(const edges_data_t &edges, const points_data_t &points, const point_t &view_point, draw_params_t &param);



#endif // EDGES_DATA_H
