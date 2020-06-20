#ifndef CHANGECAMERA_H
#define CHANGECAMERA_H

#include "BaseCommand.h"

class ChangeCommand : public BaseCommand
{
public:
    ChangeCommand(size_t index);
    virtual ~ChangeCommand();

    virtual void execute(weak_ptr<BaseScene> scene);

protected:
    size_t _index;
};

#endif // CHANGECAMERA_H
