#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include "BaseCommand.h"
#include "Viewver/qdrawerfactory.h"

class DrawCommand : public BaseCommand
{
public:
    DrawCommand();
    virtual ~DrawCommand() = 0;

    virtual void execute(weak_ptr<BaseScene> scene);

protected:
    shared_ptr<BaseDrawerFactory> _draw;
};


class QDrawScene : public DrawCommand
{
public:
    QDrawScene(weak_ptr<QGraphicsScene> scene,
               const QPen& point, const QPen& line);

    virtual ~QDrawScene();
};

#endif // DRAWCOMMAND_H
