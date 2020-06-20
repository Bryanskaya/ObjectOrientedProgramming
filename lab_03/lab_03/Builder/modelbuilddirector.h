#ifndef MODELBUILDDIRECTOR_H
#define MODELBUILDDIRECTOR_H

#include "BuildDirector.h"
#include "basemodelbuilder.h"

class ModelBuildDirector : public BuildDirector
{
public:
    ModelBuildDirector(shared_ptr<BaseModelBuilder> builder);
    virtual ~ModelBuildDirector();

    virtual shared_ptr<SceneObject> create();

private:
    shared_ptr<BaseModelBuilder> _builder;
};

#endif // MODELBUILDDIRECTOR_H
