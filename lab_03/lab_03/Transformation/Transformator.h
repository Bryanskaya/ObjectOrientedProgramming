#ifndef TRANSFORMATOR_H
#define TRANSFORMATOR_H

#include "Transformation.h"


class Transformator
{
public:
    Transformator(Transformation* transform) : _transform(transform) {}
    ~Transformator() {}

    void transform(double& x, double& y, double& z)
    {
        _transform->execute(x, y, z);
    }

protected:
    unique_ptr<Transformation> _transform;

};

#endif // TRANSFORMATOR_H
