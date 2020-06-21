#include "BaseScene.h"

BaseScene::BaseScene() : _arr(), _cur_camera(_arr.end()) {}

BaseScene::~BaseScene() {}

size_t BaseScene::get_size()
{
    return _arr.get_size();
}

Iterator<shared_ptr<SceneObject>>BaseScene::begin()
{
    return _arr.begin();
}

Iterator<shared_ptr<SceneObject>>BaseScene::end()
{
    return _arr.end();
}

ConstIterator<shared_ptr<SceneObject>>BaseScene::begin() const
{
    return _arr.begin();
}

ConstIterator<shared_ptr<SceneObject>>BaseScene::end() const
{
    return _arr.end();
}

ConstIterator<shared_ptr<SceneObject>>BaseScene::const_begin() const
{
    return _arr.const_begin();
}

ConstIterator<shared_ptr<SceneObject>>BaseScene::const_end() const
{
    return _arr.const_end();
}
