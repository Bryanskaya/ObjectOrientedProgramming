TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        base_vector.cpp \
        errors.cpp \
        main.cpp

HEADERS += \
    base_iterator.h \
    base_iterator.hpp \
    base_vector.h \
    const_iterator.h \
    const_iterator.hpp \
    errors.h \
    iterator.h \
    iterator.hpp \
    vector.h \
    vector.hpp
