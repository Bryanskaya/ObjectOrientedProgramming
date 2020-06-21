#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "Objects/complexobject.h"

class BaseModel : public ComplexObject
{
public:
    BaseModel();
    explicit BaseModel(const BaseModel& other);
    virtual ~BaseModel();

    virtual bool is_observer() final { return false; }
    virtual bool is_drawable() final { return true; }
};

#endif // BASEMODEL_H
