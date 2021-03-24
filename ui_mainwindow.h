/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSetting;
    QAction *actionCameraSetting;
    QAction *actionCameraParm;
    QAction *actionSavePointCloud;
    QAction *actionReadPointCloud;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *textClear;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit_Msg;
    QHBoxLayout *horizontalLayout;
    QPushButton *openPictureFile;
    QPushButton *clearScatter;
    QPushButton *FrontView;
    QPushButton *startProcess;
    QWidget *showScatter;
    QWidget *widget_2;
    QPushButton *ModeStart;
    QPushButton *StartListen;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QRadioButton *manualMode;
    QRadioButton *autoMode;
    QLabel *label_11;
    QLabel *label_9;
    QPushButton *EndListen;
    QPushButton *ModeStop;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QPushButton *BacktoOrigin_1;
    QPushButton *BacktoOrigin_2;
    QPushButton *BacktoOrigin_3;
    QPushButton *BacktoOrigin_4;
    QPushButton *BacktoOrigin_all;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_4;
    QPushButton *BacktoSafe_1;
    QPushButton *BacktoSafe_2;
    QPushButton *BacktoSafe_3;
    QPushButton *BacktoSafe_4;
    QPushButton *BacktoSafe_all;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *motorsPowerOn;
    QPushButton *motorsPowerOff;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *readLimit;
    QCheckBox *isSinglePointShow;
    QLabel *label;
    QSpinBox *threshold;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1177, 803);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(63,63,70);\n"
