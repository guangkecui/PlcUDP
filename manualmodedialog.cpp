#include "manualmodedialog.h"
#include "ui_manualmodedialog.h"
#include <QThread>
using namespace omron;
manualmodeDialog::manualmodeDialog(omron::MotorUnit *motors, QWidget *parent) :
    m_motors(motors),
    QDialog(parent),
    ui(new Ui::manualmodeDialog)
{
    ui->setupUi(this);
    ui->distance1_up->setValue(10);
    ui->distance1_down->setValue(10);
    ui->distance2_up->setValue(10);
    ui->distance2_down->setValue(10);
    ui->distance3_up->setValue(10);
    ui->distance3_down->setValue(10);
    ui->distance4_up->setValue(10);
    ui->distance4_down->setValue(10);
    ui->continuous->setChecked(true);
    workingMode = omron::ModeType::ManualContinuous;
}

manualmodeDialog::~manualmodeDialog()
{

    delete ui;
}

void manualmodeDialog::uintMaunal()
{
    workingMode = ManualContinuous;
    //先给手动步进模式置0
    QByteArray ManualStepZero = m_motors->getManualStepFlag();
    ManualStepZero[ManualStepZero.size()-1] = (uint8_t)0x00;
    emit sendCommand(ManualStepZero,-1,0,workingMode,0);
    //先给手动连续模式置1
    emit sendCommand(m_motors->getManualContinuousFlag(),-1,0,workingMode,0);
}

void manualmodeDialog::on_motor1_up_clicked()
{
    //先把停止位置为0
    emit sendCommand(m_motors->MotorMoveUpStopZero(1),0,0,workingMode,1);
    //再把move位置1
    double val = (double)ui->distance1_up->value()/0.75;
    emit sendCommand(m_motors->MotorMoveUp(1),
                     val,
                     ui->velocity1_up->value(),workingMode,1);
}

void manualmodeDialog::on_motor1_down_clicked()
{

    //先把停止位置为0
    emit sendCommand(m_motors->MotorMoveDownStopZero(1),0,0,workingMode,1);
    //再把move位置1
    double val = (double)ui->distance1_down->value()/0.75;
    emit sendCommand(m_motors->MotorMoveDown(1),
                     val,
                     ui->velocity1_down->value(),workingMode,1);
}

void manualmodeDialog::on_motor2_up_clicked()
{
    //先把停止位置为0
    emit sendCommand(m_motors->MotorMoveUpStopZero(2),0,0,workingMode,2);
    //再把move位置1
    double val = (double)ui->distance2_up->value()/0.75;
    emit sendCommand(m_motors->MotorMoveUp(2),
                     val,
                     ui->velocity2_up->value(),workingMode,2);
}

void manualmodeDialog::on_motor2_down_clicked()
{
    //先把停止位置为0
    emit sendCommand(m_motors->MotorMoveDownStopZero(2),0,0,workingMode,2);
    //再把move位置1
    double val = (double)ui->distance2_down->value()/0.75;
    emit sendCommand(m_motors->MotorMoveDown(2),
                     val,
                     ui->velocity2_down->value(),workingMode,2);}

void manualmodeDialog::on_motor3_up_clicked()
{
    //先把停止位置为0
    emit sendCommand(m_motors->MotorMoveUpStopZero(3),0,0,workingMode,3);
    //再把move位置1
    double val = (double)ui->distance3_up->value()/0.75;
    emit sendCommand(m_motors->MotorMoveUp(3),
                     val,
                     ui->velocity3_up->value(),workingMode,3);
}

void manualmodeDialog::on_motor3_down_clicked()
{
    //先把停止位置为0
    emit sendCommand(m_motors->MotorMoveDownStopZero(3),0,0,workingMode,3);
    //再把move位置1
    double val = (double)ui->distance3_down->value()/0.75;
    emit sendCommand(m_motors->MotorMoveDown(3),
                     val,
                     ui->velocity3_down->value(),workingMode,3);
}

void manualmodeDialog::on_motor4_up_clicked()
{
    //先把停止位置为0
    emit sendCommand(m_motors->MotorMoveUpStopZero(4),0,0,workingMode,4);
    //再把move位置1
    double val = (double)ui->distance4_up->value()/0.75;
    emit sendCommand(m_motors->MotorMoveUp(4),
                     val,
                     ui->velocity4_up->value(),workingMode,4);
}

void manualmodeDialog::on_motor4_down_clicked()
{
    //先把停止位置为0
    emit sendCommand(m_motors->MotorMoveDownStopZero(4),0,0,workingMode,4);
    //再把move位置1
    double val = (double)ui->distance4_down->value()/0.75;
    emit sendCommand(m_motors->MotorMoveDown(4),
                     val,
                     ui->velocity4_down->value(),workingMode,4);
}

