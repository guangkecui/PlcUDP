/********************************************************************************
** Form generated from reading UI file 'cammerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMMERWIDGET_H
#define UI_CAMMERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CammerWidget
{
public:
    QLabel *label_Pixmap;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *Open;
    QPushButton *Close;
    QPushButton *Start;
    QPushButton *Stop;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *ExposureShow;
    QSlider *Exposure;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *GainShow;
    QSlider *Gain;

    void setupUi(QWidget *CammerWidget)
    {
        if (CammerWidget->objectName().isEmpty())
            CammerWidget->setObjectName(QStringLiteral("CammerWidget"));
        CammerWidget->resize(320, 390);
        label_Pixmap = new QLabel(CammerWidget);
        label_Pixmap->setObjectName(QStringLiteral("label_Pixmap"));
        label_Pixmap->setGeometry(QRect(10, 10, 301, 261));
        verticalLayoutWidget = new QWidget(CammerWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 300, 322, 87));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Open = new QPushButton(verticalLayoutWidget);
        Open->setObjectName(QStringLiteral("Open"));
        Open->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        horizontalLayout->addWidget(Open);

        Close = new QPushButton(verticalLayoutWidget);
        Close->setObjectName(QStringLiteral("Close"));
        Close->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        horizontalLayout->addWidget(Close);

        Start = new QPushButton(verticalLayoutWidget);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        horizontalLayout->addWidget(Start);

        Stop = new QPushButton(verticalLayoutWidget);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        horizontalLayout->addWidget(Stop);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        ExposureShow = new QDoubleSpinBox(verticalLayoutWidget);
        ExposureShow->setObjectName(QStringLiteral("ExposureShow"));

        horizontalLayout_2->addWidget(ExposureShow);

        Exposure = new QSlider(verticalLayoutWidget);
        Exposure->setObjectName(QStringLiteral("Exposure"));
        Exposure->setMinimum(10);
        Exposure->setMaximum(1000000);
        Exposure->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(Exposure);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        GainShow = new QDoubleSpinBox(verticalLayoutWidget);
        GainShow->setObjectName(QStringLiteral("GainShow"));

        horizontalLayout_3->addWidget(GainShow);

        Gain = new QSlider(verticalLayoutWidget);
        Gain->setObjectName(QStringLiteral("Gain"));
        Gain->setMaximum(18);
        Gain->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(Gain);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(CammerWidget);

        QMetaObject::connectSlotsByName(CammerWidget);
    } // setupUi

    void retranslateUi(QWidget *CammerWidget)
    {
        CammerWidget->setWindowTitle(QApplication::translate("CammerWidget", "Form", Q_NULLPTR));
        label_Pixmap->setText(QString());
        Open->setText(QApplication::translate("CammerWidget", "\346\211\223\345\274\200", Q_NULLPTR));
        Close->setText(QApplication::translate("CammerWidget", "\345\205\263\351\227\255", Q_NULLPTR));
        Start->setText(QApplication::translate("CammerWidget", "\346\222\255\346\224\276", Q_NULLPTR));
        Stop->setText(QApplication::translate("CammerWidget", "\345\201\234\346\255\242", Q_NULLPTR));
        label->setText(QApplication::translate("CammerWidget", "\346\233\235\345\205\211", Q_NULLPTR));
        label_2->setText(QApplication::translate("CammerWidget", "\345\242\236\347\233\212", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CammerWidget: public Ui_CammerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMMERWIDGET_H
