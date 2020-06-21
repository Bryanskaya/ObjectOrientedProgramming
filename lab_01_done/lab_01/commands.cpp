#include "commands.h"

command_t create_command_loadmodel(const char* name)
{
    command_t command;
    command.action = LOAD_MODEL;
    command.load_model = name;
    return command;
}

command_t create_command_draw(draw_params_t &param)
{
    command_t command;
    command.action = DRAW_MODEL;
    command.param = param;
    return command;
}

command_t create_command_move(transform_t &move)
{
    command_t command;
    command.action = MOVE_MODEL;
    command.move_model = move;
    return command;
}

command_t create_command_rotate(transform_t &rotate)
{
    command_t command;
    command.action = ROTATE_MODEL;
    command.rotate_model = rotate;
    return command;
}

command_t create_command_scale(transform_t &scale)
{
    command_t command;
    command.action = SCALE_MODEL;
    command.scale_model = scale;
    return command;
}

command_t create_command_delete()
{
    command_t command;
    command.action = DELETE_MODEL;
    return command;
}