void manualmodeDialog::on_camera_1_clicked()
{
    emit sendCameraCmd(1);
}

void manualmodeDialog::on_camera_2_clicked()
{
    emit sendCameraCmd(2);
}

void manualmodeDialog::on_camera_3_clicked()
{
    emit sendCameraCmd(3);
}

void manualmodeDialog::on_camera_4_clicked()
{
    emit sendCameraCmd(4);
}

void manualmodeDialog::on_motor1upStop_clicked()
{
    emit sendCommand(m_motors->MotorMoveUpStop(1),0,0,workingMode,1);
    emit sendCommand(m_motors->MotorMoveUpZero(1),0,0,workingMode,1);
}

void manualmodeDialog::on_motor1downStop_clicked()
{
    emit sendCommand(m_motors->MotorMoveDownStop(1),0,0,workingMode,1);
    emit sendCommand(m_motors->MotorMoveDownZero(1),0,0,workingMode,1);
}

void manualmodeDialog::on_motor2upStop_clicked()
{
    emit sendCommand(m_motors->MotorMoveUpStop(2),0,0,workingMode,2);
    emit sendCommand(m_motors->MotorMoveUpZero(2),0,0,workingMode,2);
}

void manualmodeDialog::on_motor2downStop_clicked()
{
    emit sendCommand(m_motors->MotorMoveDownStop(2),0,0,workingMode,2);
    emit sendCommand(m_motors->MotorMoveDownZero(2),0,0,workingMode,2);
}

void manualmodeDialog::on_motor3upStop_clicked()
{
    emit sendCommand(m_motors->MotorMoveUpStop(3),0,0,workingMode,3);
    emit sendCommand(m_motors->MotorMoveUpZero(3),0,0,workingMode,3);
}

void manualmodeDialog::on_motor3downStop_clicked()
{
    emit sendCommand(m_motors->MotorMoveDownStop(3),0,0,workingMode,3);
    emit sendCommand(m_motors->MotorMoveDownZero(3),0,0,workingMode,3);
}

void manualmodeDialog::on_motor4upStop_clicked()
{
    emit sendCommand(m_motors->MotorMoveUpStop(4),0,0,workingMode,4);
    emit sendCommand(m_motors->MotorMoveUpZero(4),0,0,workingMode,4);
}

void manualmodeDialog::on_motor4downStop_clicked()
{
    emit sendCommand(m_motors->MotorMoveDownStop(4),0,0,workingMode,4);
    emit sendCommand(m_motors->MotorMoveDownZero(4),0,0,workingMode,4);
}

void manualmodeDialog::on_stepping_toggled(bool checked)
{
    if(checked){
        workingMode = ManualStepping;
        message("WorkingMode: ManualStepping");
        //先给手动连续模式置0
        QByteArray ManualContinuousZero = m_motors->getManualContinuousFlag();
        ManualContinuousZero[ManualContinuousZero.size()-1] = (uint8_t)0x00;
        emit sendCommand(ManualContinuousZero,-1,0,workingMode,0);
        //先给手动步进模式置1
        emit sendCommand(m_motors->getManualStepFlag(),-1,0,workingMode,0);
    }

}

void manualmodeDialog::on_continuous_toggled(bool checked)
{
    if(checked){
        workingMode = ManualContinuous;
        message("WorkingMode: ManualContinuous");
        //先给手动步进模式置0
        QByteArray ManualStepZero = m_motors->getManualStepFlag();
        ManualStepZero[ManualStepZero.size()-1] = (uint8_t)0x00;
        emit sendCommand(ManualStepZero,-1,0,workingMode,0);
        //先给手动连续模式置1
        emit sendCommand(m_motors->getManualContinuousFlag(),-1,0,workingMode,0);
    }

}

void manualmodeDialog::on_startToPosition_1_clicked()
{
    double position = ui->toPosition_1->value();
    emit sendMotorToPosition(1,position);
}

void manualmodeDialog::on_startToPosition_2_clicked()
{
    double position = ui->toPosition_2->value();
    emit sendMotorToPosition(2,position);
}

void manualmodeDialog::on_startToPosition_3_clicked()
{
    double position = ui->toPosition_3->value();
    emit sendMotorToPosition(3,position);
}

void manualmodeDialog::on_startToPosition_4_clicked()
{
    double position = ui->toPosition_4->value();
    emit sendMotorToPosition(4,position);
}


