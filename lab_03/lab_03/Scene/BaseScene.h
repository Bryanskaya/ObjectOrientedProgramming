#ifndef BASESCENE_H
#define BASESCENE_H

#include "Array/array.h"
#include "Objects/Camera/BaseCamera.h"


class BaseScene
{
public:
    BaseScene();
    virtual ~BaseScene() = 0;

    Iterator<shared_ptr<SceneObject>> begin();
    Iterator<shared_ptr<SceneObject>> end();

    ConstIterator<shared_ptr<SceneObject>> begin() const;
    ConstIterator<shared_ptr<SceneObject>> end() const;

    ConstIterator<shared_ptr<SceneObject>> const_begin() const;
    ConstIterator<shared_ptr<SceneObject>> const_end() const;

    size_t get_size();

    virtual void set_camera(Iterator<shared_ptr<SceneObject>>& iter) = 0;
    virtual shared_ptr<BaseCamera> get_camera() = 0;

    virtual void add_object(shared_ptr<SceneObject> object) = 0;
    virtual void remove_object(Iterator<shared_ptr<SceneObject>>& iter) = 0;


protected:
    Array<shared_ptr<SceneObject>> _arr;
    Iterator<shared_ptr<SceneObject>> _cur_camera;
};

#endif // BASESCENE_H
