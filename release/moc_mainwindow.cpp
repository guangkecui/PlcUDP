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
    QByteArrayData data[86];
    char stringdata0[1547];
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
QT_MOC_LITERAL(22, 261, 21), // "sendIsSinglePointShow"
QT_MOC_LITERAL(23, 283, 12), // "isSingleShow"
QT_MOC_LITERAL(24, 296, 27), // "sendThresholdToImageProcess"
QT_MOC_LITERAL(25, 324, 3), // "val"
QT_MOC_LITERAL(26, 328, 7), // "dealMsg"
QT_MOC_LITERAL(27, 336, 16), // "UpdateParameters"
QT_MOC_LITERAL(28, 353, 14), // "receiveMessage"
QT_MOC_LITERAL(29, 368, 3), // "msg"
QT_MOC_LITERAL(30, 372, 31), // "receiveMessageFromManualDiaglog"
QT_MOC_LITERAL(31, 404, 25), // "receiveMessageFromCameras"
QT_MOC_LITERAL(32, 430, 31), // "receiveCommandFromManualDiaglog"
QT_MOC_LITERAL(33, 462, 3), // "cmd"
QT_MOC_LITERAL(34, 466, 3), // "dis"
QT_MOC_LITERAL(35, 470, 3), // "vec"
QT_MOC_LITERAL(36, 474, 12), // "_workingMode"
QT_MOC_LITERAL(37, 487, 28), // "receivePointFromImageProcess"
QT_MOC_LITERAL(38, 516, 15), // "QVector<double>"
QT_MOC_LITERAL(39, 532, 1), // "x"
QT_MOC_LITERAL(40, 534, 1), // "y"
QT_MOC_LITERAL(41, 536, 1), // "z"
QT_MOC_LITERAL(42, 538, 30), // "receiveMessageFromImageProcess"
QT_MOC_LITERAL(43, 569, 30), // "receivePathdFromPicfileDiaglog"
QT_MOC_LITERAL(44, 600, 4), // "path"
QT_MOC_LITERAL(45, 605, 25), // "receiveCmdFromAutoDiaglog"
QT_MOC_LITERAL(46, 631, 11), // "input_motor"
QT_MOC_LITERAL(47, 643, 10), // "input_step"
QT_MOC_LITERAL(48, 654, 21), // "manualDialogDistroyed"
QT_MOC_LITERAL(49, 676, 17), // "autoModeDistroyed"
QT_MOC_LITERAL(50, 694, 22), // "on_StartListen_clicked"
QT_MOC_LITERAL(51, 717, 20), // "on_EndListen_clicked"
QT_MOC_LITERAL(52, 738, 21), // "on_manualMode_clicked"
QT_MOC_LITERAL(53, 760, 19), // "on_autoMode_clicked"
QT_MOC_LITERAL(54, 780, 20), // "on_textClear_clicked"
QT_MOC_LITERAL(55, 801, 15), // "CamerasGetImage"
QT_MOC_LITERAL(56, 817, 3), // "cam"
QT_MOC_LITERAL(57, 821, 26), // "on_actionSetting_triggered"
QT_MOC_LITERAL(58, 848, 32), // "on_actionCameraSetting_triggered"
QT_MOC_LITERAL(59, 881, 20), // "on_ModeStart_clicked"
QT_MOC_LITERAL(60, 902, 29), // "on_actionCameraParm_triggered"
QT_MOC_LITERAL(61, 932, 26), // "on_openPictureFile_clicked"
QT_MOC_LITERAL(62, 959, 23), // "on_startProcess_clicked"
QT_MOC_LITERAL(63, 983, 19), // "on_ModeStop_clicked"
QT_MOC_LITERAL(64, 1003, 25), // "on_BacktoOrigin_1_clicked"
QT_MOC_LITERAL(65, 1029, 25), // "on_BacktoOrigin_2_clicked"
QT_MOC_LITERAL(66, 1055, 25), // "on_BacktoOrigin_3_clicked"
QT_MOC_LITERAL(67, 1081, 25), // "on_BacktoOrigin_4_clicked"
QT_MOC_LITERAL(68, 1107, 27), // "on_BacktoOrigin_all_clicked"
QT_MOC_LITERAL(69, 1135, 21), // "getCmdMotorToPosition"
QT_MOC_LITERAL(70, 1157, 23), // "on_BacktoSafe_1_clicked"
QT_MOC_LITERAL(71, 1181, 23), // "on_BacktoSafe_2_clicked"
QT_MOC_LITERAL(72, 1205, 23), // "on_BacktoSafe_3_clicked"
QT_MOC_LITERAL(73, 1229, 23), // "on_BacktoSafe_4_clicked"
QT_MOC_LITERAL(74, 1253, 25), // "on_BacktoSafe_all_clicked"
QT_MOC_LITERAL(75, 1279, 23), // "on_clearScatter_clicked"
QT_MOC_LITERAL(76, 1303, 24), // "on_motorsPowerOn_clicked"
QT_MOC_LITERAL(77, 1328, 25), // "on_motorsPowerOff_clicked"
QT_MOC_LITERAL(78, 1354, 33), // "on_actionSavePointCloud_trigg..."
QT_MOC_LITERAL(79, 1388, 33), // "on_actionReadPointCloud_trigg..."
QT_MOC_LITERAL(80, 1422, 32), // "on_readLimit_currentIndexChanged"
QT_MOC_LITERAL(81, 1455, 5), // "index"
QT_MOC_LITERAL(82, 1461, 20), // "on_FrontView_clicked"
QT_MOC_LITERAL(83, 1482, 33), // "on_isSinglePointShow_stateCha..."
QT_MOC_LITERAL(84, 1516, 4), // "arg1"
QT_MOC_LITERAL(85, 1521, 25) // "on_threshold_valueChanged"

    },
    "MainWindow\0ImageProcessStart\0\0"
    "ManagerStart\0ManualStart\0ManualEnd\0"
    "step\0continuous\0AutoEnd\0ManagerMotorPowerOn\0"
    "motor\0ManagerMotorPowerOff\0startGetImage\0"
    "camera\0cmdToOrigin\0cmdToSafeLocation\0"
    "setMotorFlagZero\0sendMotorToPosition\0"
    "position\0sendCmdToManger\0memory\0flag\0"
    "sendIsSinglePointShow\0isSingleShow\0"
    "sendThresholdToImageProcess\0val\0dealMsg\0"
    "UpdateParameters\0receiveMessage\0msg\0"
    "receiveMessageFromManualDiaglog\0"
    "receiveMessageFromCameras\0"
    "receiveCommandFromManualDiaglog\0cmd\0"
    "dis\0vec\0_workingMode\0receivePointFromImageProcess\0"
    "QVector<double>\0x\0y\0z\0"
    "receiveMessageFromImageProcess\0"
    "receivePathdFromPicfileDiaglog\0path\0"
    "receiveCmdFromAutoDiaglog\0input_motor\0"
    "input_step\0manualDialogDistroyed\0"
    "autoModeDistroyed\0on_StartListen_clicked\0"
    "on_EndListen_clicked\0on_manualMode_clicked\0"
    "on_autoMode_clicked\0on_textClear_clicked\0"
    "CamerasGetImage\0cam\0on_actionSetting_triggered\0"
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
    "on_readLimit_currentIndexChanged\0index\0"
    "on_FrontView_clicked\0"
    "on_isSinglePointShow_stateChanged\0"
    "arg1\0on_threshold_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      60,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  314,    2, 0x06 /* Public */,
       3,    0,  315,    2, 0x06 /* Public */,
       4,    0,  316,    2, 0x06 /* Public */,
       5,    2,  317,    2, 0x06 /* Public */,
       8,    0,  322,    2, 0x06 /* Public */,
       9,    1,  323,    2, 0x06 /* Public */,
      11,    1,  326,    2, 0x06 /* Public */,
      12,    1,  329,    2, 0x06 /* Public */,
      14,    1,  332,    2, 0x06 /* Public */,
      15,    1,  335,    2, 0x06 /* Public */,
      16,    1,  338,    2, 0x06 /* Public */,
      17,    2,  341,    2, 0x06 /* Public */,
      19,    2,  346,    2, 0x06 /* Public */,
      22,    1,  351,    2, 0x06 /* Public */,
      24,    1,  354,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      26,    0,  357,    2, 0x08 /* Private */,
      27,    0,  358,    2, 0x08 /* Private */,
      28,    1,  359,    2, 0x08 /* Private */,
      30,    1,  362,    2, 0x08 /* Private */,
      31,    1,  365,    2, 0x08 /* Private */,
      32,    5,  368,    2, 0x08 /* Private */,
      37,    3,  379,    2, 0x08 /* Private */,
      42,    1,  386,    2, 0x08 /* Private */,
      43,    1,  389,    2, 0x08 /* Private */,
      45,    2,  392,    2, 0x08 /* Private */,
      48,    0,  397,    2, 0x08 /* Private */,
      49,    0,  398,    2, 0x08 /* Private */,
      50,    0,  399,    2, 0x08 /* Private */,
      51,    0,  400,    2, 0x08 /* Private */,
      52,    0,  401,    2, 0x08 /* Private */,
      53,    0,  402,    2, 0x08 /* Private */,
      54,    0,  403,    2, 0x08 /* Private */,
      55,    1,  404,    2, 0x08 /* Private */,
      57,    0,  407,    2, 0x08 /* Private */,
      58,    0,  408,    2, 0x08 /* Private */,
      59,    0,  409,    2, 0x08 /* Private */,
      60,    0,  410,    2, 0x08 /* Private */,
      61,    0,  411,    2, 0x08 /* Private */,
      62,    0,  412,    2, 0x08 /* Private */,
      63,    0,  413,    2, 0x08 /* Private */,
      64,    0,  414,    2, 0x08 /* Private */,
      65,    0,  415,    2, 0x08 /* Private */,
      66,    0,  416,    2, 0x08 /* Private */,
      67,    0,  417,    2, 0x08 /* Private */,
      68,    0,  418,    2, 0x08 /* Private */,
      69,    2,  419,    2, 0x08 /* Private */,
      70,    0,  424,    2, 0x08 /* Private */,
      71,    0,  425,    2, 0x08 /* Private */,
      72,    0,  426,    2, 0x08 /* Private */,
      73,    0,  427,    2, 0x08 /* Private */,
      74,    0,  428,    2, 0x08 /* Private */,
      75,    0,  429,    2, 0x08 /* Private */,
      76,    0,  430,    2, 0x08 /* Private */,
      77,    0,  431,    2, 0x08 /* Private */,
      78,    0,  432,    2, 0x08 /* Private */,
      79,    0,  433,    2, 0x08 /* Private */,
      80,    1,  434,    2, 0x08 /* Private */,
      82,    0,  437,    2, 0x08 /* Private */,
      83,    1,  438,    2, 0x08 /* Private */,
      85,    1,  441,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Int,   25,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int,   33,   34,   35,   36,   10,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 38, 0x80000000 | 38,   39,   40,   41,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString,   44,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   46,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,   56,
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
    QMetaType::Void, QMetaType::Int,   81,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   84,
    QMetaType::Void, QMetaType::Int,   84,

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
        case 13: _t->sendIsSinglePointShow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->sendThresholdToImageProcess((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->dealMsg(); break;
        case 16: _t->UpdateParameters(); break;
        case 17: _t->receiveMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->receiveMessageFromManualDiaglog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->receiveMessageFromCameras((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->receiveCommandFromManualDiaglog((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 21: _t->receivePointFromImageProcess((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 22: _t->receiveMessageFromImageProcess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->receivePathdFromPicfileDiaglog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->receiveCmdFromAutoDiaglog((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 25: _t->manualDialogDistroyed(); break;
        case 26: _t->autoModeDistroyed(); break;
        case 27: _t->on_StartListen_clicked(); break;
        case 28: _t->on_EndListen_clicked(); break;
        case 29: _t->on_manualMode_clicked(); break;
        case 30: _t->on_autoMode_clicked(); break;
        case 31: _t->on_textClear_clicked(); break;
        case 32: _t->CamerasGetImage((*reinterpret_cast< uchar(*)>(_a[1]))); break;
        case 33: _t->on_actionSetting_triggered(); break;
        case 34: _t->on_actionCameraSetting_triggered(); break;
        case 35: _t->on_ModeStart_clicked(); break;
        case 36: _t->on_actionCameraParm_triggered(); break;
        case 37: _t->on_openPictureFile_clicked(); break;
        case 38: _t->on_startProcess_clicked(); break;
        case 39: _t->on_ModeStop_clicked(); break;
        case 40: _t->on_BacktoOrigin_1_clicked(); break;
        case 41: _t->on_BacktoOrigin_2_clicked(); break;
        case 42: _t->on_BacktoOrigin_3_clicked(); break;
        case 43: _t->on_BacktoOrigin_4_clicked(); break;
        case 44: _t->on_BacktoOrigin_all_clicked(); break;
        case 45: _t->getCmdMotorToPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 46: _t->on_BacktoSafe_1_clicked(); break;
        case 47: _t->on_BacktoSafe_2_clicked(); break;
        case 48: _t->on_BacktoSafe_3_clicked(); break;
        case 49: _t->on_BacktoSafe_4_clicked(); break;
        case 50: _t->on_BacktoSafe_all_clicked(); break;
        case 51: _t->on_clearScatter_clicked(); break;
        case 52: _t->on_motorsPowerOn_clicked(); break;
        case 53: _t->on_motorsPowerOff_clicked(); break;
        case 54: _t->on_actionSavePointCloud_triggered(); break;
        case 55: _t->on_actionReadPointCloud_triggered(); break;
        case 56: _t->on_readLimit_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->on_FrontView_clicked(); break;
        case 58: _t->on_isSinglePointShow_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->on_threshold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
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
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendIsSinglePointShow)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendThresholdToImageProcess)) {
                *result = 14;
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
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
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

// SIGNAL 13
void MainWindow::sendIsSinglePointShow(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainWindow::sendThresholdToImageProcess(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_END_MOC_NAMESPACE
