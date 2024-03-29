#include "Viewver.h"

Viewver::Viewver() {}

Viewver::~Viewver() {}

void Viewver::set_drawer(BaseDrawerFactory &factory)
{
    _draw = factory.create();
}

void Viewver::set_camera(shared_ptr<BaseCamera> camera)
{
    _camera = camera;
}

void Viewver::draw_line(const BasePoint &point1, const BasePoint &point2)
{
    BasePoint p1(*_projecting_point(point1));
    BasePoint p2(*_projecting_point(point2));

    _draw->draw_line(p1.get_x(), p1.get_y(),
                     p2.get_x(), p2.get_y());
}

void Viewver::draw_point(const BasePoint &point)
{
    BasePoint p(*_projecting_point(point));

    _draw->draw_point(p.get_x(), p.get_y());
}

void Viewver::clear()
{
    _draw->clear();
}

shared_ptr<BasePoint> Viewver::_projecting_point(const BasePoint &point)
{
    shared_ptr<BasePoint> result_point(new Point());
    double k;

    if (fabs(_camera->get_z() - point.get_z()) < 1e-5)
        k = 1e30;
    else
        k = _camera->get_z() / (_camera->get_z() - point.get_z());

    result_point->set_z(0);
    result_point->set_y(_camera->get_y() + (point.get_y() - _camera->get_y()) * k);
    result_point->set_x(_camera->get_x() + (point.get_x() - _camera->get_x()) * k);

    return result_point;
}
