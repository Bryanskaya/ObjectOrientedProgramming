#ifndef ARRAYERRORS_H
#define ARRAYERRORS_H

#include "BaseErrors.h"

namespace error {

class WrongIndex : public BaseError
{
public:
    WrongIndex(string filename, string classname, int num_line, int index);
    virtual ~WrongIndex();
};

class WrongSize : public BaseError
{
public:
    WrongSize(string filename, string classname, int num_line, int num);
    virtual ~WrongSize();
};

class ArrayCountExpired : public BaseError
{
public:
    ArrayCountExpired(string filename, string classname, int num_line);
    virtual ~ArrayCountExpired();
};

class ArrayPtrExpired : public BaseError
{
public:
    ArrayPtrExpired(string filename, string classname, int num_line);
    virtual ~ArrayPtrExpired();
};

class AllocProblem : public BaseError
{
public:
    AllocProblem(string filename, string classname, int num_line);
    virtual ~AllocProblem();
};

class IndexOutRange : public BaseError
{
public:
    IndexOutRange(string filename, string classname, int num_line);
    virtual ~IndexOutRange();
};

}

#endif // ARRAYERRORS_H
