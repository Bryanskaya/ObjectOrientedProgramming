#ifndef MY_ERRORS_H
#define MY_ERRORS_H

#include <exception>
#include <string>

using namespace std;

class BaseError : public exception
{
protected:
    string errormsg;
public:
    BaseError(string filename, string classname, int num_line,
                   const char *time, string msg = "Error")
    {
        errormsg = "\nFile name: " + filename +
                   "\nClass:     " + classname +
                   "\nIn line:   " + to_string(num_line) +
                   "\nTime:      " + time +
                   msg;
    }

    virtual const char* what() const noexcept override;
};
const char* BaseError::what() const noexcept
{
    return errormsg.c_str();
}

class ErrorIndex : public BaseError
{
public:
    ErrorIndex(string filename, string classname, int num_line,
               const char *time, int index) :
        BaseError(filename, classname, num_line, time,
                  "Error: wrong index " + to_string(index)){}

    virtual ~ErrorIndex();
};
ErrorIndex::~ErrorIndex() = default;

class ErrorMemory : public BaseError
{
public:
    ErrorMemory(string filename, string classname, int num_line,
                const char *time) :
        BaseError(filename, classname, num_line, time, "Memory error"){}

    virtual ~ErrorMemory();
};
ErrorMemory::~ErrorMemory() = default;

/*class ErrorElem : public BaseError
{
public:
    ErrorElem(string filename, string classname, int num_line,
                const char *time, char elem) :
        BaseError(filename, classname, num_line, time,
                  "Error: wrong element " + to_string(elem)){}

    virtual ~ErrorElem();
};
ErrorElem::~ErrorElem() = default;*/

class ErrorSize : public BaseError
{
public:
    ErrorSize(string filename, string classname, int num_line,
               const char *time, int num) :
        BaseError(filename, classname, num_line, time,
                  "Error: wrong size " + to_string(num)){}

    virtual ~ErrorSize();
};
ErrorSize::~ErrorSize() = default;

class ErrorEmpty : public BaseError
{
public:
    ErrorEmpty(string filename, string classname, int num_line,
               const char *time) :
        BaseError(filename, classname, num_line, time, "Error: vector is empty"){}

    virtual ~ErrorEmpty();
};
ErrorEmpty::~ErrorEmpty() = default;


class ErrorDivZero : public BaseError
{
public:
    ErrorDivZero(string filename, string classname, int num_line,
               const char *time) :
        BaseError(filename, classname, num_line, time, "Error: division by zero"){}

    virtual ~ErrorDivZero();
};
ErrorDivZero::~ErrorDivZero() = default;

#endif // MY_ERRORS_H
