/****************************************************************************
** Meta object code from reading C++ file 'usbhid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../usbhid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usbhid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_usbHid_t {
    QByteArrayData data[13];
    char stringdata[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_usbHid_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_usbHid_t qt_meta_stringdata_usbHid = {
    {
QT_MOC_LITERAL(0, 0, 6), // "usbHid"
QT_MOC_LITERAL(1, 7, 12), // "valueChanged"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "devDisconnect"
QT_MOC_LITERAL(4, 35, 12), // "devConnected"
QT_MOC_LITERAL(5, 48, 9), // "enumerate"
QT_MOC_LITERAL(6, 58, 7), // "hidOpen"
QT_MOC_LITERAL(7, 66, 8), // "hidClose"
QT_MOC_LITERAL(8, 75, 16), // "hid_send_feature"
QT_MOC_LITERAL(9, 92, 6), // "size_t"
QT_MOC_LITERAL(10, 99, 15), // "hid_get_feature"
QT_MOC_LITERAL(11, 115, 13), // "waitPluginDev"
QT_MOC_LITERAL(12, 129, 17) // "stopWaitPluginDev"

    },
    "usbHid\0valueChanged\0\0devDisconnect\0"
    "devConnected\0enumerate\0hidOpen\0hidClose\0"
    "hid_send_feature\0size_t\0hid_get_feature\0"
    "waitPluginDev\0stopWaitPluginDev"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_usbHid[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    0,   67,    2, 0x06 /* Public */,
       4,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   69,    2, 0x0a /* Public */,
       6,    0,   70,    2, 0x0a /* Public */,
       7,    0,   71,    2, 0x0a /* Public */,
       8,    1,   72,    2, 0x0a /* Public */,
      10,    1,   75,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Int, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void usbHid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        usbHid *_t = static_cast<usbHid *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->devDisconnect(); break;
        case 2: _t->devConnected(); break;
        case 3: _t->enumerate(); break;
        case 4: { bool _r = _t->hidOpen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->hidClose(); break;
        case 6: _t->hid_send_feature((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 7: { int _r = _t->hid_get_feature((*reinterpret_cast< size_t(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: _t->waitPluginDev(); break;
        case 9: _t->stopWaitPluginDev(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (usbHid::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usbHid::valueChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (usbHid::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usbHid::devDisconnect)) {
                *result = 1;
            }
        }
        {
            typedef void (usbHid::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usbHid::devConnected)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject usbHid::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_usbHid.data,
      qt_meta_data_usbHid,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *usbHid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *usbHid::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_usbHid.stringdata))
        return static_cast<void*>(const_cast< usbHid*>(this));
    return QObject::qt_metacast(_clname);
}

int usbHid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void usbHid::valueChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void usbHid::devDisconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void usbHid::devConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
struct qt_meta_stringdata_hidInterface_t {
    QByteArrayData data[3];
    char stringdata[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hidInterface_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hidInterface_t qt_meta_stringdata_hidInterface = {
    {
QT_MOC_LITERAL(0, 0, 12), // "hidInterface"
QT_MOC_LITERAL(1, 13, 8), // "autoPlug"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "hidInterface\0autoPlug\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hidInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void hidInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hidInterface *_t = static_cast<hidInterface *>(_o);
        switch (_id) {
        case 0: _t->autoPlug((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject hidInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_hidInterface.data,
      qt_meta_data_hidInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *hidInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hidInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_hidInterface.stringdata))
        return static_cast<void*>(const_cast< hidInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int hidInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
