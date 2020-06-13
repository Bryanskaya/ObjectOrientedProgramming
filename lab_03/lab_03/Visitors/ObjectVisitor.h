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
};

#endif // OBJECTVISITOR_H
