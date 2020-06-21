#ifndef EDGECREATOR_H
#define EDGECREATOR_H

#include "Objects/Point/Point.h"
#include "Objects/Edge/edge.h"
#include "ObjectCreator.h"

class EdgeCreator : public ObjectCreator
{
public:
    EdgeCreator();
    virtual ~EdgeCreator();

    virtual shared_ptr<SceneObject> create()
    {
        return shared_ptr<SceneObject>(new Edge(_point1, _point2));
    }

private:
    Point _point1, _point2;
};

#endif // EDGECREATOR_H
