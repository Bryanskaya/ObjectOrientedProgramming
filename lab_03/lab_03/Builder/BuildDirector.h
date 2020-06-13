#ifndef BUILDDIRECTOR_H
#define BUILDDIRECTOR_H

#include <memory>

#include "Objects/SceneObject.h"

using namespace std;

class BuildDirector
{
public:
    BuildDirector() = default;
    virtual ~BuildDirector() = default;

    virtual shared_ptr<SceneObject> create();
};

#endif // BUILDDIRECTOR_H
