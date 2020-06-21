#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "BaseCommand.h"
#include "Creator/CameraCreator.h"


class AddCommand : public BaseCommand
{
public:
    AddCommand();
    virtual ~AddCommand() = 0;

    virtual void execute(weak_ptr<BaseScene> scene);

protected:
    shared_ptr<ObjectCreator> _creator;
};


class AddCamera : public AddCommand
{
public:
    AddCamera(double x, double y, double z);
    virtual ~AddCamera();
};

#endif // ADDCOMMAND_H
