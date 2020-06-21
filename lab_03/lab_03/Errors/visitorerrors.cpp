#include "VisitorErrors.h"

using namespace error;

ViewverExpired::ViewverExpired(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Viewver error: viewver was expired"){}
ViewverExpired::~ViewverExpired() = default;

TransformExpired::TransformExpired(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Transform error: transformer was expired"){}
TransformExpired::~TransformExpired() = default;

