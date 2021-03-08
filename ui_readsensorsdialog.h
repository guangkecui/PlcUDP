/********************************************************************************
** Form generated from reading UI file 'readsensorsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READSENSORSDIALOG_H
#define UI_READSENSORSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReadSensorsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *file_1;
    QPushButton *open_1;
    QLabel *label_2;
    QLineEdit *file_2;
    QPushButton *open_2;
    QLabel *label_3;
    QLineEdit *file_3;
    QPushButton *open_3;
    QLabel *label_4;
    QLineEdit *file_4;
    QPushButton *open_4;

    void setupUi(QDialog *ReadSensorsDialog)
    {
        if (ReadSensorsDialog->objectName().isEmpty())
            ReadSensorsDialog->setObjectName(QStringLiteral("ReadSensorsDialog"));
        ReadSensorsDialog->resize(574, 235);
        buttonBox = new QDialogButtonBox(ReadSensorsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 180, 511, 31));
        buttonBox->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(ReadSensorsDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 40, 451, 121));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        file_1 = new QLineEdit(widget);
        file_1->setObjectName(QStringLiteral("file_1"));

        gridLayout->addWidget(file_1, 0, 1, 1, 1);

        open_1 = new QPushButton(widget);
        open_1->setObjectName(QStringLiteral("open_1"));
        open_1->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout->addWidget(open_1, 0, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        file_2 = new QLineEdit(widget);
        file_2->setObjectName(QStringLiteral("file_2"));

        gridLayout->addWidget(file_2, 1, 1, 1, 1);

        open_2 = new QPushButton(widget);
        open_2->setObjectName(QStringLiteral("open_2"));
        open_2->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout->addWidget(open_2, 1, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        file_3 = new QLineEdit(widget);
        file_3->setObjectName(QStringLiteral("file_3"));

        gridLayout->addWidget(file_3, 2, 1, 1, 1);

        open_3 = new QPushButton(widget);
        open_3->setObjectName(QStringLiteral("open_3"));
        open_3->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout->addWidget(open_3, 2, 2, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        file_4 = new QLineEdit(widget);
        file_4->setObjectName(QStringLiteral("file_4"));

        gridLayout->addWidget(file_4, 3, 1, 1, 1);

        open_4 = new QPushButton(widget);
        open_4->setObjectName(QStringLiteral("open_4"));
        open_4->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        gridLayout->addWidget(open_4, 3, 2, 1, 1);


        retranslateUi(ReadSensorsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ReadSensorsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ReadSensorsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ReadSensorsDialog);
    } // setupUi

    void retranslateUi(QDialog *ReadSensorsDialog)
    {
        ReadSensorsDialog->setWindowTitle(QApplication::translate("ReadSensorsDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ReadSensorsDialog", "1\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        open_1->setText(QApplication::translate("ReadSensorsDialog", "\346\265\217\350\247\210", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReadSensorsDialog", "2\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        open_2->setText(QApplication::translate("ReadSensorsDialog", "\346\265\217\350\247\210", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReadSensorsDialog", "3\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        open_3->setText(QApplication::translate("ReadSensorsDialog", "\346\265\217\350\247\210", Q_NULLPTR));
        label_4->setText(QApplication::translate("ReadSensorsDialog", "4\345\217\267\344\274\240\346\204\237\345\231\250", Q_NULLPTR));
        open_4->setText(QApplication::translate("ReadSensorsDialog", "\346\265\217\350\247\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReadSensorsDialog: public Ui_ReadSensorsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READSENSORSDIALOG_H
