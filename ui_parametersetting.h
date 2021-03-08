/********************************************************************************
** Form generated from reading UI file 'parametersetting.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERSETTING_H
#define UI_PARAMETERSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParameterSetting
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_16;
    QLineEdit *continuousPtr;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *motor_1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *motor_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *motor_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLineEdit *motor_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLineEdit *autoPtr;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_15;
    QLineEdit *camAdress;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_17;
    QLineEdit *stepPtr;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_18;
    QLineEdit *cmdWaitTime;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *plc_port;
    QLabel *label_14;
    QLineEdit *pc_port;
    QLineEdit *plc_ip;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *pictureSavePath;
    QPushButton *scanPath;

    void setupUi(QDialog *ParameterSetting)
    {
        if (ParameterSetting->objectName().isEmpty())
            ParameterSetting->setObjectName(QStringLiteral("ParameterSetting"));
        ParameterSetting->resize(710, 538);
        buttonBox = new QDialogButtonBox(ParameterSetting);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(110, 500, 561, 32));
        buttonBox->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(ParameterSetting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 291, 471));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 271, 431));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_8->addWidget(label_16);

        continuousPtr = new QLineEdit(layoutWidget);
        continuousPtr->setObjectName(QStringLiteral("continuousPtr"));

        horizontalLayout_8->addWidget(continuousPtr);


        gridLayout->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        motor_1 = new QLineEdit(layoutWidget);
        motor_1->setObjectName(QStringLiteral("motor_1"));

        horizontalLayout->addWidget(motor_1);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        motor_2 = new QLineEdit(layoutWidget);
        motor_2->setObjectName(QStringLiteral("motor_2"));

        horizontalLayout_2->addWidget(motor_2);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        motor_3 = new QLineEdit(layoutWidget);
        motor_3->setObjectName(QStringLiteral("motor_3"));

        horizontalLayout_3->addWidget(motor_3);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        motor_4 = new QLineEdit(layoutWidget);
        motor_4->setObjectName(QStringLiteral("motor_4"));

        horizontalLayout_4->addWidget(motor_4);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_5->addWidget(label_11);

        autoPtr = new QLineEdit(layoutWidget);
        autoPtr->setObjectName(QStringLiteral("autoPtr"));

        horizontalLayout_5->addWidget(autoPtr);


        gridLayout->addLayout(horizontalLayout_5, 6, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_6->addWidget(label_15);

        camAdress = new QLineEdit(layoutWidget);
        camAdress->setObjectName(QStringLiteral("camAdress"));

        horizontalLayout_6->addWidget(camAdress);


        gridLayout->addLayout(horizontalLayout_6, 7, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_9->addWidget(label_17);

        stepPtr = new QLineEdit(layoutWidget);
        stepPtr->setObjectName(QStringLiteral("stepPtr"));

        horizontalLayout_9->addWidget(stepPtr);


        gridLayout->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_10->addWidget(label_18);

        cmdWaitTime = new QLineEdit(layoutWidget);
        cmdWaitTime->setObjectName(QStringLiteral("cmdWaitTime"));

        horizontalLayout_10->addWidget(cmdWaitTime);


        gridLayout->addLayout(horizontalLayout_10, 8, 0, 1, 1);

        groupBox_2 = new QGroupBox(ParameterSetting);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(320, 20, 361, 141));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 21, 321, 91));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 0, 0, 1, 1);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 1, 0, 1, 2);

        plc_port = new QLineEdit(layoutWidget1);
        plc_port->setObjectName(QStringLiteral("plc_port"));

        gridLayout_2->addWidget(plc_port, 1, 2, 1, 1);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 2, 0, 1, 2);

        pc_port = new QLineEdit(layoutWidget1);
        pc_port->setObjectName(QStringLiteral("pc_port"));

        gridLayout_2->addWidget(pc_port, 2, 2, 1, 1);

        plc_ip = new QLineEdit(layoutWidget1);
        plc_ip->setObjectName(QStringLiteral("plc_ip"));

        gridLayout_2->addWidget(plc_ip, 0, 2, 1, 1);

        groupBox_3 = new QGroupBox(ParameterSetting);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(320, 170, 361, 321));
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 30, 321, 25));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_7->addWidget(label_4);

        pictureSavePath = new QLineEdit(layoutWidget2);
        pictureSavePath->setObjectName(QStringLiteral("pictureSavePath"));

        horizontalLayout_7->addWidget(pictureSavePath);

        scanPath = new QPushButton(layoutWidget2);
        scanPath->setObjectName(QStringLiteral("scanPath"));
        scanPath->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        horizontalLayout_7->addWidget(scanPath);


        retranslateUi(ParameterSetting);
        QObject::connect(buttonBox, SIGNAL(accepted()), ParameterSetting, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ParameterSetting, SLOT(reject()));

        QMetaObject::connectSlotsByName(ParameterSetting);
    } // setupUi

    void retranslateUi(QDialog *ParameterSetting)
    {
        ParameterSetting->setWindowTitle(QApplication::translate("ParameterSetting", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ParameterSetting", "\347\224\265\346\234\272\345\217\202\346\225\260", Q_NULLPTR));
        label_16->setText(QApplication::translate("ParameterSetting", "\350\277\236\347\273\255\346\250\241\345\274\217", Q_NULLPTR));
        continuousPtr->setText(QString());
        label->setText(QApplication::translate("ParameterSetting", "1\345\217\267\347\224\265\346\234\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("ParameterSetting", "2\345\217\267\347\224\265\346\234\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("ParameterSetting", "3\345\217\267\347\224\265\346\234\272", Q_NULLPTR));
        label_10->setText(QApplication::translate("ParameterSetting", "4\345\217\267\347\224\265\346\234\272", Q_NULLPTR));
        motor_4->setText(QString());
        label_11->setText(QApplication::translate("ParameterSetting", "\350\207\252\345\212\250\346\250\241\345\274\217", Q_NULLPTR));
        autoPtr->setText(QString());
        label_15->setText(QApplication::translate("ParameterSetting", "\347\233\270\346\234\272\346\240\207\345\277\227", Q_NULLPTR));
        camAdress->setText(QString());
        label_17->setText(QApplication::translate("ParameterSetting", "\346\255\245\350\277\233\346\250\241\345\274\217", Q_NULLPTR));
        stepPtr->setText(QString());
        label_18->setText(QApplication::translate("ParameterSetting", "\346\214\207\344\273\244\347\255\211\345\276\205\346\227\266\351\225\277/ms", Q_NULLPTR));
        cmdWaitTime->setText(QString());
        groupBox_2->setTitle(QApplication::translate("ParameterSetting", "PLC\347\275\221\345\217\243\345\217\202\346\225\260", Q_NULLPTR));
        label_12->setText(QApplication::translate("ParameterSetting", "PLC-IP", Q_NULLPTR));
        label_13->setText(QApplication::translate("ParameterSetting", "PLC-PORT", Q_NULLPTR));
        label_14->setText(QApplication::translate("ParameterSetting", "PC-PORT", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ParameterSetting", "\347\233\270\346\234\272\345\217\202\346\225\260", Q_NULLPTR));
        label_4->setText(QApplication::translate("ParameterSetting", "\345\233\276\347\211\207\344\277\235\345\255\230\345\210\260", Q_NULLPTR));
        scanPath->setText(QApplication::translate("ParameterSetting", "\346\265\217\350\247\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ParameterSetting: public Ui_ParameterSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERSETTING_H
