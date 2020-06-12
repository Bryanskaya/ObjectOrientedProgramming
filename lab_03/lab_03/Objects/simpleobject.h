#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H

#include "SceneObject.h"

class SimpleObject : public SceneObject
{
public:
    SimpleObject() = default;
    virtual ~SimpleObject() = default;

    virtual bool is_complex() final { return false; }
};

class InvisibleObject : public SimpleObject
{
public:
    InvisibleObject() = default;
    virtual ~InvisibleObject() = default;

    virtual bool is_drawable() { return false; } // final
};

class VisibleObject : public SimpleObject
{
public:
    VisibleObject() = default;
    virtual ~VisibleObject() = default;

    virtual bool is_drawable() { return true; } // final
};

#endif // SIMPLEOBJECT_H
