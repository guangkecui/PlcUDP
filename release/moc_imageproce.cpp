/****************************************************************************
** Meta object code from reading C++ file 'imageproce.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../imageproce.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageproce.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageProce_t {
    QByteArrayData data[17];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageProce_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageProce_t qt_meta_stringdata_ImageProce = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ImageProce"
QT_MOC_LITERAL(1, 11, 21), // "sendPointToMainwindow"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 50, 1), // "x"
QT_MOC_LITERAL(5, 52, 1), // "y"
QT_MOC_LITERAL(6, 54, 1), // "z"
QT_MOC_LITERAL(7, 56, 23), // "sendMessageToMainwindow"
QT_MOC_LITERAL(8, 80, 3), // "msg"
QT_MOC_LITERAL(9, 84, 35), // "receiveIsSinglePointShowFromM..."
QT_MOC_LITERAL(10, 120, 12), // "isSingleShow"
QT_MOC_LITERAL(11, 133, 8), // "TestSlot"
QT_MOC_LITERAL(12, 142, 40), // "receiveFilepathFromManagerToI..."
QT_MOC_LITERAL(13, 183, 18), // "ImagePath_LightOFF"
QT_MOC_LITERAL(14, 202, 17), // "ImagePath_LightON"
QT_MOC_LITERAL(15, 220, 27), // "receiveThresholdFromMaindow"
QT_MOC_LITERAL(16, 248, 3) // "val"

    },
    "ImageProce\0sendPointToMainwindow\0\0"
    "QVector<double>\0x\0y\0z\0sendMessageToMainwindow\0"
    "msg\0receiveIsSinglePointShowFromMaindow\0"
    "isSingleShow\0TestSlot\0"
    "receiveFilepathFromManagerToImageProcess\0"
    "ImagePath_LightOFF\0ImagePath_LightON\0"
    "receiveThresholdFromMaindow\0val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProce[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       7,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   54,    2, 0x0a /* Public */,
      11,    0,   57,    2, 0x0a /* Public */,
      12,    2,   58,    2, 0x0a /* Public */,
      15,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void ImageProce::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageProce *_t = static_cast<ImageProce *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendPointToMainwindow((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 1: _t->sendMessageToMainwindow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->receiveIsSinglePointShowFromMaindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->TestSlot(); break;
        case 4: _t->receiveFilepathFromManagerToImageProcess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->receiveThresholdFromMaindow((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageProce::*_t)(QVector<double> , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProce::sendPointToMainwindow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ImageProce::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProce::sendMessageToMainwindow)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ImageProce::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageProce.data,
      qt_meta_data_ImageProce,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageProce::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageProce::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProce.stringdata0))
        return static_cast<void*>(const_cast< ImageProce*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageProce::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ImageProce::sendPointToMainwindow(QVector<double> _t1, QVector<double> _t2, QVector<double> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageProce::sendMessageToMainwindow(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
