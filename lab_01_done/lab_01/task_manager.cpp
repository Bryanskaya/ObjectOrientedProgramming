#include "task_manager.h"

code_t task_manager(command_t &command)
{
    static model_t model = init_model();
    static point_t view_point = init_view_point();
    code_t code;

    switch (command.action)
    {
        case LOAD_MODEL:
            code = load_model(model, command.load_model);
            break;
        case MOVE_MODEL:
            code = move_model(model, command.move_model);
            break;
        case ROTATE_MODEL:
            code = rotate_model(model, command.rotate_model);
            break;
        case SCALE_MODEL:
            code = scale_model(model, command.scale_model);
            break;
        case DRAW_MODEL:
            code = draw_model(model, view_point, command.param);
            break;
        case DELETE_MODEL:
            code = delete_model(model);
            break;
        default:
            code = INCORRECT_COMMAND;
    }

    return code;
}
