#include "drawer.h"

Drawer::Drawer(weak_ptr<QGraphicsScene> scene, const QPen& point_pen,
               const QPen& line_pen) : _scene(scene), _point_pen(point_pen), _line_pen(line_pen)
{
    _point_brush = QBrush(_line_pen.color());
}

Drawer::~Drawer() {}

void Drawer::draw_point(double x, double y)
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(),__LINE__ - 1);

    shared_ptr<QGraphicsScene> scene = _scene.lock();
    scene->addEllipse(x - 1, -y - 1, 2, 2, _point_pen, _point_brush);
}

void Drawer::draw_line(double x1, double y1, double x2, double y2)
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(),__LINE__ - 1);

    shared_ptr<QGraphicsScene> scene = _scene.lock();
    scene->addLine(x1, -y1, x2, -y2, _line_pen);
}

void Drawer::clear()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(),__LINE__ - 1);

    shared_ptr<QGraphicsScene> scene = _scene.lock();
    scene->clear();
}