"color: rgb(255, 255, 255);"));
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockNestingEnabled(false);
        actionSetting = new QAction(MainWindow);
        actionSetting->setObjectName(QStringLiteral("actionSetting"));
        actionCameraSetting = new QAction(MainWindow);
        actionCameraSetting->setObjectName(QStringLiteral("actionCameraSetting"));
        actionCameraParm = new QAction(MainWindow);
        actionCameraParm->setObjectName(QStringLiteral("actionCameraParm"));
        actionSavePointCloud = new QAction(MainWindow);
        actionSavePointCloud->setObjectName(QStringLiteral("actionSavePointCloud"));
        actionReadPointCloud = new QAction(MainWindow);
        actionReadPointCloud->setObjectName(QStringLiteral("actionReadPointCloud"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textClear = new QPushButton(centralWidget);
        textClear->setObjectName(QStringLiteral("textClear"));
        textClear->setMinimumSize(QSize(300, 20));
        textClear->setMaximumSize(QSize(300, 20));
        textClear->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout->addWidget(textClear, 1, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit_Msg = new QTextEdit(centralWidget);
        textEdit_Msg->setObjectName(QStringLiteral("textEdit_Msg"));
        textEdit_Msg->setMinimumSize(QSize(300, 636));
        textEdit_Msg->setMaximumSize(QSize(300, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft New Tai Lue"));
        font.setPointSize(10);
        font.setKerning(true);
        textEdit_Msg->setFont(font);
        textEdit_Msg->setStyleSheet(QLatin1String("background-color: rgb(30,30,30);\n"
"color: rgb(255, 255, 255);"));
        textEdit_Msg->setReadOnly(true);

        verticalLayout->addWidget(textEdit_Msg);


        gridLayout->addLayout(verticalLayout, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        openPictureFile = new QPushButton(centralWidget);
        openPictureFile->setObjectName(QStringLiteral("openPictureFile"));
        openPictureFile->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        horizontalLayout->addWidget(openPictureFile);

        clearScatter = new QPushButton(centralWidget);
        clearScatter->setObjectName(QStringLiteral("clearScatter"));
        clearScatter->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        horizontalLayout->addWidget(clearScatter);

        FrontView = new QPushButton(centralWidget);
        FrontView->setObjectName(QStringLiteral("FrontView"));
        FrontView->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        horizontalLayout->addWidget(FrontView);

        startProcess = new QPushButton(centralWidget);
        startProcess->setObjectName(QStringLiteral("startProcess"));
        startProcess->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        horizontalLayout->addWidget(startProcess);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        showScatter = new QWidget(centralWidget);
        showScatter->setObjectName(QStringLiteral("showScatter"));
        showScatter->setMinimumSize(QSize(581, 581));
        showScatter->setStyleSheet(QStringLiteral("background-color: rgb(30, 30, 30);"));

        gridLayout->addWidget(showScatter, 0, 1, 1, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(231, 701));
        widget_2->setStyleSheet(QLatin1String("background-color: rgb(30,30,30);\n"
"border-top-color: rgb(255, 255, 255);"));
        ModeStart = new QPushButton(widget_2);
        ModeStart->setObjectName(QStringLiteral("ModeStart"));
        ModeStart->setGeometry(QRect(10, 150, 211, 41));
        ModeStart->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        StartListen = new QPushButton(widget_2);
        StartListen->setObjectName(QStringLiteral("StartListen"));
        StartListen->setGeometry(QRect(10, 10, 100, 50));
        StartListen->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        layoutWidget = new QWidget(widget_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 70, 211, 71));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        manualMode = new QRadioButton(layoutWidget);
        manualMode->setObjectName(QStringLiteral("manualMode"));
        QFont font1;
        font1.setPointSize(11);
        manualMode->setFont(font1);
        manualMode->setIconSize(QSize(16, 16));

        gridLayout_2->addWidget(manualMode, 0, 1, 1, 1);

        autoMode = new QRadioButton(layoutWidget);
        autoMode->setObjectName(QStringLiteral("autoMode"));
        autoMode->setFont(font1);
        autoMode->setIconSize(QSize(16, 16));

        gridLayout_2->addWidget(autoMode, 1, 1, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 1, 2, 1, 1);

        EndListen = new QPushButton(widget_2);
        EndListen->setObjectName(QStringLiteral("EndListen"));
        EndListen->setGeometry(QRect(120, 10, 100, 50));
        EndListen->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        ModeStop = new QPushButton(widget_2);
        ModeStop->setObjectName(QStringLiteral("ModeStop"));
        ModeStop->setGeometry(QRect(10, 202, 211, 41));
        ModeStop->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 270, 211, 151));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 191, 111));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        BacktoOrigin_1 = new QPushButton(verticalLayoutWidget);
        BacktoOrigin_1->setObjectName(QStringLiteral("BacktoOrigin_1"));
        BacktoOrigin_1->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout_3->addWidget(BacktoOrigin_1, 0, 0, 1, 1);

        BacktoOrigin_2 = new QPushButton(verticalLayoutWidget);
        BacktoOrigin_2->setObjectName(QStringLiteral("BacktoOrigin_2"));
        BacktoOrigin_2->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout_3->addWidget(BacktoOrigin_2, 0, 1, 1, 1);

        BacktoOrigin_3 = new QPushButton(verticalLayoutWidget);
        BacktoOrigin_3->setObjectName(QStringLiteral("BacktoOrigin_3"));
        BacktoOrigin_3->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout_3->addWidget(BacktoOrigin_3, 1, 0, 1, 1);

        BacktoOrigin_4 = new QPushButton(verticalLayoutWidget);
        BacktoOrigin_4->setObjectName(QStringLiteral("BacktoOrigin_4"));
        BacktoOrigin_4->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout_3->addWidget(BacktoOrigin_4, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        BacktoOrigin_all = new QPushButton(verticalLayoutWidget);
        BacktoOrigin_all->setObjectName(QStringLiteral("BacktoOrigin_all"));
        BacktoOrigin_all->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        verticalLayout_2->addWidget(BacktoOrigin_all);

        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 440, 211, 151));
        verticalLayoutWidget_2 = new QWidget(groupBox_2);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 191, 111));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        BacktoSafe_1 = new QPushButton(verticalLayoutWidget_2);
        BacktoSafe_1->setObjectName(QStringLiteral("BacktoSafe_1"));
        BacktoSafe_1->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout_4->addWidget(BacktoSafe_1, 0, 0, 1, 1);

        BacktoSafe_2 = new QPushButton(verticalLayoutWidget_2);
        BacktoSafe_2->setObjectName(QStringLiteral("BacktoSafe_2"));
        BacktoSafe_2->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout_4->addWidget(BacktoSafe_2, 0, 1, 1, 1);

        BacktoSafe_3 = new QPushButton(verticalLayoutWidget_2);
        BacktoSafe_3->setObjectName(QStringLiteral("BacktoSafe_3"));
        BacktoSafe_3->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout_4->addWidget(BacktoSafe_3, 1, 0, 1, 1);

        BacktoSafe_4 = new QPushButton(verticalLayoutWidget_2);
        BacktoSafe_4->setObjectName(QStringLiteral("BacktoSafe_4"));
        BacktoSafe_4->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout_4->addWidget(BacktoSafe_4, 1, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_4);

        BacktoSafe_all = new QPushButton(verticalLayoutWidget_2);
        BacktoSafe_all->setObjectName(QStringLiteral("BacktoSafe_all"));
        BacktoSafe_all->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        verticalLayout_3->addWidget(BacktoSafe_all);

        groupBox_3 = new QGroupBox(widget_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 600, 211, 91));
        verticalLayoutWidget_3 = new QWidget(groupBox_3);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 191, 61));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        motorsPowerOn = new QPushButton(verticalLayoutWidget_3);
        motorsPowerOn->setObjectName(QStringLiteral("motorsPowerOn"));
        motorsPowerOn->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        verticalLayout_4->addWidget(motorsPowerOn);

        motorsPowerOff = new QPushButton(verticalLayoutWidget_3);
        motorsPowerOff->setObjectName(QStringLiteral("motorsPowerOff"));
        motorsPowerOff->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        verticalLayout_4->addWidget(motorsPowerOff);


        gridLayout->addWidget(widget_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        readLimit = new QComboBox(centralWidget);
        readLimit->setObjectName(QStringLiteral("readLimit"));
        readLimit->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"selection-color: rgb(0, 170, 0);\n"
""));

        horizontalLayout_3->addWidget(readLimit);

        isSinglePointShow = new QCheckBox(centralWidget);
        isSinglePointShow->setObjectName(QStringLiteral("isSinglePointShow"));

        horizontalLayout_3->addWidget(isSinglePointShow);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        threshold = new QSpinBox(centralWidget);
        threshold->setObjectName(QStringLiteral("threshold"));
        threshold->setMaximum(255);
        threshold->setValue(200);

        horizontalLayout_3->addWidget(threshold);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1177, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(actionSetting);
        menu->addAction(actionCameraSetting);
        menu_2->addAction(actionCameraParm);
        menu_2->addAction(actionSavePointCloud);
        menu_2->addAction(actionReadPointCloud);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionSetting->setText(QApplication::translate("MainWindow", "Setting", Q_NULLPTR));
        actionCameraSetting->setText(QApplication::translate("MainWindow", "CameraSetting", Q_NULLPTR));
        actionCameraParm->setText(QApplication::translate("MainWindow", "ReadSensors", Q_NULLPTR));
        actionSavePointCloud->setText(QApplication::translate("MainWindow", "SavePointCloud", Q_NULLPTR));
        actionReadPointCloud->setText(QApplication::translate("MainWindow", "ReadPointCloud", Q_NULLPTR));
        textClear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        openPictureFile->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251", Q_NULLPTR));
        clearScatter->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        FrontView->setText(QApplication::translate("MainWindow", "\346\255\243\350\247\206", Q_NULLPTR));
        startProcess->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        ModeStart->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        StartListen->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245PLC", Q_NULLPTR));
        manualMode->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\346\250\241\345\274\217", Q_NULLPTR));
        autoMode->setText(QApplication::translate("MainWindow", "\350\207\252\346\216\247\346\250\241\345\274\217", Q_NULLPTR));
        label_11->setText(QString());
        label_9->setText(QString());
        EndListen->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200PLC", Q_NULLPTR));
        ModeStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\233\236\345\216\237\347\202\271", Q_NULLPTR));
        BacktoOrigin_1->setText(QApplication::translate("MainWindow", "1\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        BacktoOrigin_2->setText(QApplication::translate("MainWindow", "2\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        BacktoOrigin_3->setText(QApplication::translate("MainWindow", "3\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        BacktoOrigin_4->setText(QApplication::translate("MainWindow", "4\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        BacktoOrigin_all->setText(QApplication::translate("MainWindow", "\345\205\250\351\203\250\345\233\236\345\216\237\347\202\271", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\233\236\345\256\211\345\205\250\344\275\215\347\275\256", Q_NULLPTR));
        BacktoSafe_1->setText(QApplication::translate("MainWindow", "1\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        BacktoSafe_2->setText(QApplication::translate("MainWindow", "2\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        BacktoSafe_3->setText(QApplication::translate("MainWindow", "3\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        BacktoSafe_4->setText(QApplication::translate("MainWindow", "4\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        BacktoSafe_all->setText(QApplication::translate("MainWindow", "\345\205\250\351\203\250\345\233\236\345\256\211\345\205\250\344\275\215\347\275\256", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\347\224\265\346\234\272\344\276\233\347\224\265", Q_NULLPTR));
        motorsPowerOn->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\344\270\212\347\224\265", Q_NULLPTR));
        motorsPowerOff->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\346\226\255\347\224\265", Q_NULLPTR));
        readLimit->clear();
        readLimit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\231\220\347\225\2141", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\231\220\347\225\2142", Q_NULLPTR)
        );
        isSinglePointShow->setText(QApplication::translate("MainWindow", "\345\215\225\347\202\271\346\230\276\347\244\272", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\351\230\210\345\200\274", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
