#include "modelbuilddirector.h"

ModelBuildDirector::ModelBuildDirector(shared_ptr<BaseModelBuilder> builder)
    : _builder(builder) {}

ModelBuildDirector::~ModelBuildDirector() {}


shared_ptr<SceneObject> ModelBuildDirector::create()
{
    _builder->open();
    _builder->load_nodes();
    _builder->load_edges();
    _builder->close();

    return _builder->get_object();
}
