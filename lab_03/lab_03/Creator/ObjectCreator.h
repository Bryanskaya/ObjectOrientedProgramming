#ifndef OBJECTCREATOR_H
#define OBJECTCREATOR_H

#include "Objects/SceneObject.h"



class ObjectCreator
{
public:
    ObjectCreator();
    virtual ~ObjectCreator() = default;

    virtual unique_ptr<SceneObject> create() = 0;
};

#endif // OBJECTCREATOR_H
