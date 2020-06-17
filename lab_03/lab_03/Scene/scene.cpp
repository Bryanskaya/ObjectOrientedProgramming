#include "scene.h"

Scene::Scene() {}

Scene::~Scene() {}

Iterator<shared_ptr<SceneObject>> Scene::_find_camera()
{
    Iterator<shared_ptr<SceneObject>> iter = begin();

    for (; iter; iter++)
        if ((*iter)->is_observer())
            break;

    return iter;
}

void Scene::set_camera(Iterator<shared_ptr<SceneObject>>& iter)
{
    if ((*iter)->is_observer())
        _cur_camera = iter;
}

shared_ptr<BaseCamera> Scene::get_camera()
{
    BaseCamera *ptr;

    if (_find_camera().is_end())
        ptr = nullptr;
    else
        ptr = reinterpret_cast<BaseCamera*>((*_find_camera())->clone());

    return shared_ptr<BaseCamera>(ptr);
}

void Scene::add_object(shared_ptr<SceneObject> object)
{
    _arr.append(object);
    _cur_camera = _find_camera();
}

void Scene::remove_object(Iterator<shared_ptr<SceneObject>>& iter)
{
    _arr.remove(iter);
    _cur_camera = _find_camera();
}
