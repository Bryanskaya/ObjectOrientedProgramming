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
        const_cast<ErrorIndex*>(this)->errormsg = errormsg + msg + to_string(ind);

        return errormsg.c_str();
    }
};



#endif // MY_ERRORS_H
