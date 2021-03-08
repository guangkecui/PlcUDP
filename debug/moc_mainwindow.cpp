/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[75];
    char stringdata0[1345];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "ImageProcessStart"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "ManagerStart"
QT_MOC_LITERAL(4, 43, 11), // "ManualStart"
QT_MOC_LITERAL(5, 55, 9), // "ManualEnd"
QT_MOC_LITERAL(6, 65, 4), // "step"
QT_MOC_LITERAL(7, 70, 10), // "continuous"
QT_MOC_LITERAL(8, 81, 7), // "AutoEnd"
QT_MOC_LITERAL(9, 89, 19), // "ManagerMotorPowerOn"
QT_MOC_LITERAL(10, 109, 5), // "motor"
QT_MOC_LITERAL(11, 115, 20), // "ManagerMotorPowerOff"
QT_MOC_LITERAL(12, 136, 13), // "startGetImage"
QT_MOC_LITERAL(13, 150, 6), // "camera"
QT_MOC_LITERAL(14, 157, 11), // "cmdToOrigin"
QT_MOC_LITERAL(15, 169, 17), // "cmdToSafeLocation"
QT_MOC_LITERAL(16, 187, 16), // "setMotorFlagZero"
QT_MOC_LITERAL(17, 204, 19), // "sendMotorToPosition"
QT_MOC_LITERAL(18, 224, 8), // "position"
QT_MOC_LITERAL(19, 233, 15), // "sendCmdToManger"
QT_MOC_LITERAL(20, 249, 6), // "memory"
QT_MOC_LITERAL(21, 256, 4), // "flag"
QT_MOC_LITERAL(22, 261, 7), // "dealMsg"
QT_MOC_LITERAL(23, 269, 16), // "UpdateParameters"
QT_MOC_LITERAL(24, 286, 14), // "receiveMessage"
QT_MOC_LITERAL(25, 301, 3), // "msg"
QT_MOC_LITERAL(26, 305, 31), // "receiveMessageFromManualDiaglog"
QT_MOC_LITERAL(27, 337, 25), // "receiveMessageFromCameras"
QT_MOC_LITERAL(28, 363, 31), // "receiveCommandFromManualDiaglog"
QT_MOC_LITERAL(29, 395, 3), // "cmd"
QT_MOC_LITERAL(30, 399, 3), // "dis"
QT_MOC_LITERAL(31, 403, 3), // "vec"
QT_MOC_LITERAL(32, 407, 12), // "_workingMode"
QT_MOC_LITERAL(33, 420, 28), // "receivePointFromImageProcess"
QT_MOC_LITERAL(34, 449, 15), // "QVector<double>"
QT_MOC_LITERAL(35, 465, 1), // "x"
QT_MOC_LITERAL(36, 467, 1), // "y"
QT_MOC_LITERAL(37, 469, 1), // "z"
QT_MOC_LITERAL(38, 471, 30), // "receiveMessageFromImageProcess"
QT_MOC_LITERAL(39, 502, 30), // "receivePathdFromPicfileDiaglog"
QT_MOC_LITERAL(40, 533, 4), // "path"
QT_MOC_LITERAL(41, 538, 21), // "manualDialogDistroyed"
QT_MOC_LITERAL(42, 560, 17), // "autoModeDistroyed"
QT_MOC_LITERAL(43, 578, 22), // "on_StartListen_clicked"
QT_MOC_LITERAL(44, 601, 20), // "on_EndListen_clicked"
QT_MOC_LITERAL(45, 622, 21), // "on_manualMode_clicked"
QT_MOC_LITERAL(46, 644, 19), // "on_autoMode_clicked"
QT_MOC_LITERAL(47, 664, 20), // "on_textClear_clicked"
QT_MOC_LITERAL(48, 685, 15), // "CamerasGetImage"
QT_MOC_LITERAL(49, 701, 3), // "cam"
QT_MOC_LITERAL(50, 705, 26), // "on_actionSetting_triggered"
QT_MOC_LITERAL(51, 732, 32), // "on_actionCameraSetting_triggered"
QT_MOC_LITERAL(52, 765, 20), // "on_ModeStart_clicked"
QT_MOC_LITERAL(53, 786, 29), // "on_actionCameraParm_triggered"
QT_MOC_LITERAL(54, 816, 26), // "on_openPictureFile_clicked"
QT_MOC_LITERAL(55, 843, 23), // "on_startProcess_clicked"
QT_MOC_LITERAL(56, 867, 19), // "on_ModeStop_clicked"
QT_MOC_LITERAL(57, 887, 25), // "on_BacktoOrigin_1_clicked"
QT_MOC_LITERAL(58, 913, 25), // "on_BacktoOrigin_2_clicked"
QT_MOC_LITERAL(59, 939, 25), // "on_BacktoOrigin_3_clicked"
QT_MOC_LITERAL(60, 965, 25), // "on_BacktoOrigin_4_clicked"
QT_MOC_LITERAL(61, 991, 27), // "on_BacktoOrigin_all_clicked"
QT_MOC_LITERAL(62, 1019, 21), // "getCmdMotorToPosition"
QT_MOC_LITERAL(63, 1041, 23), // "on_BacktoSafe_1_clicked"
QT_MOC_LITERAL(64, 1065, 23), // "on_BacktoSafe_2_clicked"
QT_MOC_LITERAL(65, 1089, 23), // "on_BacktoSafe_3_clicked"
QT_MOC_LITERAL(66, 1113, 23), // "on_BacktoSafe_4_clicked"
QT_MOC_LITERAL(67, 1137, 25), // "on_BacktoSafe_all_clicked"
QT_MOC_LITERAL(68, 1163, 23), // "on_clearScatter_clicked"
QT_MOC_LITERAL(69, 1187, 24), // "on_motorsPowerOn_clicked"
QT_MOC_LITERAL(70, 1212, 25), // "on_motorsPowerOff_clicked"
QT_MOC_LITERAL(71, 1238, 33), // "on_actionSavePointCloud_trigg..."
QT_MOC_LITERAL(72, 1272, 33), // "on_actionReadPointCloud_trigg..."
QT_MOC_LITERAL(73, 1306, 32), // "on_readLimit_currentIndexChanged"
QT_MOC_LITERAL(74, 1339, 5) // "index"

    },
    "MainWindow\0ImageProcessStart\0\0"
    "ManagerStart\0ManualStart\0ManualEnd\0"
    "step\0continuous\0AutoEnd\0ManagerMotorPowerOn\0"
    "motor\0ManagerMotorPowerOff\0startGetImage\0"
    "camera\0cmdToOrigin\0cmdToSafeLocation\0"
    "setMotorFlagZero\0sendMotorToPosition\0"
    "position\0sendCmdToManger\0memory\0flag\0"
    "dealMsg\0UpdateParameters\0receiveMessage\0"
    "msg\0receiveMessageFromManualDiaglog\0"
    "receiveMessageFromCameras\0"
    "receiveCommandFromManualDiaglog\0cmd\0"
    "dis\0vec\0_workingMode\0receivePointFromImageProcess\0"
    "QVector<double>\0x\0y\0z\0"
    "receiveMessageFromImageProcess\0"
    "receivePathdFromPicfileDiaglog\0path\0"
    "manualDialogDistroyed\0autoModeDistroyed\0"
    "on_StartListen_clicked\0on_EndListen_clicked\0"
    "on_manualMode_clicked\0on_autoMode_clicked\0"
    "on_textClear_clicked\0CamerasGetImage\0"
    "cam\0on_actionSetting_triggered\0"
    "on_actionCameraSetting_triggered\0"
    "on_ModeStart_clicked\0on_actionCameraParm_triggered\0"
    "on_openPictureFile_clicked\0"
    "on_startProcess_clicked\0on_ModeStop_clicked\0"
    "on_BacktoOrigin_1_clicked\0"
    "on_BacktoOrigin_2_clicked\0"
    "on_BacktoOrigin_3_clicked\0"
    "on_BacktoOrigin_4_clicked\0"
    "on_BacktoOrigin_all_clicked\0"
    "getCmdMotorToPosition\0on_BacktoSafe_1_clicked\0"
    "on_BacktoSafe_2_clicked\0on_BacktoSafe_3_clicked\0"
    "on_BacktoSafe_4_clicked\0"
    "on_BacktoSafe_all_clicked\0"
    "on_clearScatter_clicked\0"
    "on_motorsPowerOn_clicked\0"
    "on_motorsPowerOff_clicked\0"
    "on_actionSavePointCloud_triggered\0"
    "on_actionReadPointCloud_triggered\0"
    "on_readLimit_currentIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      54,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  284,    2, 0x06 /* Public */,
       3,    0,  285,    2, 0x06 /* Public */,
       4,    0,  286,    2, 0x06 /* Public */,
       5,    2,  287,    2, 0x06 /* Public */,
       8,    0,  292,    2, 0x06 /* Public */,
       9,    1,  293,    2, 0x06 /* Public */,
      11,    1,  296,    2, 0x06 /* Public */,
      12,    1,  299,    2, 0x06 /* Public */,
      14,    1,  302,    2, 0x06 /* Public */,
      15,    1,  305,    2, 0x06 /* Public */,
      16,    1,  308,    2, 0x06 /* Public */,
      17,    2,  311,    2, 0x06 /* Public */,
      19,    2,  316,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    0,  321,    2, 0x08 /* Private */,
      23,    0,  322,    2, 0x08 /* Private */,
      24,    1,  323,    2, 0x08 /* Private */,
      26,    1,  326,    2, 0x08 /* Private */,
      27,    1,  329,    2, 0x08 /* Private */,
      28,    5,  332,    2, 0x08 /* Private */,
      33,    3,  343,    2, 0x08 /* Private */,
      38,    1,  350,    2, 0x08 /* Private */,
      39,    1,  353,    2, 0x08 /* Private */,
      41,    0,  356,    2, 0x08 /* Private */,
      42,    0,  357,    2, 0x08 /* Private */,
      43,    0,  358,    2, 0x08 /* Private */,
      44,    0,  359,    2, 0x08 /* Private */,
      45,    0,  360,    2, 0x08 /* Private */,
      46,    0,  361,    2, 0x08 /* Private */,
      47,    0,  362,    2, 0x08 /* Private */,
      48,    1,  363,    2, 0x08 /* Private */,
      50,    0,  366,    2, 0x08 /* Private */,
      51,    0,  367,    2, 0x08 /* Private */,
      52,    0,  368,    2, 0x08 /* Private */,
      53,    0,  369,    2, 0x08 /* Private */,
      54,    0,  370,    2, 0x08 /* Private */,
      55,    0,  371,    2, 0x08 /* Private */,
      56,    0,  372,    2, 0x08 /* Private */,
      57,    0,  373,    2, 0x08 /* Private */,
      58,    0,  374,    2, 0x08 /* Private */,
      59,    0,  375,    2, 0x08 /* Private */,
      60,    0,  376,    2, 0x08 /* Private */,
      61,    0,  377,    2, 0x08 /* Private */,
      62,    2,  378,    2, 0x08 /* Private */,
      63,    0,  383,    2, 0x08 /* Private */,
      64,    0,  384,    2, 0x08 /* Private */,
      65,    0,  385,    2, 0x08 /* Private */,
      66,    0,  386,    2, 0x08 /* Private */,
      67,    0,  387,    2, 0x08 /* Private */,
      68,    0,  388,    2, 0x08 /* Private */,
      69,    0,  389,    2, 0x08 /* Private */,
      70,    0,  390,    2, 0x08 /* Private */,
      71,    0,  391,    2, 0x08 /* Private */,
      72,    0,  392,    2, 0x08 /* Private */,
      73,    1,  393,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   10,   18,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   20,   21,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int,   29,   30,   31,   32,   10,
    QMetaType::Void, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34,   35,   36,   37,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,   49,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   10,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   74,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ImageProcessStart(); break;
        case 1: _t->ManagerStart(); break;
        case 2: _t->ManualStart(); break;
        case 3: _t->ManualEnd((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 4: _t->AutoEnd(); break;
        case 5: _t->ManagerMotorPowerOn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->ManagerMotorPowerOff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->startGetImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->cmdToOrigin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->cmdToSafeLocation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setMotorFlagZero((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->sendMotorToPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 12: _t->sendCmdToManger((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->dealMsg(); break;
        case 14: _t->UpdateParameters(); break;
        case 15: _t->receiveMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->receiveMessageFromManualDiaglog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->receiveMessageFromCameras((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->receiveCommandFromManualDiaglog((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 19: _t->receivePointFromImageProcess((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 20: _t->receiveMessageFromImageProcess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->receivePathdFromPicfileDiaglog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->manualDialogDistroyed(); break;
        case 23: _t->autoModeDistroyed(); break;
        case 24: _t->on_StartListen_clicked(); break;
        case 25: _t->on_EndListen_clicked(); break;
        case 26: _t->on_manualMode_clicked(); break;
        case 27: _t->on_autoMode_clicked(); break;
        case 28: _t->on_textClear_clicked(); break;
        case 29: _t->CamerasGetImage((*reinterpret_cast< uchar(*)>(_a[1]))); break;
        case 30: _t->on_actionSetting_triggered(); break;
        case 31: _t->on_actionCameraSetting_triggered(); break;
        case 32: _t->on_ModeStart_clicked(); break;
        case 33: _t->on_actionCameraParm_triggered(); break;
        case 34: _t->on_openPictureFile_clicked(); break;
        case 35: _t->on_startProcess_clicked(); break;
        case 36: _t->on_ModeStop_clicked(); break;
        case 37: _t->on_BacktoOrigin_1_clicked(); break;
        case 38: _t->on_BacktoOrigin_2_clicked(); break;
        case 39: _t->on_BacktoOrigin_3_clicked(); break;
        case 40: _t->on_BacktoOrigin_4_clicked(); break;
        case 41: _t->on_BacktoOrigin_all_clicked(); break;
        case 42: _t->getCmdMotorToPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 43: _t->on_BacktoSafe_1_clicked(); break;
        case 44: _t->on_BacktoSafe_2_clicked(); break;
        case 45: _t->on_BacktoSafe_3_clicked(); break;
        case 46: _t->on_BacktoSafe_4_clicked(); break;
        case 47: _t->on_BacktoSafe_all_clicked(); break;
        case 48: _t->on_clearScatter_clicked(); break;
        case 49: _t->on_motorsPowerOn_clicked(); break;
        case 50: _t->on_motorsPowerOff_clicked(); break;
        case 51: _t->on_actionSavePointCloud_triggered(); break;
        case 52: _t->on_actionReadPointCloud_triggered(); break;
        case 53: _t->on_readLimit_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 19:
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
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::ImageProcessStart)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::ManagerStart)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::ManualStart)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QByteArray , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::ManualEnd)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::AutoEnd)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::ManagerMotorPowerOn)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::ManagerMotorPowerOff)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::startGetImage)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::cmdToOrigin)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::cmdToSafeLocation)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::setMotorFlagZero)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendMotorToPosition)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendCmdToManger)) {
                *result = 12;
                return;
            }
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
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::ImageProcessStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::ManagerStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::ManualStart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::ManualEnd(QByteArray _t1, QByteArray _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::AutoEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainWindow::ManagerMotorPowerOn(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::ManagerMotorPowerOff(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::startGetImage(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::cmdToOrigin(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::cmdToSafeLocation(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::setMotorFlagZero(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MainWindow::sendMotorToPosition(int _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MainWindow::sendCmdToManger(QString _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_END_MOC_NAMESPACE
