#include "ObjectVisitor.h"


ObjectVisitor::ObjectVisitor() {}

ObjectVisitor::~ObjectVisitor() {}

void ObjectVisitor::set_ptr(weak_ptr<ObjectVisitor> ptr)
{
    _self_ptr = ptr;
}
