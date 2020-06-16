#ifndef COMPLEXOBJECT_H
#define COMPLEXOBJECT_H

#include "SceneObject.h"
#include "Array/array.h"

class ComplexObject : public SceneObject
{
public:
    ComplexObject();
    explicit ComplexObject(const ComplexObject& other);

    virtual bool is_complex() final { return true; }
    virtual bool is_observer();
    virtual bool is_drawable();

    size_t get_size() const;

    void add_object(shared_ptr<SceneObject>);
    void remove_object(Iterator<shared_ptr<SceneObject>>&);

    Iterator<shared_ptr<SceneObject>> begin() { return _object_arr.begin(); }
    Iterator<shared_ptr<SceneObject>> end() { return _object_arr.end(); }

    ConstIterator<shared_ptr<SceneObject>> const_begin() { return _object_arr.const_begin(); }
    ConstIterator<shared_ptr<SceneObject>> const_end() { return _object_arr.const_end(); }

    ConstIterator<shared_ptr<SceneObject>> begin() const { return _object_arr.begin(); }
    ConstIterator<shared_ptr<SceneObject>> end() const { return _object_arr.end(); }

protected:
    Array<shared_ptr<SceneObject>> _object_arr;
};

#endif // COMPLEXOBJECT_H
