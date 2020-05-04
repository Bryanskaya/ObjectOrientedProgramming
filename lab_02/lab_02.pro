TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        baseiterator.cpp \
        basevector.cpp \
        main.cpp \
        vector.cpp

HEADERS += \
    baseiterator.h \
    basevector.h \
    iterator.h \
    my_errors.h \
    vector.h
