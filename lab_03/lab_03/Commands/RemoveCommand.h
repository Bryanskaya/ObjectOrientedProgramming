#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "BaseCommand.h"

class RemoveCommand : public BaseCommand
{
public:
    RemoveCommand(size_t index);
    virtual ~RemoveCommand() = 0;

    virtual void execute(weak_ptr<BaseScene> scene);

protected:
    size_t _index;
};

#endif // REMOVECOMMAND_H
