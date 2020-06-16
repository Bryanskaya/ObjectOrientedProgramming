#include "model.h"

Model::Model() {}

Model::~Model() {}


Model::Model(const Model& other) : BaseModel(other) {}

void Model::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

SceneObject *Model::clone()
{
    return new Model(*this);
}
