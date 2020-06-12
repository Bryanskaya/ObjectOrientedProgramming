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

    void add_object(const SceneObject&);
    void remove_object(const Iterator<SceneObject>&);

    Iterator<SceneObject> begin() { return _object_arr.begin(); }
    Iterator<SceneObject> end() { return _object_arr.end(); }

    ConstIterator<SceneObject> const_begin() { return _object_arr.const_begin(); }
    ConstIterator<SceneObject> const_end() { return _object_arr.const_end(); }

    ConstIterator<SceneObject> begin() const { return _object_arr.begin(); }
    ConstIterator<SceneObject> end() const { return _object_arr.end(); }

protected:
    Array<SceneObject> _object_arr;
};

#endif // COMPLEXOBJECT_H
