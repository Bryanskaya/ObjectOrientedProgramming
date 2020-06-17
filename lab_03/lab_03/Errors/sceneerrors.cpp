#include "Errors/sceneerrors.h"

using namespace error;

SceneExpired::SceneExpired(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Scene error: scene was expired"){}
SceneExpired::~SceneExpired() = default;

DrawExpired::DrawExpired(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Draw error: drawer was expired"){}
DrawExpired::~DrawExpired() = default;

DirectorExpired::DirectorExpired(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Director error: director was expired"){}
DirectorExpired::~DirectorExpired() = default;

CreatorExpired::CreatorExpired(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Create error: creator was expired"){}
CreatorExpired::~CreatorExpired() = default;
