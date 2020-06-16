#ifndef BUILDDIRECTOR_H
#define BUILDDIRECTOR_H

#include <memory>

#include "Objects/SceneObject.h"

using namespace std;

class BuildDirector
{
public:
    BuildDirector();
    virtual ~BuildDirector() = 0;

    virtual shared_ptr<SceneObject> create() = 0;
};

#endif // BUILDDIRECTOR_H
