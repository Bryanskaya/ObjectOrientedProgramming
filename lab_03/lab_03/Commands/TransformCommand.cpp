#include "TransformCommand.h"

TransformCommand::TransformCommand(Transformation *transf, size_t index) :
    _transf(new Transformator(transf)), _index(index) {}

TransformCommand::~TransformCommand() {}

void TransformCommand::execute(weak_ptr<BaseScene> scene)
{
    TransformManager(scene, _transf, _index).execute();
}


RotateCommand::RotateCommand(double ax, double ay, double az, size_t index) :
    TransformCommand(new Rotate(ax, ay, az), index) {}

RotateCommand::~RotateCommand() {}

MoveCommand::MoveCommand(double ax, double ay, double az, size_t index) :
    TransformCommand(new Move(ax, ay, az), index) {}

MoveCommand::~MoveCommand() {}

ScaleCommand::ScaleCommand(double ax, double ay, double az, size_t index) :
    TransformCommand(new Scale(ax, ay, az), index) {}

ScaleCommand::~ScaleCommand() {}
