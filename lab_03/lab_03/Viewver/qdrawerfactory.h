#ifndef QDRAWERFACTORY_H
#define QDRAWERFACTORY_H

#include "basedrawerfactory.h"
#include "drawer.h"


class QDrawerFactory : public BaseDrawerFactory
{
public:
    QDrawerFactory(weak_ptr<QGraphicsScene> scene, const QPen& point_pen,
                   const QPen& line_pen);
    virtual ~QDrawerFactory();

    virtual shared_ptr<BaseDrawer> create();

private:
    weak_ptr<QGraphicsScene> _scene;
    QPen _point_pen, _line_pen;
};

#endif // QDRAWERFACTORY_H
