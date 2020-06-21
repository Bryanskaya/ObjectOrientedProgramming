#include "edge.h"

edge_t create_edge(unsigned int point_1, unsigned int point_2)
{
    edge_t edge;
    edge.point_1 = point_1;
    edge.point_2 = point_2;
    return edge;
}

code_t scan_edge(edge_t &edge, FILE *f)
{
    unsigned int point_1, point_2;

    int rc = fscanf(f, "%u%u", &point_1, &point_2);
    if (rc != 2) return INCORRECT_INPUT;

    edge = create_edge(point_1, point_2);

    return CORRECT_WORK;
}

void get_numbers_nodes(unsigned int &num_1, unsigned int &num_2,
                       const edge_t &edge)
{
    num_1 = edge.point_1;
    num_2 = edge.point_2;
}

code_t draw_edge_general(const point_t &point_1, const point_t &point_2,
                         draw_params_t &param)
{
    return draw_line(point_1.x, point_1.y, point_2.x, point_2.y, param);
}
