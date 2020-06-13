#include "Errors/sceneerrors.h"

using namespace error;

SceneExpired::SceneExpired(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Scene error: scene was expired"){}
SceneExpired::~SceneExpired() = default;
