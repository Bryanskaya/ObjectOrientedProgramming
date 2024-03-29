#include "errors.h"

VectorError::VectorError(string filename, string classname, int num_line,
                     string msg = "Error")
{
    time_t t = time(nullptr);

    errormsg = "\n\nFile name: " + filename +
               "\nClass:     " + classname +
               "\nIn line:   " + to_string(num_line) +
               "\nTime:      " + ctime(&t) +
               msg;
}
VectorError::~VectorError()
{
}

const char* VectorError::what() const noexcept
{
    return errormsg.c_str();
}

ErrorIndex::ErrorIndex(string filename, string classname, int num_line, int index) :
    VectorError(filename, classname, num_line,
              "Error: wrong index " + to_string(index)){}
ErrorIndex::~ErrorIndex() = default;

ErrorMemory::ErrorMemory(string filename, string classname, int num_line) :
    VectorError(filename, classname, num_line, "Memory error"){}
ErrorMemory::~ErrorMemory() = default;

ErrorWrongSize::ErrorWrongSize(string filename, string classname, int num_line, int num) :
    VectorError(filename, classname, num_line,
               "Error: wrong size " + to_string(num)){}
ErrorWrongSize::~ErrorWrongSize() = default;

ErrorEmptyVector::ErrorEmptyVector(string filename, string classname, int num_line) :
    VectorError(filename, classname, num_line, "Error: vector is empty"){}
ErrorEmptyVector::~ErrorEmptyVector() = default;

ErrorArrayExpired::ErrorArrayExpired(string filename, string classname, int num_line) :
    VectorError(filename, classname, num_line, "Error: array pointer is deleted"){}
ErrorArrayExpired::~ErrorArrayExpired() = default;

ErrorCountExpired::ErrorCountExpired(string filename, string classname, int num_line) :
    VectorError(filename, classname, num_line, "Error: count pointer is deleted"){}
ErrorCountExpired::~ErrorCountExpired() = default;

ErrorDivZero::ErrorDivZero(string filename, string classname, int num_line) :
    VectorError(filename, classname, num_line, "Error: division by zero"){}
ErrorDivZero::~ErrorDivZero() = default;

ErrorDiffSize::ErrorDiffSize(string filename, string classname, int num_line,
                             size_t size1, size_t size2) :
    VectorError(filename, classname, num_line,
              "Error: different sizes:" + to_string(size1) + " " + to_string(size2)){}
ErrorDiffSize::~ErrorDiffSize() = default;

ErrorNotAllowedSize::ErrorNotAllowedSize(string filename, string classname, int num_line,
                             size_t size1, size_t size2) :
    VectorError(filename, classname, num_line,
              "Error: prohibited size: " + to_string(size1) +
              " (allowed " + to_string(size2) + ")"){}
ErrorNotAllowedSize::~ErrorNotAllowedSize() = default;

ErrorInvalidOperation::ErrorInvalidOperation(string filename, string classname, int num_line) :
    VectorError(filename, classname, num_line,
              "Error: operation is prohibited for vector"){}
ErrorInvalidOperation::~ErrorInvalidOperation() = default;
