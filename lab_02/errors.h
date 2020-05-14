#ifndef MY_ERRORS_H
#define MY_ERRORS_H

#include <exception>
#include <string>
#include <time.h>

using namespace std;

class VectorError : public exception
{
public:
    VectorError(string filename, string classname, int num_line, string msg);
    virtual ~VectorError() override;

    virtual const char* what() const noexcept override;
protected:
    string errormsg;
};

class ErrorIndex : public VectorError
{
public:
    ErrorIndex(string filename, string classname, int num_line, int index);
    virtual ~ErrorIndex();
};

class ErrorMemory : public VectorError
{
public:
    ErrorMemory(string filename, string classname, int num_line);
    virtual ~ErrorMemory();
};

class ErrorSize : public VectorError
{
public:
    ErrorSize(string filename, string classname, int num_line, int num);
    virtual ~ErrorSize();
};

class ErrorEmpty : public VectorError
{
public:
    ErrorEmpty(string filename, string classname, int num_line);
    virtual ~ErrorEmpty();
};

class ErrorNotExist : public VectorError
{
public:
    ErrorNotExist(string filename, string classname, int num_line);
    virtual ~ErrorNotExist();
};

class ErrorDivZero : public VectorError
{
public:
    ErrorDivZero(string filename, string classname, int num_line);
    virtual ~ErrorDivZero();
};

class ErrorDiffSize : public VectorError
{
public:
    ErrorDiffSize(string filename, string classname, int num_line,
                  size_t size1, size_t size2);
    virtual ~ErrorDiffSize();
};

class ErrorNotAllowedSize : public VectorError
{
public:
    ErrorNotAllowedSize(string filename, string classname, int num_line,
                  size_t size1, size_t size2);
    virtual ~ErrorNotAllowedSize();
};



#endif // MY_ERRORS_H
