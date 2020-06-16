#include "SceneManager.h"

SceneManager::SceneManager(weak_ptr<BaseScene> scene) : _scene(scene) {}

SceneManager::~SceneManager() {}


Iterator<shared_ptr<SceneObject>> SceneManager::_find_pos(size_t index)
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(),__LINE__ - 1);

    Iterator<shared_ptr<SceneObject>> iter = _scene.lock()->begin();

    for (size_t i = 0; i < index && iter; i++, iter++) {}

    if (iter.is_end())
        throw error::IndexOutRange(__FILE__, typeid (*this).name(),__LINE__ - 1);

    return iter;
}

CameraManager::CameraManager(weak_ptr<BaseScene> scene, size_t index) :
    SceneManager(scene), _ind(index) {}

CameraManager::~CameraManager() {}

void CameraManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    Iterator<shared_ptr<SceneObject>> iter = _find_pos(_ind);
    _scene.lock()->set_camera(iter);
}

TransformManager::TransformManager(weak_ptr<BaseScene> scene,
                                   weak_ptr<Transformator> transf, size_t index) :
    SceneManager(scene), _transf(transf), _ind(index) {}

TransformManager::~TransformManager() {}

void TransformManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    Iterator<shared_ptr<SceneObject>> iter = _find_pos(_ind);
    //////////////////
}



