#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene/BaseScene.h"
#include "Transformation/Transformator.h"
#include "Viewver/Viewver.h"
#include "Builder/BuildDirector.h"
#include "Creator/ObjectCreator.h"

class SceneManager
{
public:
    SceneManager(weak_ptr<BaseScene> scene);
    virtual ~SceneManager() = 0;

    virtual void execute() = 0;

protected:
    weak_ptr<BaseScene> _scene;
    Iterator<shared_ptr<SceneObject>> _find_pos(size_t index);
};

class CameraManager : public SceneManager
{
public:
    CameraManager(weak_ptr<BaseScene> scene, size_t index);
    virtual ~CameraManager();

    virtual void execute();

private:
    size_t _ind;
};

class TransformManager : public SceneManager
{
public:
    TransformManager(weak_ptr<BaseScene> scene,
                     weak_ptr<Transformator> transf,
                     size_t ind);
    virtual ~TransformManager();

    virtual void execute();

private:
    weak_ptr<Transformator> _transf;
    size_t _ind;
};

class DrawManager : public SceneManager
{
public:
    DrawManager(weak_ptr<BaseScene> scene,
                weak_ptr<BaseDrawerFactory> draw);
    virtual ~DrawManager();

    virtual void execute();

private:
    weak_ptr<BaseDrawerFactory> _draw;
};

class LoadManager : public SceneManager
{
public:
    LoadManager(weak_ptr<BaseScene> scene,
                weak_ptr<BuildDirector> dir);
    virtual ~LoadManager();

    virtual void execute();

private:
    weak_ptr<BuildDirector> _director;
};

class AddManager : public SceneManager
{
public:
    AddManager(weak_ptr<BaseScene> scene,
               weak_ptr<ObjectCreator> creator);
    virtual ~AddManager();

    virtual void execute();

private:
    weak_ptr<ObjectCreator> _creator;
};

class RemoveManager : public SceneManager
{
public:
    RemoveManager(weak_ptr<BaseScene> scene, size_t ind);
    virtual ~RemoveManager();

    virtual void execute();

private:
    size_t _index;
};

#endif // SCENEMANAGER_H
