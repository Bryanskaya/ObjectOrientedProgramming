#ifndef VIEWVER_H
#define VIEWVER_H

#include <math.h>

#include "Objects/Camera/BaseCamera.h"
#include "Objects/Point/basepoint.h"
#include "Objects/Point/Point.h"
#include "Viewver/basedrawerfactory.h"


class Viewver
{
public:
    Viewver();
    ~Viewver();

    void set_drawer(BaseDrawerFactory& factory);
    void set_camera(shared_ptr<BaseCamera> camera);

    void draw_line(const BasePoint& point1, const BasePoint& point2);
    void draw_point(const BasePoint& point);

    void clear();

private:
    shared_ptr<BaseCamera> _camera;
    shared_ptr<BaseDrawer> _draw;

    shared_ptr<BasePoint> _projecting_point(const BasePoint& point);
};

#endif // VIEWVER_H
