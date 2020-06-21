#include "loaderrors.h"

using namespace error;

OpeningFail::OpeningFail(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "File error: opening was failed"){}
OpeningFail::~OpeningFail() = default;

FileNotOpened::FileNotOpened(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "File error: file was not opened"){}
FileNotOpened::~FileNotOpened() = default;

WrongNodeNum::WrongNodeNum(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Data error: wrong number of nodes"){}
WrongNodeNum::~WrongNodeNum() = default;

WrongEdgeNum::WrongEdgeNum(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Data error: wrong number of edges"){}
WrongEdgeNum::~WrongEdgeNum() = default;

WrongPointIndex::WrongPointIndex(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Data error: wrong index of point"){}
WrongPointIndex::~WrongPointIndex() = default;
