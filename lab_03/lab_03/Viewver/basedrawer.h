#ifndef BASEDRAWER_H
#define BASEDRAWER_H

#include "Errors/sceneerrors.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void draw_line(double x1, double y1, double x, double y2) = 0;
    virtual void draw_point(double x, double y) = 0;
    virtual void clear() = 0;
};

#endif // BASEDRAWER_H
