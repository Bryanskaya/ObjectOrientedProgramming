#include "RemoveCommand.h"

RemoveCommand::RemoveCommand(size_t index) : _index(index) {}

RemoveCommand::~RemoveCommand() {}

void RemoveCommand::execute(weak_ptr<BaseScene> scene)
{
    RemoveManager(scene, _index).execute();
}
