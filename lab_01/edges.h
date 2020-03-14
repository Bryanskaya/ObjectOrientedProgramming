#ifndef EDGES_H
#define EDGES_H

#include "global_attributes.h"
#include "edge.h"

typedef edge_t* arr_edges_t;

code_t alloc_edges(arr_edges_t &arr, unsigned int num);
code_t scan_edge_arr(arr_edges_t &arr, unsigned int &num, FILE *f);
void delete_edge_arr(arr_edges_t &arr);
code_t draw_edges(const arr_edges_t &arr_ed, unsigned int num, const arr_points_t &arr_p, const point_t &view_point, draw_params_t &param);


code_t set_edge(arr_edges_t &arr, edge_t &edge, unsigned int i);
code_t get_edge(edge_t &edge, arr_edges_t &arr, unsigned int i);


#endif // EDGES_H
