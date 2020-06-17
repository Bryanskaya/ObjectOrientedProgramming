#ifndef LOADCOMMAND_H
#define LOADCOMMAND_H

#include "BaseCommand.h"
#include "Builder/BuildDirector.h"
#include "Builder/BuilderTxtFile.h"
#include "Builder/modelbuilddirector.h"


class LoadCommand : public BaseCommand
{
public:
    LoadCommand();
    virtual ~LoadCommand() = 0;

    virtual void execute(weak_ptr<BaseScene> scene);

protected:
    shared_ptr<BuildDirector> _director;
};


class LoadModel : public LoadCommand
{
public:
    LoadModel(string filename);
    virtual ~LoadModel();
};

#endif // LOADCOMMAND_H
