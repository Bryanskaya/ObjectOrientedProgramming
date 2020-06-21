#ifndef SCENEERRORS_H
#define SCENEERRORS_H

#include "BaseErrors.h"

namespace error {

class SceneExpired : public BaseError
{
public:
    SceneExpired(string filename, string classname, int num_line);
    virtual ~SceneExpired();
};

class DrawExpired : public BaseError
{
public:
    DrawExpired(string filename, string classname, int num_line);
    virtual ~DrawExpired();
};

class DirectorExpired : public BaseError
{
public:
    DirectorExpired(string filename, string classname, int num_line);
    virtual ~DirectorExpired();
};

class CreatorExpired : public BaseError
{
public:
    CreatorExpired(string filename, string classname, int num_line);
    virtual ~CreatorExpired();
};

}

#endif // SCENEERRORS_H
