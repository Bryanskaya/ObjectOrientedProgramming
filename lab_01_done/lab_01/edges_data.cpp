#include "edges_data.h"
#include "memory.h"

edges_data_t init_edges(void)
{
    edges_data_t edges;

    edges.num_ed = 0;
    edges.arr_ed = nullptr;

    return edges;
}

code_t scan_edges_num(unsigned int &num, FILE *f)
{
    if (!f) return EMPTY_FILE;

    unsigned int temp;
    int rc = fscanf(f, "%u", &temp);

    if (rc != 1) return INCORRECT_INPUT;

    num = temp;
    return CORRECT_WORK;
}

code_t alloc_edges_data(edges_data_t &data, unsigned int num)
{
    data.arr_ed = alloc_edges_memory(num);
    if (!data.arr_ed) return MEMORY_ERROR;

    data.num_ed = num;

    return CORRECT_WORK;
}

code_t scanning_edges(edges_data_t &data, FILE *f)
{
    if (!data.num_ed) return INCORRECT_DATA;

    edge_t edge;
    code_t code = CORRECT_WORK;
    for (unsigned int i = 0; !code && i < data.num_ed; i++)
    {
        code = scan_edge(edge, f);
        if (!code)
            code = set_edge(data.arr_ed, edge, i);
    }
    return code;
}

code_t scan_edges_data(edges_data_t &old_data, FILE *f)
{
    edges_data_t buf = init_edges();
    unsigned int num_temp;

    code_t code = scan_edges_num(num_temp, f);
    if (code) return code;

    code = alloc_edges_data(buf, num_temp);
    if (code) return code;

    code = scanning_edges(buf, f);
    if (code)
        delete_edges_data(buf);
    else
    {
        delete_edges_data(old_data);
        old_data = buf;
    }

    return code;
}

void delete_edges_data(edges_data_t &edges)
{
    edges.num_ed = 0;
    delete_edge_arr(edges.arr_ed);
}

code_t draw_edges_data(const edges_data_t &edges, const points_data_t &points,
                       const point_t &view_point, draw_params_t &param)
{
    return draw_edges(edges.arr_ed, edges.num_ed, points.arr_p,
                      view_point, param);
}
