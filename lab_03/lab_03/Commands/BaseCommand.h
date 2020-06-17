#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include "Scene/BaseScene.h"
#include "Manager/SceneManager.h"


class BaseCommand
{
public:
    BaseCommand();
    virtual ~BaseCommand() = 0;

    virtual void execute(weak_ptr<BaseScene> scene) = 0;
};



#endif // BASECOMMAND_H
