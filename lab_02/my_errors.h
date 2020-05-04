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
                   "\nClass: " + classname +
                   "\nIn line: " + to_string(num_line) +
                   "\nTime: " + time +
                   "\nInfo: " + msg;
    }
    // у Тассова тут удаление какое-то, но у меня string и оно не хочет
    //virtual ~BaseError() { delete[]errormsg; }

    virtual const char* what() const noexcept override { return errormsg.c_str(); }
};

class ErrorIndex : public BaseError
{
private:
    string msg = "Error: wrong index: ";
    int ind;
public:
    ErrorIndex(string filename, string classname, int num_line,
               const char *time, string msg, int index) :
        BaseError(filename, classname, num_line, time, msg), ind(index){};
    virtual ~ErrorIndex(){} // не уверена

    virtual const char* what() const noexcept override
    {
        const_cast<ErrorIndex*>(this)->errormsg = msg + to_string(ind);

        return errormsg.c_str();
    }
};

class ErrorMemory : public BaseError
{
private:
    string msg = "Memory error";
public:
    ErrorMemory(string filename, string classname, int num_line,
                const char *time, string msg) :
        BaseError(filename, classname, num_line, time, msg){};
    virtual ~ErrorMemory(){} // не уверена

    virtual const char* what() const noexcept override
    {
        const_cast<ErrorMemory*>(this)->errormsg = msg;

        return errormsg.c_str();
    }
};

class ErrorElem : public BaseError
{
private:
    string msg = "Error: wrong element";
public:
    ErrorElem(string filename, string classname, int num_line,
                const char *time, string msg) :
        BaseError(filename, classname, num_line, time, msg){};
    virtual ~ErrorElem(){} // не уверена

    virtual const char* what() const noexcept override
    {
        const_cast<ErrorElem*>(this)->errormsg = msg;

        return errormsg.c_str();
    }
};

class ErrorSize : public BaseError
{
private:
    string msg = "Wrong size";
    int size;
public:
    ErrorSize(string filename, string classname, int num_line,
               const char *time, string msg, int num) :
        BaseError(filename, classname, num_line, time, msg), size(num){};
    virtual ~ErrorSize(){} // не уверена

    virtual const char* what() const noexcept override
    {
        const_cast<ErrorSize*>(this)->errormsg = msg + to_string(size);

        return errormsg.c_str();
    }
};

class ErrorEmpty : public BaseError
{
private:
    string msg = "Vector is empty";
public:
    ErrorEmpty(string filename, string classname, int num_line,
               const char *time, string msg) :
        BaseError(filename, classname, num_line, time, msg){};
    virtual ~ErrorEmpty(){} // не уверена

    virtual const char* what() const noexcept override
    {
        const_cast<ErrorEmpty*>(this)->errormsg = msg;

        return errormsg.c_str();
    }
};

class ErrorDivZero : public BaseError
{
private:
    string msg = "Division by zero";
public:
    ErrorDivZero(string filename, string classname, int num_line,
               const char *time, string msg) :
        BaseError(filename, classname, num_line, time, msg){};
    virtual ~ErrorDivZero(){} // не уверена

    virtual const char* what() const noexcept override
    {
        const_cast<ErrorDivZero*>(this)->errormsg = errormsg +  msg;

        return errormsg.c_str();
    }
};

#endif // MY_ERRORS_H
