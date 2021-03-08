#-------------------------------------------------
#
# Project created by QtCreator 2020-07-30T20:14:13
#
#-------------------------------------------------

QT       += core gui network datavisualization widgets
RC_ICONS = ./resource/myico.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlcUDP
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

Debug {
    contains(QMAKE_COMPILER_DEFINES, _WIN64) {
        #LIBS += -L./Depends/x64/vs2013shared -lMVSDKmd
        #LIBS += -L./Depends/x64/vs2013shared -lImageConvert
    }
    else {
        LIBS += -L./Depends/win32/vs2013shared -lMVSDKmd
        LIBS += -L./Depends/win32/vs2013shared -lImageConvert
    }
}
else {
    contains(QMAKE_COMPILER_DEFINES, _WIN64) {
        LIBS += -L./Depends/x64/vs2013shared -lMVSDKmd
        LIBS += -L./Depends/x64/vs2013shared -lImageConvert
    }
    else {
        LIBS += -L./Depends/win32/vs2013shared -lMVSDKmd
        LIBS += -L./Depends/win32/vs2013shared -lImageConvert
    }
}
INCLUDEPATH += ./Include

INCLUDEPATH += E:\software\opencv\opencv410\build_64\install\include
               E:\software\opencv\opencv410\build_64\install\include\opencv2

SOURCES += main.cpp\
        mainwindow.cpp \
    fins.cpp \
    ifinscommand.cpp \
    udpfinscommand.cpp \
    abstractmode.cpp \
    motor.cpp \
    motorunit.cpp \
    manualmode.cpp \
    automaticmode.cpp \
    mode.cpp \
    cammerwidget.cpp \
    setcamerasprtwidget.cpp \
    cameras.cpp \
    onecamera.cpp \
    parametersetting.cpp \
    manualmodedialog.cpp \
    sensordata.cpp \
    cameradata.cpp \
    sensorunit.cpp \
    readsensorsdialog.cpp \
    manager.cpp \
    imageproce.cpp \
    findpicfile.cpp

HEADERS  += mainwindow.h \
    fins.h \
    ifinscommand.h \
    udpfinscommand.h \
    abstractmode.h \
    motor.h \
    motorunit.h \
    manualmode.h \
    automaticmode.h \
    mode.h \
    MessageQue.h \
    cammerwidget.h \
    setcamerasprtwidget.h \
    cameras.h \
    onecamera.h \
    parametersetting.h \
    omronpst.h \
    manualmodedialog.h \
    sensordata.h \
    cameradata.h \
    sensorunit.h \
    readsensorsdialog.h \
    manager.h \
    imageproce.h \
    findpicfile.h

FORMS    += mainwindow.ui \
    cammerwidget.ui \
    setcamerasprtwidget.ui \
    parametersetting.ui \
    manualmodedialog.ui \
    readsensorsdialog.ui \
    findpicfile.ui

DISTFILES +=

RESOURCES += \
    motor.qrc

win32:CONFIG(release, debug|release): LIBS += -LE:/software/opencv/opencv410/build_64/install/x64/vc14/lib/ -lopencv_world410
else:win32:CONFIG(debug, debug|release): LIBS += -LE:/software/opencv/opencv410/build_64/install/x64/vc14/lib/ -lopencv_world410d

INCLUDEPATH += E:/software/opencv/opencv410/build_64/install/x64/vc14
DEPENDPATH += E:/software/opencv/opencv410/build_64/install/x64/vc14


win32: LIBS += -L$$PWD/Depends/x64/vs2013shared/ -lMVSDKmd

INCLUDEPATH += $$PWD/Depends/x64/vs2013shared
DEPENDPATH += $$PWD/Depends/x64/vs2013shared

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/Depends/x64/vs2013shared/MVSDKmd.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/Depends/x64/vs2013shared/libMVSDKmd.a

win32: LIBS += -L$$PWD/Depends/x64/vs2013shared/ -lImageConvert

INCLUDEPATH += $$PWD/Depends/x64/vs2013shared
DEPENDPATH += $$PWD/Depends/x64/vs2013shared

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/Depends/x64/vs2013shared/ImageConvert.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/Depends/x64/vs2013shared/libImageConvert.a
