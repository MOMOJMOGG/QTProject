/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[454];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 30), // "on_pushButton_init_cam_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 27), // "on_pushButton_start_clicked"
QT_MOC_LITERAL(4, 71, 27), // "on_pushButton_pause_clicked"
QT_MOC_LITERAL(5, 99, 19), // "slot_handleCaputred"
QT_MOC_LITERAL(6, 119, 3), // "img"
QT_MOC_LITERAL(7, 123, 20), // "slot_handleCaputred2"
QT_MOC_LITERAL(8, 144, 33), // "on_lineEdit_threshold_textCha..."
QT_MOC_LITERAL(9, 178, 4), // "arg1"
QT_MOC_LITERAL(10, 183, 26), // "on_lineEdit_wd_textChanged"
QT_MOC_LITERAL(11, 210, 29), // "on_lineEdit_fov_w_textChanged"
QT_MOC_LITERAL(12, 240, 29), // "on_lineEdit_fov_h_textChanged"
QT_MOC_LITERAL(13, 270, 34), // "on_lineEdit_filtersize_textCh..."
QT_MOC_LITERAL(14, 305, 25), // "on_pushButton_led_clicked"
QT_MOC_LITERAL(15, 331, 31), // "on_pushButton_antiflash_clicked"
QT_MOC_LITERAL(16, 363, 30), // "on_pushButton_mirror_h_clicked"
QT_MOC_LITERAL(17, 394, 30), // "on_pushButton_mirror_v_clicked"
QT_MOC_LITERAL(18, 425, 28) // "on_pushButton_binary_clicked"

    },
    "MainWindow\0on_pushButton_init_cam_clicked\0"
    "\0on_pushButton_start_clicked\0"
    "on_pushButton_pause_clicked\0"
    "slot_handleCaputred\0img\0slot_handleCaputred2\0"
    "on_lineEdit_threshold_textChanged\0"
    "arg1\0on_lineEdit_wd_textChanged\0"
    "on_lineEdit_fov_w_textChanged\0"
    "on_lineEdit_fov_h_textChanged\0"
    "on_lineEdit_filtersize_textChanged\0"
    "on_pushButton_led_clicked\0"
    "on_pushButton_antiflash_clicked\0"
    "on_pushButton_mirror_h_clicked\0"
    "on_pushButton_mirror_v_clicked\0"
    "on_pushButton_binary_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    1,   92,    2, 0x08 /* Private */,
       7,    1,   95,    2, 0x08 /* Private */,
       8,    1,   98,    2, 0x08 /* Private */,
      10,    1,  101,    2, 0x08 /* Private */,
      11,    1,  104,    2, 0x08 /* Private */,
      12,    1,  107,    2, 0x08 /* Private */,
      13,    1,  110,    2, 0x08 /* Private */,
      14,    0,  113,    2, 0x08 /* Private */,
      15,    0,  114,    2, 0x08 /* Private */,
      16,    0,  115,    2, 0x08 /* Private */,
      17,    0,  116,    2, 0x08 /* Private */,
      18,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    6,
    QMetaType::Void, QMetaType::QImage,    6,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_init_cam_clicked(); break;
        case 1: _t->on_pushButton_start_clicked(); break;
        case 2: _t->on_pushButton_pause_clicked(); break;
        case 3: _t->slot_handleCaputred((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->slot_handleCaputred2((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_threshold_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_wd_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_lineEdit_fov_w_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_lineEdit_fov_h_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_lineEdit_filtersize_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_led_clicked(); break;
        case 11: _t->on_pushButton_antiflash_clicked(); break;
        case 12: _t->on_pushButton_mirror_h_clicked(); break;
        case 13: _t->on_pushButton_mirror_v_clicked(); break;
        case 14: _t->on_pushButton_binary_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
