#include "drawcommand.h"

DrawCommand::DrawCommand() {}

DrawCommand::~DrawCommand() {}

void DrawCommand::execute(weak_ptr<BaseScene> scene)
{
    DrawManager(scene, _draw).execute();
}

QDrawScene::QDrawScene(weak_ptr<QGraphicsScene> scene,
                       const QPen& point, const QPen& line)
{
    _draw = shared_ptr<BaseDrawerFactory>(new QDrawerFactory(scene, point, line));
}

QDrawScene::~QDrawScene() {}
