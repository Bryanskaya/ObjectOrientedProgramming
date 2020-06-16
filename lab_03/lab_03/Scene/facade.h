#ifndef FACADE_H
#define FACADE_H

#include "BaseScene.h"
#include "Commands/BaseCommand.h"

class Facade
{
public:
    Facade(BaseScene* scene) : _scene(scene) {}
    ~Facade() = default;

    void execute(BaseCommand& command)
    {
        command.execute(weak_ptr<BaseScene>(_scene));
    }

private:
    shared_ptr<BaseScene> _scene;
};

#endif // FACADE_H
