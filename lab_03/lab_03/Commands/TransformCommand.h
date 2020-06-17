#ifndef TRANSFORMCOMMAND_H
#define TRANSFORMCOMMAND_H

#include "BaseCommand.h"
#include "Transformation/Transformator.h"


class TransformCommand : public BaseCommand
{
public:
    TransformCommand(Transformation* transf, size_t index);
    virtual ~TransformCommand() = 0;

    virtual void execute(weak_ptr<BaseScene> scene);

protected:
    shared_ptr<Transformator> _transf;
    size_t _index;
};


class RotateCommand : public TransformCommand
{
public:
    RotateCommand(double ax, double ay, double az, size_t index);
    virtual ~RotateCommand();
};

class MoveCommand : public TransformCommand
{
public:
    MoveCommand(double dx, double dy, double dz, size_t index);
    virtual ~MoveCommand();
};

class ScaleCommand : public TransformCommand
{
public:
    ScaleCommand(double kx, double ky, double kz, size_t index);
    virtual ~ScaleCommand();
};


#endif // TRANSFORMCOMMAND_H
