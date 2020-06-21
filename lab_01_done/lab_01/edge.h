#ifndef EDGE_H
#define EDGE_H

#include "global_attributes.h"
#include "draw_interface.h"
#include "operations.h"
#include "points_data.h"

typedef struct
{
    unsigned int point_1;
    unsigned int point_2;
}edge_t;

edge_t create_edge(unsigned int point_1, unsigned int point_2);
code_t scan_edge(edge_t &edge, FILE *f);

void get_numbers_nodes(unsigned int &num_1, unsigned int &num_2, const edge_t &edge);
code_t draw_edge_general(const point_t &point_1, const point_t &point_2, draw_params_t &param);


#endif // EDGE_H
