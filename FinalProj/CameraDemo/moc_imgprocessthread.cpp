/****************************************************************************
** Meta object code from reading C++ file 'imgprocessthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imgprocessthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imgprocessthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_imgprocessthread_t {
    QByteArrayData data[6];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_imgprocessthread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_imgprocessthread_t qt_meta_stringdata_imgprocessthread = {
    {
QT_MOC_LITERAL(0, 0, 16), // "imgprocessthread"
QT_MOC_LITERAL(1, 17, 9), // "processed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "cmd_suspend_cap"
QT_MOC_LITERAL(4, 44, 14), // "cmd_resume_cap"
QT_MOC_LITERAL(5, 59, 16) // "slot_startThread"

    },
    "imgprocessthread\0processed\0\0cmd_suspend_cap\0"
    "cmd_resume_cap\0slot_startThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_imgprocessthread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    0,   37,    2, 0x06 /* Public */,
       4,    0,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void imgprocessthread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        imgprocessthread *_t = static_cast<imgprocessthread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processed((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->cmd_suspend_cap(); break;
        case 2: _t->cmd_resume_cap(); break;
        case 3: _t->slot_startThread(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (imgprocessthread::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&imgprocessthread::processed)) {
                *result = 0;
            }
        }
        {
            typedef void (imgprocessthread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&imgprocessthread::cmd_suspend_cap)) {
                *result = 1;
            }
        }
        {
            typedef void (imgprocessthread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&imgprocessthread::cmd_resume_cap)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject imgprocessthread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_imgprocessthread.data,
      qt_meta_data_imgprocessthread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *imgprocessthread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *imgprocessthread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_imgprocessthread.stringdata0))
        return static_cast<void*>(const_cast< imgprocessthread*>(this));
    return QObject::qt_metacast(_clname);
}

int imgprocessthread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void imgprocessthread::processed(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void imgprocessthread::cmd_suspend_cap()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void imgprocessthread::cmd_resume_cap()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
