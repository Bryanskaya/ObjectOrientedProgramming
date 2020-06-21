#include "arrayerrors.h"

using namespace error;

WrongIndex::WrongIndex(string filename, string classname, int num_line, int index) :
    BaseError(filename, classname, num_line,
              "Array error: wrong index " + to_string(index)){}
WrongIndex::~WrongIndex() = default;

WrongSize::WrongSize(string filename, string classname, int num_line, int num) :
    BaseError(filename, classname, num_line,
               "Array error: wrong size " + to_string(num)){}
WrongSize::~WrongSize() = default;

ArrayPtrExpired::ArrayPtrExpired(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line, "Array error: pointer is deleted"){}
ArrayPtrExpired::~ArrayPtrExpired() = default;

ArrayCountExpired::ArrayCountExpired(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line, "Array error: count pointer is deleted"){}
ArrayCountExpired::~ArrayCountExpired() = default;

AllocProblem::AllocProblem(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line, "Array error: memory allocation is failed"){}
AllocProblem::~AllocProblem() = default;

IndexOutRange::IndexOutRange(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line, "Array error: index out of range"){}
IndexOutRange::~IndexOutRange() = default;

