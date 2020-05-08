#ifndef MY_ERRORS_H
#define MY_ERRORS_H

#include <exception>
#include <string>
#include <time.h>

using namespace std;

class BaseError : public exception
{
protected:
    string errormsg;
public:
    BaseError(string filename, string classname, int num_line, string msg);
    /*{
        time_t t = time(nullptr);

        errormsg = "\n\nFile name: " + filename +
                   "\nClass:     " + classname +
                   "\nIn line:   " + to_string(num_line) +
                   "\nTime:      " + ctime(&t) +
                   msg;
    }*/

    virtual const char* what() const noexcept override;
};
/*const char* BaseError::what() const noexcept
{
    return errormsg.c_str();
}*/

class ErrorIndex : public BaseError
{
public:
    ErrorIndex(string filename, string classname, int num_line, int index);
    virtual ~ErrorIndex();
};

class ErrorMemory : public BaseError
{
public:
    ErrorMemory(string filename, string classname, int num_line);
    virtual ~ErrorMemory();
};

class ErrorSize : public BaseError
{
public:
    ErrorSize(string filename, string classname, int num_line, int num);
    virtual ~ErrorSize();
};

class ErrorEmpty : public BaseError
{
public:
    ErrorEmpty(string filename, string classname, int num_line);
    virtual ~ErrorEmpty();
};

class ErrorNotExist : public BaseError
{
public:
    ErrorNotExist(string filename, string classname, int num_line);
    virtual ~ErrorNotExist();
};

class ErrorDivZero : public BaseError
{
public:
    ErrorDivZero(string filename, string classname, int num_line);
    virtual ~ErrorDivZero();
};

/*class ErrorIndex : public BaseError
{
public:
    ErrorIndex(string filename, string classname, int num_line, int index) :
        BaseError(filename, classname, num_line,
                  "Error: wrong index " + to_string(index)){}

    virtual ~ErrorIndex();
};
ErrorIndex::~ErrorIndex() = default;

class ErrorMemory : public BaseError
{
public:
    ErrorMemory(string filename, string classname, int num_line) :
        BaseError(filename, classname, num_line, "Memory error"){}

    virtual ~ErrorMemory();
};
ErrorMemory::~ErrorMemory() = default;

class ErrorSize : public BaseError
{
public:
    ErrorSize(string filename, string classname, int num_line, int num) :
        BaseError(filename, classname, num_line,
                   "Error: wrong size " + to_string(num)){}

    virtual ~ErrorSize();
};
ErrorSize::~ErrorSize() = default;

class ErrorEmpty : public BaseError
{
public:
    ErrorEmpty(string filename, string classname, int num_line) :
        BaseError(filename, classname, num_line, "Error: vector is empty"){}

    virtual ~ErrorEmpty();
};
ErrorEmpty::~ErrorEmpty() = default;

class ErrorNotExist : public BaseError
{
public:
    ErrorNotExist(string filename, string classname, int num_line) :
        BaseError(filename, classname, num_line, "Error: element not exist"){}

    virtual ~ErrorNotExist();
};
ErrorNotExist::~ErrorNotExist() = default;

class ErrorDivZero : public BaseError
{
public:
    ErrorDivZero(string filename, string classname, int num_line) :
        BaseError(filename, classname, num_line, "Error: division by zero"){}

    virtual ~ErrorDivZero();
};
ErrorDivZero::~ErrorDivZero() = default;*/

#endif // MY_ERRORS_H
