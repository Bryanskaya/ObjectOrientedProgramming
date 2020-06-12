#ifndef EDGE_H
#define EDGE_H

#include "BaseEdge.h"


class Edge : public BaseEdge
{
public:
    Edge();
    Edge(const BasePoint& point1, const BasePoint& point2);
    explicit Edge(const Edge& other);
    virtual ~Edge() = default; //

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual unique_ptr<SceneObject> clone();
};

#endif // EDGE_H
