#ifndef TRANSFORMVISITOR_H
#define TRANSFORMVISITOR_H

#include "ObjectVisitor.h"
#include "Transformation/Transformator.h"
#include "Errors/VisitorErrors.h"


class TransformVisitor : public ObjectVisitor
{
public:
    TransformVisitor(weak_ptr<Transformator> transf);
    virtual ~TransformVisitor() = default;

    virtual void visit(BaseCamera& camera);
    virtual void visit(BasePoint& point);
    virtual void visit(BaseEdge& edge);
    virtual void visit(BaseModel& model);

protected:
    weak_ptr<Transformator> _transf;
};

#endif // TRANSFORMVISITOR_H
