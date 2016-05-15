/****************************************************************************
** Meta object code from reading C++ file 'usb_debug.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../usbHid/usb_debug.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usb_debug.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_usb_debug_t {
    QByteArrayData data[14];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_usb_debug_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_usb_debug_t qt_meta_stringdata_usb_debug = {
    {
QT_MOC_LITERAL(0, 0, 9), // "usb_debug"
QT_MOC_LITERAL(1, 10, 14), // "inputBufferUPD"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "outputBufferUPD"
QT_MOC_LITERAL(4, 42, 15), // "sizeExtBuff_NZS"
QT_MOC_LITERAL(5, 58, 5), // "debug"
QT_MOC_LITERAL(6, 64, 17), // "copyToInputBuffer"
QT_MOC_LITERAL(7, 82, 6), // "size_t"
QT_MOC_LITERAL(8, 89, 10), // "indexBegin"
QT_MOC_LITERAL(9, 100, 8), // "indexEnd"
QT_MOC_LITERAL(10, 109, 18), // "onPullingExtBuffer"
QT_MOC_LITERAL(11, 128, 19), // "offPullingExtBuffer"
QT_MOC_LITERAL(12, 148, 16), // "getSizeExtBuffer"
QT_MOC_LITERAL(13, 165, 19) // "getSeqOfByteExtBuff"

    },
    "usb_debug\0inputBufferUPD\0\0outputBufferUPD\0"
    "sizeExtBuff_NZS\0debug\0copyToInputBuffer\0"
    "size_t\0indexBegin\0indexEnd\0"
    "onPullingExtBuffer\0offPullingExtBuffer\0"
    "getSizeExtBuffer\0getSeqOfByteExtBuff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_usb_debug[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   63,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,
      12,    0,   70,    2, 0x0a /* Public */,
      13,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void usb_debug::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        usb_debug *_t = static_cast<usb_debug *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inputBufferUPD(); break;
        case 1: _t->outputBufferUPD(); break;
        case 2: _t->sizeExtBuff_NZS(); break;
        case 3: _t->debug(); break;
        case 4: _t->copyToInputBuffer((*reinterpret_cast< const size_t(*)>(_a[1])),(*reinterpret_cast< const size_t(*)>(_a[2]))); break;
        case 5: _t->onPullingExtBuffer(); break;
        case 6: _t->offPullingExtBuffer(); break;
        case 7: _t->getSizeExtBuffer(); break;
        case 8: _t->getSeqOfByteExtBuff(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (usb_debug::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usb_debug::inputBufferUPD)) {
                *result = 0;
            }
        }
        {
            typedef void (usb_debug::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usb_debug::outputBufferUPD)) {
                *result = 1;
            }
        }
        {
            typedef void (usb_debug::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usb_debug::sizeExtBuff_NZS)) {
                *result = 2;
            }
        }
        {
            typedef void (usb_debug::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usb_debug::debug)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject usb_debug::staticMetaObject = {
    { &hidInterface::staticMetaObject, qt_meta_stringdata_usb_debug.data,
      qt_meta_data_usb_debug,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *usb_debug::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *usb_debug::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_usb_debug.stringdata0))
        return static_cast<void*>(const_cast< usb_debug*>(this));
    return hidInterface::qt_metacast(_clname);
}

int usb_debug::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = hidInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void usb_debug::inputBufferUPD()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void usb_debug::outputBufferUPD()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void usb_debug::sizeExtBuff_NZS()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void usb_debug::debug()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
