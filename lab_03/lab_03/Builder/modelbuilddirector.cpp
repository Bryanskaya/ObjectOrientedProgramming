#include "modelbuilddirector.h"

ModelBuildDirector::ModelBuildDirector(shared_ptr<BaseModelBuilder> builder)
    : _builder(builder) {}

ModelBuildDirector::~ModelBuildDirector() {}


shared_ptr<SceneObject> ModelBuildDirector::create()
{
    _builder->load_nodes();
    _builder->load_edges();

    return _builder->get_object();
}
