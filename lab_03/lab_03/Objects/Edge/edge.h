#ifndef EDGE_H
#define EDGE_H

#include "BaseEdge.h"
#include "Visitors/ObjectVisitor.h"
#include "Objects/Point/Point.h"


class Edge : public BaseEdge
{
public:
    Edge();
    Edge(const BasePoint& point1, const BasePoint& point2);
    explicit Edge(const Edge& other);
    virtual ~Edge();

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual SceneObject* clone();
};

#endif // EDGE_H
