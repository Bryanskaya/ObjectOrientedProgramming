#include "changecamera.h"

ChangeCommand::ChangeCommand(size_t index) : _index(index) {}

ChangeCommand::~ChangeCommand() {}

void ChangeCommand::execute(weak_ptr<BaseScene> scene)
{
    CameraManager(scene, _index).execute();
}
