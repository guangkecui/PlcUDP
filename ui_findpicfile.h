/********************************************************************************
** Form generated from reading UI file 'findpicfile.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPICFILE_H
#define UI_FINDPICFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FindPicFile
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *pathText;
    QPushButton *find;

    void setupUi(QDialog *FindPicFile)
    {
        if (FindPicFile->objectName().isEmpty())
            FindPicFile->setObjectName(QStringLiteral("FindPicFile"));
        FindPicFile->resize(530, 148);
        buttonBox = new QDialogButtonBox(FindPicFile);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 90, 501, 32));
        buttonBox->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(FindPicFile);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 51, 16));
        pathText = new QLineEdit(FindPicFile);
        pathText->setObjectName(QStringLiteral("pathText"));
        pathText->setGeometry(QRect(60, 40, 371, 20));
        find = new QPushButton(FindPicFile);
        find->setObjectName(QStringLiteral("find"));
        find->setGeometry(QRect(436, 40, 76, 20));
        find->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(152, 152, 152)}\n"
"\n"
"QPushButton:hover{background-color: rgb(53, 161, 79);}\n"
"\n"
"QPushButton:pressed{background-color: rgb(53, 161, 79)}"));

        retranslateUi(FindPicFile);
        QObject::connect(buttonBox, SIGNAL(accepted()), FindPicFile, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FindPicFile, SLOT(reject()));

        QMetaObject::connectSlotsByName(FindPicFile);
    } // setupUi

    void retranslateUi(QDialog *FindPicFile)
    {
        FindPicFile->setWindowTitle(QApplication::translate("FindPicFile", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("FindPicFile", "\345\233\276\347\211\207\350\267\257\345\276\204", Q_NULLPTR));
        find->setText(QApplication::translate("FindPicFile", "\346\265\217\350\247\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FindPicFile: public Ui_FindPicFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPICFILE_H
