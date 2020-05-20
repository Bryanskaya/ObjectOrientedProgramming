#include "memory.h"

arr_points_t alloc_points_memory(unsigned int num)
{
    arr_points_t arr;
    arr = static_cast<arr_points_t>(malloc(sizeof(point_t) * num));
    return arr;
}

arr_edges_t alloc_edges_memory(unsigned int num)
{
    arr_edges_t arr;
    arr = static_cast<arr_edges_t>(malloc(sizeof(edge_t) * num));
    return arr;
}

void delete_point_arr(arr_points_t &arr)
{
    free(arr);
    arr = nullptr;
}

void delete_edge_arr(arr_edges_t &arr)
{
    free(arr);
    arr = nullptr;
}
