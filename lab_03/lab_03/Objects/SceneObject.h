#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <iostream>
#include <memory>


class ObjectVisitor;

using namespace std;


class SceneObject
{
public:
    SceneObject();
    virtual ~SceneObject() = 0;

    virtual bool is_drawable() { return false; }
    virtual bool is_observer() { return false; }
    virtual bool is_complex() { return false; }

    virtual void accept(shared_ptr<ObjectVisitor>);

    virtual SceneObject* clone();
};

#endif // SCENEOBJECT_H
