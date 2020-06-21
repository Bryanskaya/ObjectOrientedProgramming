#include "basemodelbuilder.h"

BaseModelBuilder::BaseModelBuilder() : _model(new Model()) {}

BaseModelBuilder::~BaseModelBuilder() {}


shared_ptr<SceneObject> BaseModelBuilder::get_object()
{
    return _model;
}
