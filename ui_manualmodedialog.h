/********************************************************************************
** Form generated from reading UI file 'manualmodedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUALMODEDIALOG_H
#define UI_MANUALMODEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_manualmodeDialog
{
public:
    QPushButton *pushButton;
    QPushButton *camera_1;
    QPushButton *camera_4;
    QPushButton *camera_3;
    QPushButton *camera_2;
    QPushButton *motor1_down;
    QPushButton *motor1_up;
    QPushButton *motor4_up;
    QPushButton *motor4_down;
    QPushButton *motor2_up;
    QPushButton *motor2_down;
    QPushButton *motor3_down;
    QPushButton *motor3_up;
    QPushButton *motor1downStop;
    QPushButton *motor1upStop;
    QPushButton *motor2upStop;
    QPushButton *motor2downStop;
    QPushButton *motor4upStop;
    QPushButton *motor4downStop;
    QPushButton *motor3downStop;
    QPushButton *motor3upStop;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *stepping;
    QRadioButton *continuous;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *distance3_down;
    QLabel *label_7;
    QDoubleSpinBox *velocity3_down;
    QLabel *label_15;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QSpinBox *distance3_up;
    QLabel *label_8;
    QDoubleSpinBox *velocity3_up;
    QLabel *label_16;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_12;
    QDoubleSpinBox *velocity4_down;
    QLabel *label_6;
    QSpinBox *distance4_down;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QSpinBox *distance4_up;
    QLabel *label_11;
    QDoubleSpinBox *velocity4_up;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QSpinBox *distance2_up;
    QDoubleSpinBox *velocity2_up;
    QLabel *label_13;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QLabel *label_5;
    QSpinBox *distance2_down;
    QLabel *label_14;
    QDoubleSpinBox *velocity2_down;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_7;
    QLabel *label;
    QSpinBox *distance1_down;
    QLabel *label_9;
    QDoubleSpinBox *velocity1_down;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_8;
    QSpinBox *distance1_up;
    QLabel *label_2;
    QLabel *label_10;
    QDoubleSpinBox *velocity1_up;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *toPosition_1;
    QPushButton *startToPosition_1;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *toPosition_4;
    QPushButton *startToPosition_4;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QDoubleSpinBox *toPosition_2;
    QPushButton *startToPosition_2;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QDoubleSpinBox *toPosition_3;
    QPushButton *startToPosition_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *manualmodeDialog)
    {
        if (manualmodeDialog->objectName().isEmpty())
            manualmodeDialog->setObjectName(QStringLiteral("manualmodeDialog"));
        manualmodeDialog->resize(869, 698);
        manualmodeDialog->setStyleSheet(QStringLiteral(""));
        pushButton = new QPushButton(manualmodeDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 140, 401, 400));
        QFont font;
        font.setFamily(QStringLiteral("ADMUI3Lg"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/resource/hightspeed.png);"));
        camera_1 = new QPushButton(manualmodeDialog);
        camera_1->setObjectName(QStringLiteral("camera_1"));
        camera_1->setGeometry(QRect(390, 100, 50, 50));
        camera_1->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        camera_4 = new QPushButton(manualmodeDialog);
        camera_4->setObjectName(QStringLiteral("camera_4"));
        camera_4->setGeometry(QRect(610, 320, 50, 50));
        camera_4->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        camera_3 = new QPushButton(manualmodeDialog);
        camera_3->setObjectName(QStringLiteral("camera_3"));
        camera_3->setGeometry(QRect(390, 540, 50, 50));
        camera_3->setMinimumSize(QSize(50, 50));
        camera_3->setSizeIncrement(QSize(50, 50));
        camera_3->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        camera_2 = new QPushButton(manualmodeDialog);
        camera_2->setObjectName(QStringLiteral("camera_2"));
        camera_2->setGeometry(QRect(170, 320, 50, 50));
        camera_2->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        motor1_down = new QPushButton(manualmodeDialog);
        motor1_down->setObjectName(QStringLiteral("motor1_down"));
        motor1_down->setGeometry(QRect(230, 100, 90, 50));
        motor1_down->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/resource/left_uncheck.png)}\n"
"QPushButton:hover{border-image: url(:/resource/left_honver.png)}\n"
"QPushButton:pressed{border-image: url(:/resource/left_check.png)}"));
        motor1_up = new QPushButton(manualmodeDialog);
        motor1_up->setObjectName(QStringLiteral("motor1_up"));
        motor1_up->setGeometry(QRect(510, 100, 90, 50));
        motor1_up->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/resource/right_uncheck.png)}\n"
"QPushButton:hover{border-image: url(:/resource/right_honver.png)}\n"
"QPushButton:pressed{border-image: url(:/resource/right_check.png)}"));
        motor4_up = new QPushButton(manualmodeDialog);
        motor4_up->setObjectName(QStringLiteral("motor4_up"));
        motor4_up->setGeometry(QRect(610, 160, 50, 90));
        motor4_up->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/resource/up_uncheck.png)}\n"
"QPushButton:hover{border-image: url(:/resource/up_honver.png)}\n"
"QPushButton:pressed{border-image: url(:/resource/up_check.png)}"));
        motor4_down = new QPushButton(manualmodeDialog);
        motor4_down->setObjectName(QStringLiteral("motor4_down"));
        motor4_down->setGeometry(QRect(610, 440, 50, 90));
        motor4_down->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/resource/down_uncheck.png)}\n"
"QPushButton:hover{border-image: url(:/resource/down_honver.png)}\n"
"QPushButton:pressed{border-image: url(:/resource/down_check.png)}"));
        motor2_up = new QPushButton(manualmodeDialog);
        motor2_up->setObjectName(QStringLiteral("motor2_up"));
        motor2_up->setGeometry(QRect(170, 160, 50, 90));
        motor2_up->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/resource/up_uncheck.png)}\n"
"QPushButton:hover{border-image: url(:/resource/up_honver.png)}\n"
"QPushButton:pressed{border-image: url(:/resource/up_check.png)}"));
        motor2_down = new QPushButton(manualmodeDialog);
        motor2_down->setObjectName(QStringLiteral("motor2_down"));
        motor2_down->setGeometry(QRect(170, 440, 50, 90));
        motor2_down->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/resource/down_uncheck.png)}\n"
"QPushButton:hover{border-image: url(:/resource/down_honver.png)}\n"
"QPushButton:pressed{border-image: url(:/resource/down_check.png)}"));
        motor3_down = new QPushButton(manualmodeDialog);
        motor3_down->setObjectName(QStringLiteral("motor3_down"));
        motor3_down->setGeometry(QRect(230, 540, 90, 50));
        motor3_down->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/resource/left_uncheck.png)}\n"
"QPushButton:hover{border-image: url(:/resource/left_honver.png)}\n"
"QPushButton:pressed{border-image: url(:/resource/left_check.png)}"));
        motor3_up = new QPushButton(manualmodeDialog);
        motor3_up->setObjectName(QStringLiteral("motor3_up"));
        motor3_up->setGeometry(QRect(510, 540, 90, 50));
        motor3_up->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/resource/right_uncheck.png)}\n"
"QPushButton:hover{border-image: url(:/resource/right_honver.png)}\n"
"QPushButton:pressed{border-image: url(:/resource/right_check.png)}"));
        motor1downStop = new QPushButton(manualmodeDialog);
        motor1downStop->setObjectName(QStringLiteral("motor1downStop"));
        motor1downStop->setGeometry(QRect(330, 100, 50, 50));
        motor1downStop->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        motor1upStop = new QPushButton(manualmodeDialog);
        motor1upStop->setObjectName(QStringLiteral("motor1upStop"));
        motor1upStop->setGeometry(QRect(450, 100, 50, 50));
        motor1upStop->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        motor2upStop = new QPushButton(manualmodeDialog);
        motor2upStop->setObjectName(QStringLiteral("motor2upStop"));
        motor2upStop->setGeometry(QRect(170, 260, 50, 50));
        motor2upStop->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        motor2downStop = new QPushButton(manualmodeDialog);
        motor2downStop->setObjectName(QStringLiteral("motor2downStop"));
        motor2downStop->setGeometry(QRect(170, 380, 50, 50));
        motor2downStop->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        motor4upStop = new QPushButton(manualmodeDialog);
        motor4upStop->setObjectName(QStringLiteral("motor4upStop"));
        motor4upStop->setGeometry(QRect(610, 260, 50, 50));
        motor4upStop->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        motor4downStop = new QPushButton(manualmodeDialog);
        motor4downStop->setObjectName(QStringLiteral("motor4downStop"));
        motor4downStop->setGeometry(QRect(610, 380, 50, 50));
        motor4downStop->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        motor3downStop = new QPushButton(manualmodeDialog);
        motor3downStop->setObjectName(QStringLiteral("motor3downStop"));
        motor3downStop->setGeometry(QRect(330, 540, 50, 50));
        motor3downStop->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        motor3upStop = new QPushButton(manualmodeDialog);
        motor3upStop->setObjectName(QStringLiteral("motor3upStop"));
        motor3upStop->setGeometry(QRect(450, 540, 50, 50));
        motor3upStop->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        groupBox = new QGroupBox(manualmodeDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 111, 101));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 81, 61));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        stepping = new QRadioButton(verticalLayoutWidget);
        stepping->setObjectName(QStringLiteral("stepping"));

        verticalLayout_3->addWidget(stepping);

        continuous = new QRadioButton(verticalLayoutWidget);
        continuous->setObjectName(QStringLiteral("continuous"));

        verticalLayout_3->addWidget(continuous);

        gridLayoutWidget = new QWidget(manualmodeDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(220, 600, 102, 48));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        distance3_down = new QSpinBox(gridLayoutWidget);
        distance3_down->setObjectName(QStringLiteral("distance3_down"));
        distance3_down->setMaximum(200);

        gridLayout->addWidget(distance3_down, 0, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(30, 20));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        velocity3_down = new QDoubleSpinBox(gridLayoutWidget);
        velocity3_down->setObjectName(QStringLiteral("velocity3_down"));
        velocity3_down->setMinimum(-400);
        velocity3_down->setMaximum(400);
        velocity3_down->setValue(50);

        gridLayout->addWidget(velocity3_down, 1, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 1, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(manualmodeDialog);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(510, 600, 102, 48));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        distance3_up = new QSpinBox(gridLayoutWidget_2);
        distance3_up->setObjectName(QStringLiteral("distance3_up"));
        distance3_up->setMaximum(200);

        gridLayout_2->addWidget(distance3_up, 0, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(30, 20));

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        velocity3_up = new QDoubleSpinBox(gridLayoutWidget_2);
        velocity3_up->setObjectName(QStringLiteral("velocity3_up"));
        velocity3_up->setMinimum(-400);
        velocity3_up->setMaximum(400);
        velocity3_up->setValue(50);

        gridLayout_2->addWidget(velocity3_up, 1, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMaximumSize(QSize(30, 20));

        gridLayout_2->addWidget(label_16, 1, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(manualmodeDialog);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(670, 460, 102, 51));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(gridLayoutWidget_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(30, 20));

        gridLayout_3->addWidget(label_12, 1, 0, 1, 1);

        velocity4_down = new QDoubleSpinBox(gridLayoutWidget_3);
        velocity4_down->setObjectName(QStringLiteral("velocity4_down"));
        velocity4_down->setMinimum(-400);
        velocity4_down->setMaximum(400);
        velocity4_down->setValue(50);

        gridLayout_3->addWidget(velocity4_down, 1, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(30, 20));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        distance4_down = new QSpinBox(gridLayoutWidget_3);
        distance4_down->setObjectName(QStringLiteral("distance4_down"));
        distance4_down->setMaximum(200);

        gridLayout_3->addWidget(distance4_down, 0, 1, 1, 1);

        gridLayoutWidget_4 = new QWidget(manualmodeDialog);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(670, 180, 102, 51));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(30, 20));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        distance4_up = new QSpinBox(gridLayoutWidget_4);
        distance4_up->setObjectName(QStringLiteral("distance4_up"));
        distance4_up->setMaximum(200);

        gridLayout_4->addWidget(distance4_up, 0, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(30, 20));

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        velocity4_up = new QDoubleSpinBox(gridLayoutWidget_4);
        velocity4_up->setObjectName(QStringLiteral("velocity4_up"));
        velocity4_up->setMinimum(-400);
        velocity4_up->setMaximum(400);
        velocity4_up->setValue(50);

        gridLayout_4->addWidget(velocity4_up, 1, 1, 1, 1);

        gridLayoutWidget_5 = new QWidget(manualmodeDialog);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(60, 180, 102, 51));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(30, 20));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        distance2_up = new QSpinBox(gridLayoutWidget_5);
        distance2_up->setObjectName(QStringLiteral("distance2_up"));
        distance2_up->setMaximum(200);

        gridLayout_5->addWidget(distance2_up, 0, 1, 1, 1);

        velocity2_up = new QDoubleSpinBox(gridLayoutWidget_5);
        velocity2_up->setObjectName(QStringLiteral("velocity2_up"));
        velocity2_up->setMinimum(-400);
        velocity2_up->setMaximum(400);
        velocity2_up->setValue(50);

        gridLayout_5->addWidget(velocity2_up, 1, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(30, 20));

        gridLayout_5->addWidget(label_13, 1, 0, 1, 1);

        gridLayoutWidget_6 = new QWidget(manualmodeDialog);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(60, 460, 102, 51));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget_6);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_6->addWidget(label_5, 0, 0, 1, 1);

        distance2_down = new QSpinBox(gridLayoutWidget_6);
        distance2_down->setObjectName(QStringLiteral("distance2_down"));
        distance2_down->setMaximum(200);

        gridLayout_6->addWidget(distance2_down, 0, 1, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(30, 20));

        gridLayout_6->addWidget(label_14, 1, 0, 1, 1);

        velocity2_down = new QDoubleSpinBox(gridLayoutWidget_6);
        velocity2_down->setObjectName(QStringLiteral("velocity2_down"));
        velocity2_down->setMinimum(-400);
        velocity2_down->setMaximum(400);
        velocity2_down->setValue(50);

        gridLayout_6->addWidget(velocity2_down, 1, 1, 1, 1);

        gridLayoutWidget_7 = new QWidget(manualmodeDialog);
        gridLayoutWidget_7->setObjectName(QStringLiteral("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(220, 40, 102, 51));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget_7);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(30, 20));

        gridLayout_7->addWidget(label, 0, 0, 1, 1);

        distance1_down = new QSpinBox(gridLayoutWidget_7);
        distance1_down->setObjectName(QStringLiteral("distance1_down"));
        distance1_down->setMaximum(200);

        gridLayout_7->addWidget(distance1_down, 0, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_7);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(30, 20));

        gridLayout_7->addWidget(label_9, 1, 0, 1, 1);

        velocity1_down = new QDoubleSpinBox(gridLayoutWidget_7);
        velocity1_down->setObjectName(QStringLiteral("velocity1_down"));
        velocity1_down->setMinimum(-400);
        velocity1_down->setMaximum(400);
        velocity1_down->setValue(50);

        gridLayout_7->addWidget(velocity1_down, 1, 1, 1, 1);

        gridLayoutWidget_8 = new QWidget(manualmodeDialog);
        gridLayoutWidget_8->setObjectName(QStringLiteral("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(510, 40, 102, 51));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        distance1_up = new QSpinBox(gridLayoutWidget_8);
        distance1_up->setObjectName(QStringLiteral("distance1_up"));
        distance1_up->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        distance1_up->setMaximum(200);

        gridLayout_8->addWidget(distance1_up, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_8);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(30, 20));

        gridLayout_8->addWidget(label_2, 0, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_8);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(30, 20));

        gridLayout_8->addWidget(label_10, 1, 0, 1, 1);

        velocity1_up = new QDoubleSpinBox(gridLayoutWidget_8);
        velocity1_up->setObjectName(QStringLiteral("velocity1_up"));
        velocity1_up->setMinimum(-400);
        velocity1_up->setMaximum(400);
        velocity1_up->setValue(50);

        gridLayout_8->addWidget(velocity1_up, 1, 1, 1, 1);

        verticalLayoutWidget_2 = new QWidget(manualmodeDialog);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(380, 40, 77, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toPosition_1 = new QDoubleSpinBox(verticalLayoutWidget_2);
        toPosition_1->setObjectName(QStringLiteral("toPosition_1"));
        toPosition_1->setMaximum(3400);

        verticalLayout->addWidget(toPosition_1);

        startToPosition_1 = new QPushButton(verticalLayoutWidget_2);
        startToPosition_1->setObjectName(QStringLiteral("startToPosition_1"));
        startToPosition_1->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        verticalLayout->addWidget(startToPosition_1);

        verticalLayoutWidget_3 = new QWidget(manualmodeDialog);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(670, 320, 77, 51));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        toPosition_4 = new QDoubleSpinBox(verticalLayoutWidget_3);
        toPosition_4->setObjectName(QStringLiteral("toPosition_4"));
        toPosition_4->setMaximum(4800);

        verticalLayout_2->addWidget(toPosition_4);

        startToPosition_4 = new QPushButton(verticalLayoutWidget_3);
        startToPosition_4->setObjectName(QStringLiteral("startToPosition_4"));
        startToPosition_4->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        verticalLayout_2->addWidget(startToPosition_4);

        verticalLayoutWidget_4 = new QWidget(manualmodeDialog);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(80, 320, 77, 51));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        toPosition_2 = new QDoubleSpinBox(verticalLayoutWidget_4);
        toPosition_2->setObjectName(QStringLiteral("toPosition_2"));
        toPosition_2->setMaximum(4800);

        verticalLayout_4->addWidget(toPosition_2);

        startToPosition_2 = new QPushButton(verticalLayoutWidget_4);
        startToPosition_2->setObjectName(QStringLiteral("startToPosition_2"));
        startToPosition_2->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        verticalLayout_4->addWidget(startToPosition_2);

        verticalLayoutWidget_5 = new QWidget(manualmodeDialog);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(380, 600, 77, 51));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        toPosition_3 = new QDoubleSpinBox(verticalLayoutWidget_5);
        toPosition_3->setObjectName(QStringLiteral("toPosition_3"));
        toPosition_3->setMaximum(3400);

        verticalLayout_5->addWidget(toPosition_3);

        startToPosition_3 = new QPushButton(verticalLayoutWidget_5);
        startToPosition_3->setObjectName(QStringLiteral("startToPosition_3"));
        startToPosition_3->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        verticalLayout_5->addWidget(startToPosition_3);

        pushButton_2 = new QPushButton(manualmodeDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 180, 101, 51));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        pushButton_2->setFont(font1);
        pushButton_2->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_2->setIconSize(QSize(40, 30));
        pushButton_2->setAutoRepeatDelay(298);

        retranslateUi(manualmodeDialog);

        QMetaObject::connectSlotsByName(manualmodeDialog);
    } // setupUi

    void retranslateUi(QDialog *manualmodeDialog)
    {
        manualmodeDialog->setWindowTitle(QApplication::translate("manualmodeDialog", "Dialog", Q_NULLPTR));
        pushButton->setText(QString());
        camera_1->setText(QApplication::translate("manualmodeDialog", "\346\265\213\351\207\2171", Q_NULLPTR));
        camera_4->setText(QApplication::translate("manualmodeDialog", "\346\265\213\351\207\2174", Q_NULLPTR));
        camera_3->setText(QApplication::translate("manualmodeDialog", "\346\265\213\351\207\2173", Q_NULLPTR));
        camera_2->setText(QApplication::translate("manualmodeDialog", "\346\265\213\351\207\2172", Q_NULLPTR));
        motor1_down->setText(QString());
        motor1_up->setText(QString());
        motor4_up->setText(QString());
        motor4_down->setText(QString());
        motor2_up->setText(QString());
        motor2_down->setText(QString());
        motor3_down->setText(QString());
        motor3_up->setText(QString());
        motor1downStop->setText(QApplication::translate("manualmodeDialog", "\345\201\234\346\255\242", Q_NULLPTR));
        motor1upStop->setText(QApplication::translate("manualmodeDialog", "\345\201\234\346\255\242", Q_NULLPTR));
        motor2upStop->setText(QApplication::translate("manualmodeDialog", "\345\201\234\346\255\242", Q_NULLPTR));
        motor2downStop->setText(QApplication::translate("manualmodeDialog", "\345\201\234\346\255\242", Q_NULLPTR));
        motor4upStop->setText(QApplication::translate("manualmodeDialog", "\345\201\234\346\255\242", Q_NULLPTR));
        motor4downStop->setText(QApplication::translate("manualmodeDialog", "\345\201\234\346\255\242", Q_NULLPTR));
        motor3downStop->setText(QApplication::translate("manualmodeDialog", "\345\201\234\346\255\242", Q_NULLPTR));
        motor3upStop->setText(QApplication::translate("manualmodeDialog", "\345\201\234\346\255\242", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("manualmodeDialog", "\346\250\241\345\274\217", Q_NULLPTR));
        stepping->setText(QApplication::translate("manualmodeDialog", "\346\255\245\350\277\233\345\236\213", Q_NULLPTR));
        continuous->setText(QApplication::translate("manualmodeDialog", "\350\277\236\347\273\255\345\236\213", Q_NULLPTR));
        label_7->setText(QApplication::translate("manualmodeDialog", "\346\255\245\350\277\233", Q_NULLPTR));
        label_15->setText(QApplication::translate("manualmodeDialog", "\351\200\237\345\272\246", Q_NULLPTR));
        label_8->setText(QApplication::translate("manualmodeDialog", "\346\255\245\350\277\233", Q_NULLPTR));
        label_16->setText(QApplication::translate("manualmodeDialog", "\351\200\237\345\272\246", Q_NULLPTR));
        label_12->setText(QApplication::translate("manualmodeDialog", "\351\200\237\345\272\246", Q_NULLPTR));
        label_6->setText(QApplication::translate("manualmodeDialog", "\346\255\245\350\277\233", Q_NULLPTR));
        label_4->setText(QApplication::translate("manualmodeDialog", "\346\255\245\350\277\233", Q_NULLPTR));
        label_11->setText(QApplication::translate("manualmodeDialog", "\351\200\237\345\272\246", Q_NULLPTR));
        label_3->setText(QApplication::translate("manualmodeDialog", "\346\255\245\350\277\233", Q_NULLPTR));
        label_13->setText(QApplication::translate("manualmodeDialog", "\351\200\237\345\272\246", Q_NULLPTR));
        label_5->setText(QApplication::translate("manualmodeDialog", "\346\255\245\350\277\233", Q_NULLPTR));
        label_14->setText(QApplication::translate("manualmodeDialog", "\351\200\237\345\272\246", Q_NULLPTR));
        label->setText(QApplication::translate("manualmodeDialog", "\346\255\245\350\277\233", Q_NULLPTR));
        label_9->setText(QApplication::translate("manualmodeDialog", "\351\200\237\345\272\246", Q_NULLPTR));
        label_2->setText(QApplication::translate("manualmodeDialog", "\346\255\245\350\277\233", Q_NULLPTR));
        label_10->setText(QApplication::translate("manualmodeDialog", "\351\200\237\345\272\246", Q_NULLPTR));
        startToPosition_1->setText(QApplication::translate("manualmodeDialog", "\346\214\207\345\256\232\344\275\215\347\275\256", Q_NULLPTR));
        startToPosition_4->setText(QApplication::translate("manualmodeDialog", "\346\214\207\345\256\232\344\275\215\347\275\256", Q_NULLPTR));
        startToPosition_2->setText(QApplication::translate("manualmodeDialog", "\346\214\207\345\256\232\344\275\215\347\275\256", Q_NULLPTR));
        startToPosition_3->setText(QApplication::translate("manualmodeDialog", "\346\214\207\345\256\232\344\275\215\347\275\256", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("manualmodeDialog", "\346\265\213\350\257\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class manualmodeDialog: public Ui_manualmodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUALMODEDIALOG_H
