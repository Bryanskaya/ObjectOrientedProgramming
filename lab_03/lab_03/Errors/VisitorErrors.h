#ifndef VISITOTERRORS_H
#define VISITOTERRORS_H

#include "BaseErrors.h"

namespace error {

class ViewverExpired : public BaseError
{
public:
    ViewverExpired(string filename, string classname, int num_line);
    virtual ~ViewverExpired();
};

class TransformExpired : public BaseError
{
public:
    TransformExpired(string filename, string classname, int num_line);
    virtual ~TransformExpired();
};

}

#endif // VISITOTERRORS_H
