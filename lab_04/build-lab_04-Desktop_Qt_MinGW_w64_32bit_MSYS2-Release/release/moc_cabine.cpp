/****************************************************************************
** Meta object code from reading C++ file 'cabine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lab_04/cabine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cabine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LiftCabine_t {
    QByteArrayData data[17];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LiftCabine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LiftCabine_t qt_meta_stringdata_LiftCabine = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LiftCabine"
QT_MOC_LITERAL(1, 11, 12), // "start_moving"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 6), // "moving"
QT_MOC_LITERAL(4, 32, 11), // "stop_moving"
QT_MOC_LITERAL(5, 44, 10), // "open_doors"
QT_MOC_LITERAL(6, 55, 12), // "wait_request"
QT_MOC_LITERAL(7, 68, 14), // "achieved_floor"
QT_MOC_LITERAL(8, 83, 6), // "size_t"
QT_MOC_LITERAL(9, 90, 9), // "floor_num"
QT_MOC_LITERAL(10, 100, 9), // "Direction"
QT_MOC_LITERAL(11, 110, 3), // "dir"
QT_MOC_LITERAL(12, 114, 10), // "slot_close"
QT_MOC_LITERAL(13, 125, 12), // "slot_request"
QT_MOC_LITERAL(14, 138, 10), // "slot_start"
QT_MOC_LITERAL(15, 149, 11), // "slot_moving"
QT_MOC_LITERAL(16, 161, 9) // "slot_stop"

    },
    "LiftCabine\0start_moving\0\0moving\0"
    "stop_moving\0open_doors\0wait_request\0"
    "achieved_floor\0size_t\0floor_num\0"
    "Direction\0dir\0slot_close\0slot_request\0"
    "slot_start\0slot_moving\0slot_stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LiftCabine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    2,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   84,    2, 0x0a /* Public */,
      13,    1,   87,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x2a /* Public | MethodCloned */,
      14,    0,   91,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LiftCabine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LiftCabine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->start_moving(); break;
        case 1: _t->moving(); break;
        case 2: _t->stop_moving(); break;
        case 3: _t->open_doors(); break;
        case 4: _t->wait_request(); break;
        case 5: _t->achieved_floor((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< Direction(*)>(_a[2]))); break;
        case 6: _t->slot_close((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 7: _t->slot_request((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 8: _t->slot_request(); break;
        case 9: _t->slot_start(); break;
        case 10: _t->slot_moving(); break;
        case 11: _t->slot_stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LiftCabine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabine::start_moving)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LiftCabine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabine::moving)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LiftCabine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabine::stop_moving)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LiftCabine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabine::open_doors)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LiftCabine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabine::wait_request)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (LiftCabine::*)(size_t , Direction );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabine::achieved_floor)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LiftCabine::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_LiftCabine.data,
    qt_meta_data_LiftCabine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LiftCabine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LiftCabine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LiftCabine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LiftCabine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void LiftCabine::start_moving()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LiftCabine::moving()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LiftCabine::stop_moving()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void LiftCabine::open_doors()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void LiftCabine::wait_request()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void LiftCabine::achieved_floor(size_t _t1, Direction _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
