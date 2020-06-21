#include "SceneObject.h"

SceneObject::SceneObject() {}

SceneObject::~SceneObject() {}

void SceneObject::accept(shared_ptr<ObjectVisitor>) {}

SceneObject *SceneObject::clone()
{
    return nullptr;
}
