#include "qdrawerfactory.h"

QDrawerFactory::QDrawerFactory(weak_ptr<QGraphicsScene> scene, const QPen& point_pen,
                               const QPen& line_pen) : _scene(scene), _point_pen(point_pen), _line_pen(line_pen) {}

QDrawerFactory::~QDrawerFactory() {}

shared_ptr<BaseDrawer> QDrawerFactory:: create()
{
    return shared_ptr<BaseDrawer>(new Drawer(_scene, _point_pen, _line_pen));
}
