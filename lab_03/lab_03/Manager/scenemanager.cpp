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
    shared_ptr<ObjectVisitor> visitor(new TransformVisitor(_transf));

    visitor->set_ptr(visitor);
    (*iter)->accept(visitor);
}


DrawManager::DrawManager(weak_ptr<BaseScene> scene,
                         weak_ptr<BaseDrawerFactory> draw) :
    SceneManager(scene), _draw(draw) {}

DrawManager::~DrawManager() {}

void DrawManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (_draw.expired())
        throw error::DrawExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    cout << "DrawManager1" << endl;

    shared_ptr<Viewver> viewver(new Viewver());
    viewver->set_camera(_scene.lock()->get_camera());
    viewver->set_drawer(*_draw.lock());

    shared_ptr<ObjectVisitor> visitor(new DrawVisitor(viewver));

    visitor->set_ptr(visitor);    
    viewver->clear();

    for (auto object : *_scene.lock())
        object->accept(visitor);

    cout << "DrawManager4" << endl;

}


LoadManager::LoadManager(weak_ptr<BaseScene> scene,
                         weak_ptr<BuildDirector> dir) :
    SceneManager(scene), _director(dir) {}

LoadManager::~LoadManager() {}

void LoadManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (_director.expired())
        throw error::DirectorExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    _scene.lock()->add_object(_director.lock()->create());
}


AddManager::AddManager(weak_ptr<BaseScene> scene,
                       weak_ptr<ObjectCreator> creator) :
    SceneManager(scene), _creator(creator) {}

AddManager::~AddManager() {}

void AddManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    if (_creator.expired())
        throw error::CreatorExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    _scene.lock()->add_object(_creator.lock()->create());
}

RemoveManager::RemoveManager(weak_ptr<BaseScene> scene, size_t ind) :
    SceneManager(scene), _index(ind) {}

RemoveManager::~RemoveManager() {}

void RemoveManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    Iterator<shared_ptr<SceneObject>> iter = _find_pos(_index);
    _scene.lock()->remove_object(iter);
}
