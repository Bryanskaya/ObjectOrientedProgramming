#include "drawvisitor.h"

DrawVisitor::DrawVisitor(weak_ptr<Viewver> viewver) : _viewver(viewver) {}


void DrawVisitor::visit(BasePoint &point)
{
    if (_viewver.expired())
        throw error::ViewverExpired(__FILE__, typeid (*this).name(),__LINE__ - 1);

    _viewver.lock()->draw_point(point);
}

void DrawVisitor::visit(BaseCamera&) {}

void DrawVisitor::visit(BaseEdge &edge)
{
    if (_viewver.expired())
        throw error::ViewverExpired(__FILE__, typeid (*this).name(),__LINE__ - 1);

    _viewver.lock()->draw_line(edge.get_point1(), edge.get_point2());
}

void DrawVisitor::visit(BaseModel &model)
{
    if (_viewver.expired())
        throw error::ViewverExpired(__FILE__, typeid (*this).name(),__LINE__ - 1);

    for (auto obj : model)
        obj->accept(_self_ptr.lock());
}
