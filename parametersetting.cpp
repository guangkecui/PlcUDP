#include "parametersetting.h"
#include "ui_parametersetting.h"
#include "omronpst.h"
#include <QFileDialog>

using namespace omron;
ParameterSetting::ParameterSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParameterSetting)
{
    ui->setupUi(this);
    unitUi();
}

ParameterSetting::~ParameterSetting()
{
    delete ui;
}

void ParameterSetting::unitUi()
{
    this->setWindowTitle("参数设置");
    ui->continuousPtr->setText(MANUALCONTINUOUS);
    ui->stepPtr->setText(MANUALSTEPPING);
    ui->motor_1->setText(MOTOR_1);
    ui->motor_2->setText(MOTOR_2);
    ui->motor_3->setText(MOTOR_3);
    ui->motor_4->setText(MOTOR_4);
    ui->autoPtr->setText(AUTOPTR);
    ui->plc_ip->setText(PLCNX1P2_IP);
    ui->plc_port->setText(PLCNX1P2_PORT);
    ui->pc_port->setText(HOSTPC_PORT);
    ui->camAdress->setText(CAMADRESS);
    ui->pictureSavePath->setText(DEFAULTIMAGEPATH);
    ui->cmdWaitTime->setText(CMDWAITTIME);
}

QString ParameterSetting::getMotor1Text()
{
    return ui->motor_1->text();
}

QString ParameterSetting::getMotor2Text()
{
    return ui->motor_2->text();
}

QString ParameterSetting::getMotor3Text()
{
    return ui->motor_3->text();
}

QString ParameterSetting::getMotor4Text()
{
    return ui->motor_4->text();
}

QString ParameterSetting::getAutoptrText()
{
    return ui->autoPtr->text();
}

QString ParameterSetting::getContinuousPtrText()
{
    return ui->continuousPtr->text();
}

QString ParameterSetting::getStepPtrText()
{
    return ui->stepPtr->text();
}

QString ParameterSetting::getCamsptrText()
{
    return ui->camAdress->text();
}

QString ParameterSetting::getCmdWaitTime()
{
    return ui->cmdWaitTime->text();
}

QString ParameterSetting::getPLCIpText()
{
    return ui->plc_ip->text();
}

QString ParameterSetting::getPLCPortText()
{
    return ui->plc_port->text();
}

QString ParameterSetting::getPCPortText()
{
    return ui->pc_port->text();
}

QString ParameterSetting::getPicturePath()
{
    return ui->pictureSavePath->text();
}

void ParameterSetting::on_buttonBox_accepted()
{
    emit updatePar();
}

void ParameterSetting::on_scanPath_clicked()
{
    QString picturePath = QFileDialog::getExistingDirectory(this,"请选择图片保存路径","./");
    if(picturePath!="")
        ui->pictureSavePath->setText(picturePath);
}
