#include "complexobject.h"

ComplexObject::ComplexObject(): _object_arr() {}

ComplexObject::ComplexObject(const ComplexObject& other)
{
    _object_arr = other._object_arr;
}

bool ComplexObject::is_drawable()
{
    for (size_t i = 0; i < _object_arr.get_size(); i++)
        if (_object_arr[i]->is_drawable())
            return true;

    return false;
}

bool ComplexObject::is_observer()
{
    for (size_t i = 0; i < _object_arr.get_size(); i++)
        if (_object_arr[i]->is_observer())
            return true;

    return false;
}

size_t ComplexObject::get_size() const
{
    return _object_arr.get_size();
}

void ComplexObject::add_object(shared_ptr<SceneObject> other)
{
    _object_arr.append(other);
}

void ComplexObject::remove_object(Iterator<shared_ptr<SceneObject>> &iter)
{
    _object_arr.remove(iter);
}
