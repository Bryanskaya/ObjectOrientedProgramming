#ifndef LOADERRORS_H
#define LOADERRORS_H

#include "BaseErrors.h"

namespace error {

class OpeningFail : public BaseError
{
public:
    OpeningFail(string filename, string classname, int num_line);
    virtual ~OpeningFail();
};

class FileNotOpened : public BaseError
{
public:
    FileNotOpened(string filename, string classname, int num_line);
    virtual ~FileNotOpened();
};

class WrongNodeNum : public BaseError
{
public:
    WrongNodeNum(string filename, string classname, int num_line);
    virtual ~WrongNodeNum();
};

class WrongEdgeNum : public BaseError
{
public:
    WrongEdgeNum(string filename, string classname, int num_line);
    virtual ~WrongEdgeNum();
};

class WrongPointIndex : public BaseError
{
public:
    WrongPointIndex(string filename, string classname, int num_line);
    virtual ~WrongPointIndex();
};
}


#endif // LOADERRORS_H
