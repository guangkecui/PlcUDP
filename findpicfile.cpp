#include "findpicfile.h"
#include "ui_findpicfile.h"
#include <QFileDialog>

FindPicFile::FindPicFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindPicFile)
{
    ui->setupUi(this);
    setWindowTitle("请选择图片路径");
    path = "";
}

FindPicFile::~FindPicFile()
{
    delete ui;
}

void FindPicFile::on_find_clicked()
{
    path = QFileDialog::getExistingDirectory(this,"请选择图片路径","./");
    if(path!="")
        ui->pathText->setText(path);
}

void FindPicFile::on_buttonBox_accepted()
{
    emit sendFilePathToMainwindow(path);
}
