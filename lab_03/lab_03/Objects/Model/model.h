#ifndef MODEL_H
#define MODEL_H

#include "BaseModel.h"
#include "Visitors/ObjectVisitor.h"


class Model : public BaseModel
{
public:
    Model();
    explicit Model(const Model& other);
    virtual ~Model();

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual unique_ptr<SceneObject> clone();
};

#endif // MODEL_H
