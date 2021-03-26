/********************************************************************************
** Form generated from reading UI file 'autodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTODIALOG_H
#define UI_AUTODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_autoDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QDoubleSpinBox *step_1;
    QPushButton *ok_1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QDoubleSpinBox *step_2;
    QPushButton *ok_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QDoubleSpinBox *step_3;
    QPushButton *ok_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QDoubleSpinBox *step_4;
    QPushButton *ok_4;

    void setupUi(QDialog *autoDialog)
    {
        if (autoDialog->objectName().isEmpty())
            autoDialog->setObjectName(QStringLiteral("autoDialog"));
        autoDialog->resize(656, 389);
        buttonBox = new QDialogButtonBox(autoDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(270, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(autoDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 60, 571, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_11);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);

        step_1 = new QDoubleSpinBox(verticalLayoutWidget);
        step_1->setObjectName(QStringLiteral("step_1"));

        horizontalLayout_2->addWidget(step_1);

        ok_1 = new QPushButton(verticalLayoutWidget);
        ok_1->setObjectName(QStringLiteral("ok_1"));

        horizontalLayout_2->addWidget(ok_1);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_7);

        step_2 = new QDoubleSpinBox(verticalLayoutWidget);
        step_2->setObjectName(QStringLiteral("step_2"));

        horizontalLayout_3->addWidget(step_2);

        ok_2 = new QPushButton(verticalLayoutWidget);
        ok_2->setObjectName(QStringLiteral("ok_2"));

        horizontalLayout_3->addWidget(ok_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_8);

        step_3 = new QDoubleSpinBox(verticalLayoutWidget);
        step_3->setObjectName(QStringLiteral("step_3"));

        horizontalLayout_4->addWidget(step_3);

        ok_3 = new QPushButton(verticalLayoutWidget);
        ok_3->setObjectName(QStringLiteral("ok_3"));

        horizontalLayout_4->addWidget(ok_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_10);

        step_4 = new QDoubleSpinBox(verticalLayoutWidget);
        step_4->setObjectName(QStringLiteral("step_4"));

        horizontalLayout_6->addWidget(step_4);

        ok_4 = new QPushButton(verticalLayoutWidget);
        ok_4->setObjectName(QStringLiteral("ok_4"));

        horizontalLayout_6->addWidget(ok_4);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(autoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), autoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), autoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(autoDialog);
    } // setupUi

    void retranslateUi(QDialog *autoDialog)
    {
        autoDialog->setWindowTitle(QApplication::translate("autoDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("autoDialog", "\347\224\265\346\234\272\345\217\267", Q_NULLPTR));
        label_4->setText(QApplication::translate("autoDialog", "\346\255\245\350\277\233\345\200\274", Q_NULLPTR));
        label_11->setText(QApplication::translate("autoDialog", "\347\212\266\346\200\201", Q_NULLPTR));
        label_6->setText(QApplication::translate("autoDialog", "1", Q_NULLPTR));
        ok_1->setText(QApplication::translate("autoDialog", "\345\274\200\345\247\213", Q_NULLPTR));
        label_7->setText(QApplication::translate("autoDialog", "2", Q_NULLPTR));
        ok_2->setText(QApplication::translate("autoDialog", "\345\274\200\345\247\213", Q_NULLPTR));
        label_8->setText(QApplication::translate("autoDialog", "3", Q_NULLPTR));
        ok_3->setText(QApplication::translate("autoDialog", "\345\274\200\345\247\213", Q_NULLPTR));
        label_10->setText(QApplication::translate("autoDialog", "4", Q_NULLPTR));
        ok_4->setText(QApplication::translate("autoDialog", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class autoDialog: public Ui_autoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTODIALOG_H
