#ifndef SCENEOBJECTS_H
#define SCENEOBJECTS_H

#include <iostream>
#include <memory>

using namespace std;


class ObjectVisitor; //

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
        cout << '*';
    }  //

    virtual unique_ptr<SceneObject> clone()
    {
        cout << '+';
        return nullptr;
    } //
};

#endif // SCENEOBJECTS_H
