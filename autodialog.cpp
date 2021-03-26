#include "autodialog.h"
#include "ui_autodialog.h"

autoDialog::autoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::autoDialog)
{
    ui->setupUi(this);
}

autoDialog::~autoDialog()
{
    delete ui;
}

void autoDialog::on_ok_1_clicked()
{
    int motor = 1;
    double step = ui->step_1->value();
    sendAutoCmdToMainwindow(motor,step);
}


void autoDialog::on_ok_2_clicked()
{
    int motor = 2;
    double step = ui->step_2->value();
    sendAutoCmdToMainwindow(motor,step);
}

void autoDialog::on_ok_3_clicked()
{
    int motor = 3;
    double step = ui->step_3->value();
    sendAutoCmdToMainwindow(motor,step);
}

void autoDialog::on_ok_4_clicked()
{
    int motor = 4;
    double step = ui->step_4->value();
    sendAutoCmdToMainwindow(motor,step);
}
