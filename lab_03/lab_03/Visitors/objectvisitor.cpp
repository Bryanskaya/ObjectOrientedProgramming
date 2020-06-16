#include "ObjectVisitor.h"


ObjectVisitor::ObjectVisitor() {}

ObjectVisitor::~ObjectVisitor() {}

void ObjectVisitor::set_ptr(shared_ptr<ObjectVisitor> &ptr)
{
    _self_ptr = ptr;
}
