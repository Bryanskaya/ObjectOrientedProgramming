#ifndef MEMORY_H
#define MEMORY_H

#include "points_data.h"
#include "edges_data.h"

arr_points_t alloc_points_memory(unsigned int num);
arr_edges_t alloc_edges_memory(unsigned int num);
void delete_edge_arr(arr_edges_t &arr);
void delete_point_arr(arr_points_t &arr);

#endif // MEMORY_H
