#include "transformvisitor.h"

TransformVisitor::TransformVisitor(weak_ptr<Transformator> transf) : _transf(transf) {}


void TransformVisitor::visit(BasePoint &point)
{
    if (_transf.expired())
        throw error::TransformExpired(__FILE__, typeid (*this).name(),__LINE__ - 1);

    _transf.lock()->transform(point.get_x(), point.get_y(), point.get_z());
}

void TransformVisitor::visit(BaseCamera &camera)
{
    if (_transf.expired())
        throw error::TransformExpired(__FILE__, typeid (*this).name(),__LINE__ - 1);

    _transf.lock()->transform(camera.get_x(), camera.get_y(), camera.get_z());
}

void TransformVisitor::visit(BaseEdge &edge)
{
    if (_transf.expired())
        throw error::TransformExpired(__FILE__, typeid (*this).name(),__LINE__ - 1);

    BasePoint& point1 = edge.get_point1();
    BasePoint& point2 = edge.get_point2();

    _transf.lock()->transform(point1.get_x(), point1.get_y(), point1.get_z());
    _transf.lock()->transform(point2.get_x(), point2.get_y(), point2.get_z());
}

void TransformVisitor::visit(BaseModel &model)
{
    if (_transf.expired())
        throw error::TransformExpired(__FILE__, typeid (*this).name(),__LINE__ - 1);

    for (auto obj : model)
        obj->accept(_self_ptr.lock());
}
