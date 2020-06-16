#ifndef OBJECTVISITOR_H
#define OBJECTVISITOR_H

#include "Objects/Camera/BaseCamera.h"
#include "Objects/Point/basepoint.h"
#include "Objects/Edge/BaseEdge.h"
#include "Objects/Model/BaseModel.h"

class ObjectVisitor
{
public:
    ObjectVisitor();
    virtual ~ObjectVisitor() = 0;

    virtual void visit(BaseCamera& camera) = 0;
    virtual void visit(BasePoint& point) = 0;
    virtual void visit(BaseEdge& edge) = 0;
    virtual void visit(BaseModel& model) = 0;

    void set_ptr(shared_ptr<ObjectVisitor>&);

protected:
    shared_ptr<ObjectVisitor> _self_ptr;
};

#endif // OBJECTVISITOR_H
