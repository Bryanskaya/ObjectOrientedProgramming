TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        baseiterator.cpp \
        basevector.cpp \
        main.cpp \
        my_errors.cpp

HEADERS += \
    baseiterator.h \
    basevector.h \
    iterator.h \
    iterator.hpp \
    my_errors.h \
    vector.h
