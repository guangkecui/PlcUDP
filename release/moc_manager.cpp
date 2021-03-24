/****************************************************************************
** Meta object code from reading C++ file 'manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Manager_t {
    QByteArrayData data[32];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Manager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Manager_t qt_meta_stringdata_Manager = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Manager"
QT_MOC_LITERAL(1, 8, 7), // "message"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 3), // "msg"
QT_MOC_LITERAL(4, 21, 18), // "singleImageProcess"
QT_MOC_LITERAL(5, 40, 18), // "ImageName_LightOFF"
QT_MOC_LITERAL(6, 59, 17), // "ImageName_LightON"
QT_MOC_LITERAL(7, 77, 11), // "AutoModeEnd"
QT_MOC_LITERAL(8, 89, 11), // "getPosition"
QT_MOC_LITERAL(9, 101, 6), // "camera"
QT_MOC_LITERAL(10, 108, 14), // "getCameraImage"
QT_MOC_LITERAL(11, 123, 13), // "powerOnMotors"
QT_MOC_LITERAL(12, 137, 5), // "motor"
QT_MOC_LITERAL(13, 143, 14), // "powerOffMotors"
QT_MOC_LITERAL(14, 158, 9), // "manualEnd"
QT_MOC_LITERAL(15, 168, 4), // "step"
QT_MOC_LITERAL(16, 173, 10), // "continuous"
QT_MOC_LITERAL(17, 184, 7), // "autoEnd"
QT_MOC_LITERAL(18, 192, 5), // "start"
QT_MOC_LITERAL(19, 198, 13), // "timerPollDeal"
QT_MOC_LITERAL(20, 212, 12), // "backToOrigin"
QT_MOC_LITERAL(21, 225, 18), // "backToSafeLocation"
QT_MOC_LITERAL(22, 244, 8), // "isOrigin"
QT_MOC_LITERAL(23, 253, 13), // "setOriginZero"
QT_MOC_LITERAL(24, 267, 12), // "sendVelocity"
QT_MOC_LITERAL(25, 280, 8), // "inputVec"
QT_MOC_LITERAL(26, 289, 17), // "setZeroMotorFlags"
QT_MOC_LITERAL(27, 307, 18), // "setMotorToPosition"
QT_MOC_LITERAL(28, 326, 8), // "position"
QT_MOC_LITERAL(29, 335, 20), // "receiveCmdFromOrders"
QT_MOC_LITERAL(30, 356, 6), // "memory"
QT_MOC_LITERAL(31, 363, 4) // "flag"

    },
    "Manager\0message\0\0msg\0singleImageProcess\0"
    "ImageName_LightOFF\0ImageName_LightON\0"
    "AutoModeEnd\0getPosition\0camera\0"
    "getCameraImage\0powerOnMotors\0motor\0"
    "powerOffMotors\0manualEnd\0step\0continuous\0"
    "autoEnd\0start\0timerPollDeal\0backToOrigin\0"
    "backToSafeLocation\0isOrigin\0setOriginZero\0"
    "sendVelocity\0inputVec\0setZeroMotorFlags\0"
    "setMotorToPosition\0position\0"
    "receiveCmdFromOrders\0memory\0flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Manager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    2,  112,    2, 0x06 /* Public */,
       7,    0,  117,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,  118,    2, 0x08 /* Private */,
      10,    1,  121,    2, 0x08 /* Private */,
      11,    1,  124,    2, 0x08 /* Private */,
      13,    1,  127,    2, 0x08 /* Private */,
      14,    2,  130,    2, 0x08 /* Private */,
      17,    0,  135,    2, 0x08 /* Private */,
      18,    0,  136,    2, 0x08 /* Private */,
      19,    0,  137,    2, 0x08 /* Private */,
      20,    1,  138,    2, 0x08 /* Private */,
      21,    1,  141,    2, 0x08 /* Private */,
      22,    1,  144,    2, 0x08 /* Private */,
      23,    1,  147,    2, 0x08 /* Private */,
      24,    2,  150,    2, 0x08 /* Private */,
      26,    1,  155,    2, 0x08 /* Private */,
      27,    2,  158,    2, 0x08 /* Private */,
      29,    2,  163,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Bool, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   12,   25,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   12,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   30,   31,

       0        // eod
};

void Manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Manager *_t = static_cast<Manager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->singleImageProcess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->AutoModeEnd(); break;
        case 3: _t->getPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->getCameraImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->powerOnMotors((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->powerOffMotors((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->manualEnd((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 8: _t->autoEnd(); break;
        case 9: _t->start(); break;
        case 10: _t->timerPollDeal(); break;
        case 11: _t->backToOrigin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->backToSafeLocation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: { bool _r = _t->isOrigin((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: _t->setOriginZero((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->sendVelocity((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 16: _t->setZeroMotorFlags((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->setMotorToPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 18: _t->receiveCmdFromOrders((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Manager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Manager::message)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Manager::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Manager::singleImageProcess)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Manager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Manager::AutoModeEnd)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Manager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Manager.data,
      qt_meta_data_Manager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Manager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Manager.stringdata0))
        return static_cast<void*>(const_cast< Manager*>(this));
    return QObject::qt_metacast(_clname);
}

int Manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Manager::message(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Manager::singleImageProcess(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Manager::AutoModeEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
