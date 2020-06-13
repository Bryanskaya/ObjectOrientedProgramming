#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include "ObjectVisitor.h"
#include "Viewver/Viewver.h"

class DrawVisitor : public ObjectVisitor
{
public:
    DrawVisitor(weak_ptr<Viewver> viewver);
    virtual ~DrawVisitor() = default;


    virtual void visit(BaseCamera& camera);
    virtual void visit(BasePoint& point);
    virtual void visit(BaseEdge& edge);
    virtual void visit(BaseModel& model);


protected:
    weak_ptr<Viewver> _viewver;
};

#endif // DRAWVISITOR_H
