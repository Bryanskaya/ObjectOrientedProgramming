#include "loadcommand.h"

LoadCommand::LoadCommand() {}

LoadCommand::~LoadCommand() {}

void LoadCommand::execute(weak_ptr<BaseScene> scene)
{
    LoadManager(scene, _director).execute();
}


LoadModel::LoadModel(string filename)
{
    shared_ptr<BaseModelBuilder> builder(new BuilderTxtFile(filename));
    _director = shared_ptr<BuildDirector>(new ModelBuildDirector(builder));
}

LoadModel::~LoadModel() {}

