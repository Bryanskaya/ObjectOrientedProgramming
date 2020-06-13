#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <iostream>
#include <memory>


class ObjectVisitor;

using namespace std;


class SceneObject
{
public:
    explicit SceneObject() = default;
    virtual ~SceneObject() = default;

    virtual bool is_drawable() { return false; }
    virtual bool is_observer() { return false; }
    virtual bool is_complex() { return false; }

    virtual void accept(shared_ptr<ObjectVisitor>)
    {
        cout << "*";
    }

    virtual unique_ptr<SceneObject> clone()
    {
        return nullptr;
    }
};

#endif // SCENEOBJECT_H
