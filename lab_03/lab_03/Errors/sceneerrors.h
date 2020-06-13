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

}

#endif // SCENEERRORS_H
