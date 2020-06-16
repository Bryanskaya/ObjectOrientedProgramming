#-------------------------------------------------
#
# Project created by QtCreator 2020-05-31T21:55:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab_03
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Array/BaseArray.cpp \
        Builder/BaseModelBuilder.cpp \
        Builder/BuildDirector.cpp \
        Builder/ModelBuildDirector.cpp \
        Commands/commands.cpp \
        Errors/ArrayErrors.cpp \
        Errors/BaseErrors.cpp \
        Errors/SceneErrors.cpp \
        Errors/VisitorErrors.cpp \
        Objects/Camera/BaseCamera.cpp \
        Objects/Camera/Camera.cpp \
        Objects/ComplexObject.cpp \
        Objects/Edge/BaseEdge.cpp \
        Objects/Edge/Edge.cpp \
        Objects/Model/BaseModel.cpp \
        Objects/Model/Model.cpp \
        Objects/Point/BasePoint.cpp \
        Objects/Point/Point.cpp \
        Objects/SceneObject.cpp \
        Scene/BaseScene.cpp \
        Scene/Scene.cpp \
        Transformation/Transformation.cpp \
        Viewver/BaseDrawer.cpp \
        Viewver/BaseDrawerFactory.cpp \
        Viewver/Drawer.cpp \
        Viewver/QDrawerFactory.cpp \
        Viewver/Viewver.cpp \
        Visitors/DrawVisitor.cpp \
        Visitors/ObjectVisitor.cpp \
        Visitors/TransformVisitor.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        Array/Array.h \
        Array/Array.hpp \
        Array/BaseArray.h \
        Array/BaseIterator.h \
        Array/BaseIterator.hpp \
        Array/ConstIterator.h \
        Array/ConstIterator.hpp \
        Array/Iterator.h \
        Array/Iterator.hpp \
        Builder/BaseModelBuilder.h \
        Builder/BuildDirector.h \
        Builder/Builder.h \
        Builder/BuilderTxtFile.h \
        Builder/ModelBuildDirector.h \
        Commands/commands.h \
        Creator/CameraCreator.h \
        Creator/EdgeCreator.h \
        Creator/ObjectCreator.h \
        Creator/PointCreator.h \
        Errors/ArrayErrors.h \
        Errors/BaseErrors.h \
        Errors/SceneErrors.h \
        Errors/VisitorErrors.h \
        Objects/Camera/BaseCamera.h \
        Objects/Camera/Camera.h \
        Objects/ComplexObject.h \
        Objects/Edge/BaseEdge.h \
        Objects/Edge/Edge.h \
        Objects/Model/BaseModel.h \
        Objects/Model/Model.h \
        Objects/Point/BasePoint.h \
        Objects/Point/Point.h \
        Objects/SceneObject.h \
        Objects/SimpleObject.h \
        Scene/BaseScene.h \
        Scene/Scene.h \
        Transformation/Transformation.h \
        Transformation/Transformator.h \
        Viewver/BaseDrawer.h \
        Viewver/BaseDrawerFactory.h \
        Viewver/Drawer.h \
        Viewver/QDrawerFactory.h \
        Viewver/Viewver.h \
        Visitors/DrawVisitor.h \
        Visitors/ObjectVisitor.h \
        Visitors/TransformVisitor.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
