#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <string>
#include <time.h>

using namespace std;
namespace  error{

class BaseError : public exception
{
public:
    BaseError(string filename, string classname, int num_line, string msg);
    virtual ~BaseError() override;

    virtual const char* what() const noexcept override;
protected:
    string errormsg;
};
}

/*

class ErrorMemory : public BaseError
{
public:
    ErrorMemory(string filename, string classname, int num_line);
    virtual ~ErrorMemory();
};

class ErrorEmptyVector : public BaseError
{
public:
    ErrorEmptyVector(string filename, string classname, int num_line);
    virtual ~ErrorEmptyVector();
};

class ErrorCountExpired : public BaseError
{
public:
    ErrorCountExpired(string filename, string classname, int num_line);
    virtual ~ErrorCountExpired();
};

class ErrorDivZero : public BaseError
{
public:
    ErrorDivZero(string filename, string classname, int num_line);
    virtual ~ErrorDivZero();
};

class ErrorDiffSize : public BaseError
{
public:
    ErrorDiffSize(string filename, string classname, int num_line,
                  size_t size1, size_t size2);
    virtual ~ErrorDiffSize();
};

class ErrorNotAllowedSize : public BaseError
{
public:
    ErrorNotAllowedSize(string filename, string classname, int num_line,
                  size_t size1, size_t size2);
    virtual ~ErrorNotAllowedSize();
};

class ErrorInvalidOperation : public BaseError
{
public:
    ErrorInvalidOperation(string filename, string classname, int num_line);
    virtual ~ErrorInvalidOperation();
};
*/

#endif // ERRORS_H
