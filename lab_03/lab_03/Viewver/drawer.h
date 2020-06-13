#ifndef DRAWER_H
#define DRAWER_H

#include <memory>
#include <QGraphicsScene>

#include "basedrawer.h"


using namespace std;

class Drawer : public BaseDrawer
{
public:
    Drawer(weak_ptr<QGraphicsScene> scene, const QPen& point_pen,
           const QPen& line_pen);
    virtual ~Drawer();

    virtual void draw_point(double x, double y);
    virtual void draw_line(double x1, double y1, double x, double y2);
    virtual void clear();

private:
    weak_ptr<QGraphicsScene> _scene;
    QPen _point_pen, _line_pen;
    QBrush _point_brush;
};

#endif // DRAWER_H
