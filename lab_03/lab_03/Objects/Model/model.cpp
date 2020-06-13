#include "model.h"

Model::Model() {}

Model::~Model() {}


Model::Model(const Model& other) : BaseModel(other) {}

void Model::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

unique_ptr<SceneObject> Model::clone()
{
    return unique_ptr<SceneObject>(new Model(*this));
}
