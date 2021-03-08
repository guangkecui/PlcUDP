#include "readsensorsdialog.h"
#include "ui_readsensorsdialog.h"
#include<QFileDialog>
#include<QMessageBox>

ReadSensorsDialog::ReadSensorsDialog(sensorunit *InputSenUnit, QWidget *parent) :
    m_SensorUnit(InputSenUnit),
    QDialog(parent),
    ui(new Ui::ReadSensorsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("请读入传感器数据文件");
    ui->file_1->setText(SENSORFILE_1);
    ui->file_2->setText(SENSORFILE_2);
    ui->file_3->setText(SENSORFILE_3);
    ui->file_4->setText(SENSORFILE_4);
}

ReadSensorsDialog::~ReadSensorsDialog()
{
    delete ui;
}

void ReadSensorsDialog::on_open_1_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this,"选择文件",
                                                    SENSORFILEDIRECTORY,
                                                    tr("File(*.txt *.dat)"));
    if(filepath == ""){
        return;
    }
    ui->file_1->setText(filepath);
}

void ReadSensorsDialog::on_open_2_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this,"选择文件",
                                                    SENSORFILEDIRECTORY,
                                                    tr("File(*.txt *.dat)"));
    if(filepath == ""){
        return;
    }
    ui->file_2->setText(filepath);
}

void ReadSensorsDialog::on_open_3_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this,"选择文件",
                                                    SENSORFILEDIRECTORY,
                                                    tr("File(*.txt *.dat)"));
    if(filepath == ""){
        return;
    }
    ui->file_3->setText(filepath);
}

void ReadSensorsDialog::on_open_4_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this,"选择文件",
                                                    SENSORFILEDIRECTORY,
                                                    tr("File(*.txt *.dat)"));
    if(filepath == ""){
        return;
    }
    ui->file_4->setText(filepath);
}

void ReadSensorsDialog::on_buttonBox_accepted()
{
    QString filepath_1 = ui->file_1->text();
    QString filepath_2 = ui->file_2->text();
    QString filepath_3 = ui->file_3->text();
    QString filepath_4 = ui->file_4->text();
    if(filepath_1!=""){
        QString format=filepath_1.right(3);
        if(format==QString("dat")){
            if(!(m_SensorUnit->Sensor_1->ReadData(filepath_1,true)))
                QMessageBox::warning(this,"error!","File_1 read failed!");
        }
        else if(format==QString("txt")){
            if(!(m_SensorUnit->Sensor_1->ReadData(filepath_1,false)))
                QMessageBox::warning(this,"error!","File_1 read failed!");
        }
    }
    if(filepath_2!=""){
        QString format=filepath_2.right(3);
        if(format==QString("dat")){
            if(!(m_SensorUnit->Sensor_2->ReadData(filepath_2,true)))
                QMessageBox::warning(this,"error!","File_2 read failed!");
        }
        else if(format==QString("txt")){
            if(!(m_SensorUnit->Sensor_2->ReadData(filepath_2,false)))
                QMessageBox::warning(this,"error!","File_2 read failed!");
        }
    }
    if(filepath_3!=""){
        QString format=filepath_3.right(3);
        if(format==QString("dat")){
            if(!m_SensorUnit->Sensor_3->ReadData(filepath_3,true))
                QMessageBox::warning(this,"error!","File_3 read failed!");
        }
        else if(format==QString("txt")){
            if(!m_SensorUnit->Sensor_3->ReadData(filepath_3,false))
                QMessageBox::warning(this,"error!","File_3 read failed!");
        }
    }
    if(filepath_4!=""){
        QString format=filepath_4.right(3);
        if(format==QString("dat")){
            if(!m_SensorUnit->Sensor_4->ReadData(filepath_4,true)){
                QMessageBox::warning(this,"error!","File_4 read failed!");
            }
        }
        else if(format==QString("txt")){
            if(!m_SensorUnit->Sensor_4->ReadData(filepath_4,false))
                QMessageBox::warning(this,"error!","File_4 read failed!");
        }
    }
}
