#include "edges.h"

code_t alloc_edges(arr_edges_t &arr, unsigned int num)
{
    arr = static_cast<arr_edges_t>(malloc(sizeof(edge_t) * num));
    if (!arr) return MEMORY_ERROR;

    return CORRECT_WORK;
}

code_t scan_edge_arr(arr_edges_t &arr, unsigned int &num, FILE *f)
{
    if (!arr) return INCORRECT_DATA;

    code_t code = CORRECT_WORK;
    for (unsigned int i = 0; !code && i < num; i++)
        code = scan_edge(arr[i], f);
    return code;
}

void delete_edge_arr(arr_edges_t &arr)
{
    free(arr);
    arr = nullptr;
}

code_t draw_edges(const arr_edges_t &arr_ed, unsigned int num,
                  const arr_points_t &arr_p, const point_t &view_point,
                  draw_params_t &param)
{
    if (!arr_ed) return INCORRECT_DATA;

    code_t code = CORRECT_WORK;
    unsigned int num_1, num_2;

    point_t point_1, point_2;
    for (unsigned int i = 0; i < num; i++)
    {
        get_numbers_nodes(num_1, num_2, arr_ed[i]);
        point_1 = arr_p[num_1];
        point_2 = arr_p[num_2];
        projection_point(point_1, view_point);
        projection_point(point_2, view_point);
        draw_edge_general(point_1, point_2, param);
    }

    return code;
}

code_t set_edge(arr_edges_t &arr, edge_t &edge, unsigned int i)
{
    if (!arr) return INCORRECT_DATA;
    arr[i] = edge;
    return CORRECT_WORK;
}

code_t get_edge(edge_t &edge, arr_edges_t &arr, unsigned int i)
{
    if (!arr) return INCORRECT_DATA;
    edge = arr[i];
    return CORRECT_WORK;
}
