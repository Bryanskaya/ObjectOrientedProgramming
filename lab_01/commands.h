#ifndef COMMANDS_H
#define COMMANDS_H

#include "model.h"

typedef enum
{
    READ_FILE,
    MOVE_MODEL,
    ROTATE_MODEL,
    SCALE_MODEL,
    DRAW_MODEL,
    DELETE_MODEL,
}action_t;

typedef struct
{
    action_t action;
    const char *read_file;
    transform_t move_model;
    transform_t rotate_model;
    transform_t scale_model;
    draw_params_t param;
}command_t;

command_t create_command_readfile(const char *name);
command_t create_command_draw(draw_params_t &param);
command_t create_command_move(transform_t &move);
command_t create_command_rotate(transform_t &rotate);
command_t create_command_scale(transform_t &scale);
command_t create_command_delete();

#endif // COMMANDS_H
