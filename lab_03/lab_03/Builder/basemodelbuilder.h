#ifndef BASEMODELBUILDER_H
#define BASEMODELBUILDER_H

#include "builder.h"
#include "Objects/Model/model.h"

class BaseModelBuilder : public Builder
{
public:
    BaseModelBuilder();
    virtual ~BaseModelBuilder() = 0;

    virtual void load_nodes() = 0;
    virtual void load_edges() = 0;

    virtual shared_ptr<SceneObject> get_object();

protected:
    shared_ptr<Model> _model;
};

#endif // BASEMODELBUILDER_H
