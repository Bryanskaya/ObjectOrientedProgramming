#include "edge.h"

Edge::Edge() {}

Edge::~Edge() {}

Edge::Edge(const BasePoint& point1, const BasePoint& point2) : BaseEdge(point1, point2) {}

Edge::Edge(const Edge& other) : BaseEdge(other) {}


void Edge::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

unique_ptr<SceneObject> Edge::clone()
{
    return unique_ptr<SceneObject>(new Edge(*this));
}

