#include "addcommand.h"

AddCommand::AddCommand() {}

AddCommand::~AddCommand() {}

void AddCommand::execute(weak_ptr<BaseScene> scene)
{
    AddManager(scene, _creator).execute();
}


AddCamera::AddCamera(double x, double y, double z)
{
    _creator = shared_ptr<ObjectCreator>(new CameraCreator(x, y, z));
}

AddCamera::~AddCamera() {}
