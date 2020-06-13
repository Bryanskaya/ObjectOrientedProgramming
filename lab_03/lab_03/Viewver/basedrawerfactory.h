#ifndef BASEDRAWERFACTORY_H
#define BASEDRAWERFACTORY_H

#include <memory>

#include "basedrawer.h"

using namespace std;


class BaseDrawerFactory
{
public:
    BaseDrawerFactory();
    virtual ~BaseDrawerFactory() = 0;

    virtual unique_ptr<BaseDrawer> create() = 0;
};

#endif // BASEDRAWERFACTORY_H
