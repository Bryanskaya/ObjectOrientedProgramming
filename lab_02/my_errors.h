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

    virtual const char* what() const noexcept override;
};
const char* BaseError::what() const noexcept
{
    //return errormsg.c_str();
    return "Test";
}

class ErrorIndex : public BaseError
{
/*private:
    string err = "Error: wrong index ";*/
public:
    ErrorIndex(string filename, string classname, int num_line,
               const char *time, int index) :
        BaseError(filename, classname, num_line, time,
                  "Error: wrong index " + to_string(index)){}

    virtual const char* what() const noexcept override;
};

class ErrorMemory : public BaseError
{
/*private:
    string msg = "Memory error";*/
public:
    ErrorMemory(string filename, string classname, int num_line,
                const char *time) :
        BaseError(filename, classname, num_line, time, "Memory error"){}

    virtual const char* what() const noexcept override;
};

class ErrorElem : public BaseError
{
private:
    string msg = "Error: wrong element ";
public:
    ErrorElem(string filename, string classname, int num_line,
                const char *time, char elem) :
        BaseError(filename, classname, num_line, time, "Error: wrong element " + to_string(elem)){}

    virtual const char* what() const noexcept override;
};

class ErrorSize : public BaseError
{
/*private:
    string msg = "Error: wrong size ";
    int size;*/
public:
    ErrorSize(string filename, string classname, int num_line,
               const char *time, int num) :
        BaseError(filename, classname, num_line, time, "Error: wrong size " + to_string(num)){}

    virtual const char* what() const noexcept override;
};

/*class ErrorEmpty : public BaseError
{
private:
    string msg = "Error: vector is empty";
public:
    ErrorEmpty(string filename, string classname, int num_line,
               const char *time, string msg) :
        BaseError(filename, classname, num_line, time, msg){};

    virtual const char* what() const noexcept override;
};
const char* ErrorEmpty::what() const noexcept
{
    const_cast<ErrorEmpty*>(this)->errormsg = msg;

    return errormsg.c_str();
}

class ErrorDivZero : public BaseError
{
private:
    string msg = "Error: division by zero";
public:
    ErrorDivZero(string filename, string classname, int num_line,
               const char *time, string msg) :
        BaseError(filename, classname, num_line, time, msg){};

    virtual const char* what() const noexcept override;
};
const char* ErrorDivZero::what() const noexcept
{
    const_cast<ErrorDivZero*>(this)->errormsg = errormsg +  msg;

    return errormsg.c_str();
}*/

#endif // MY_ERRORS_H
