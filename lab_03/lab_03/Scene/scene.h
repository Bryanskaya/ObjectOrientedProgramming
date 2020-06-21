#ifndef SCENE_H
#define SCENE_H

#include "BaseScene.h"

#include "Objects/Camera/Camera.h"

class Scene: public BaseScene
{
public:
    Scene();
    virtual ~Scene();

    virtual void set_camera(Iterator<shared_ptr<SceneObject>>& iter);
    virtual shared_ptr<BaseCamera> get_camera();

    virtual void add_object(shared_ptr<SceneObject> object);
    virtual void remove_object(Iterator<shared_ptr<SceneObject>>& iter);

private:
    Iterator<shared_ptr<SceneObject>> _find_camera();
};

#endif // SCENE_H
