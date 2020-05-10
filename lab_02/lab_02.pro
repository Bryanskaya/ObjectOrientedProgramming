TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        base_vector.cpp \
        main.cpp \
        my_errors.cpp

HEADERS += \
    base_iterator.h \
    base_vector.h \
    const_iterator.h \
    const_iterator.hpp \
    iterator.h \
    iterator.hpp \
    my_errors.h \
    vector.h \
    vector.hpp
