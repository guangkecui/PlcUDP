/********************************************************************************
** Form generated from reading UI file 'setcamerasprtwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETCAMERASPRTWIDGET_H
#define UI_SETCAMERASPRTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <cammerwidget.h>

QT_BEGIN_NAMESPACE

class Ui_SetCamerasPrtWidget
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    CammerWidget *Cam1_1;
    QGroupBox *groupBox_2;
    CammerWidget *Cam1_2;
    QGroupBox *groupBox_4;
    CammerWidget *Cam2_2;
    QGroupBox *groupBox_3;
    CammerWidget *Cam2_1;
    QGroupBox *groupBox_5;
    CammerWidget *Cam3_1;
    QGroupBox *groupBox_6;
    CammerWidget *Cam3_2;
    QGroupBox *groupBox_7;
    CammerWidget *Cam4_1;
    QGroupBox *groupBox_8;
    CammerWidget *Cam4_2;

    void setupUi(QWidget *SetCamerasPrtWidget)
    {
        if (SetCamerasPrtWidget->objectName().isEmpty())
            SetCamerasPrtWidget->setObjectName(QStringLiteral("SetCamerasPrtWidget"));
        SetCamerasPrtWidget->resize(1383, 870);
        SetCamerasPrtWidget->setStyleSheet(QLatin1String("background-color: rgb(63,63,70);\n"
"color: rgb(255, 255, 255);"));
        gridLayoutWidget = new QWidget(SetCamerasPrtWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 1371, 851));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(gridLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        Cam1_1 = new CammerWidget(groupBox);
        Cam1_1->setObjectName(QStringLiteral("Cam1_1"));
        Cam1_1->setGeometry(QRect(9, 19, 320, 390));

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(gridLayoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        Cam1_2 = new CammerWidget(groupBox_2);
        Cam1_2->setObjectName(QStringLiteral("Cam1_2"));
        Cam1_2->setGeometry(QRect(10, 20, 320, 390));

        gridLayout_2->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(gridLayoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        Cam2_2 = new CammerWidget(groupBox_4);
        Cam2_2->setObjectName(QStringLiteral("Cam2_2"));
        Cam2_2->setGeometry(QRect(10, 20, 320, 390));

        gridLayout_2->addWidget(groupBox_4, 0, 3, 1, 1);

        groupBox_3 = new QGroupBox(gridLayoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        Cam2_1 = new CammerWidget(groupBox_3);
        Cam2_1->setObjectName(QStringLiteral("Cam2_1"));
        Cam2_1->setGeometry(QRect(10, 20, 320, 390));

        gridLayout_2->addWidget(groupBox_3, 0, 2, 1, 1);

        groupBox_5 = new QGroupBox(gridLayoutWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        Cam3_1 = new CammerWidget(groupBox_5);
        Cam3_1->setObjectName(QStringLiteral("Cam3_1"));
        Cam3_1->setGeometry(QRect(10, 20, 320, 390));

        gridLayout_2->addWidget(groupBox_5, 1, 0, 1, 1);

        groupBox_6 = new QGroupBox(gridLayoutWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        Cam3_2 = new CammerWidget(groupBox_6);
        Cam3_2->setObjectName(QStringLiteral("Cam3_2"));
        Cam3_2->setGeometry(QRect(10, 20, 320, 390));

        gridLayout_2->addWidget(groupBox_6, 1, 1, 1, 1);

        groupBox_7 = new QGroupBox(gridLayoutWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        Cam4_1 = new CammerWidget(groupBox_7);
        Cam4_1->setObjectName(QStringLiteral("Cam4_1"));
        Cam4_1->setGeometry(QRect(10, 20, 320, 390));

        gridLayout_2->addWidget(groupBox_7, 1, 2, 1, 1);

        groupBox_8 = new QGroupBox(gridLayoutWidget);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        Cam4_2 = new CammerWidget(groupBox_8);
        Cam4_2->setObjectName(QStringLiteral("Cam4_2"));
        Cam4_2->setGeometry(QRect(10, 20, 320, 390));

        gridLayout_2->addWidget(groupBox_8, 1, 3, 1, 1);


        retranslateUi(SetCamerasPrtWidget);

        QMetaObject::connectSlotsByName(SetCamerasPrtWidget);
    } // setupUi

    void retranslateUi(QWidget *SetCamerasPrtWidget)
    {
        SetCamerasPrtWidget->setWindowTitle(QApplication::translate("SetCamerasPrtWidget", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SetCamerasPrtWidget", "\347\233\270\346\234\2721-1", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("SetCamerasPrtWidget", "\347\233\270\346\234\2721-2", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("SetCamerasPrtWidget", "\347\233\270\346\234\2722-2", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("SetCamerasPrtWidget", "\347\233\270\346\234\2722-1", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("SetCamerasPrtWidget", "\347\233\270\346\234\2723-1", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("SetCamerasPrtWidget", "\347\233\270\346\234\2723-2", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("SetCamerasPrtWidget", "\347\233\270\346\234\2724-1", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("SetCamerasPrtWidget", "\347\233\270\346\234\2724-2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetCamerasPrtWidget: public Ui_SetCamerasPrtWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETCAMERASPRTWIDGET_H
