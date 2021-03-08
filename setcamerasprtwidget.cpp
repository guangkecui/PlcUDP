#include "setcamerasprtwidget.h"
#include "ui_setcamerasprtwidget.h"
#include "cammerwidget.h"

#include <string>

SetCamerasPrtWidget::SetCamerasPrtWidget(Dahua::Infra::TVector<Dahua::GenICam::ICameraPtr> CameraPtrList,
                                         QWidget *parent) :
    m_vCameraPtrList(CameraPtrList),
    QWidget(parent),
    ui(new Ui::SetCamerasPrtWidget)
{
    ui->setupUi(this);
    unitUi();
}

SetCamerasPrtWidget::~SetCamerasPrtWidget()
{
    delete ui;
}

void SetCamerasPrtWidget::unitUi()
{
    this->setWindowTitle("相机参数");
    if (m_vCameraPtrList.size() < 1)
    {
        qDebug("SetCamerasPrtWidget Constructor function:\nERROR --> The number of cameras is less than one!");
        return;
    }
    else{
        for(int i=0;i<m_vCameraPtrList.size();++i){
            const char* charSerialNumber = m_vCameraPtrList[i]->getSerialNumber();
            QString SerialNumber(charSerialNumber);
            switch (SerialNumber.toInt())
            {
            case CAMERA1_1NAME:
                ui->Cam1_1->SetCamera(m_vCameraPtrList[i]->getKey());
                qDebug("Camera1-1 has been searched\n");
                break;
            case CAMERA1_2NAME:
                ui->Cam1_2->SetCamera(m_vCameraPtrList[i]->getKey());
                qDebug("Camera1-2 has been searched\n");
                break;
            case CAMERA2_1NAME:
                ui->Cam2_1->SetCamera(m_vCameraPtrList[i]->getKey());
                qDebug("Camera2-1 has been searched\n");
                break;
            case CAMERA2_2NAME:
                ui->Cam2_2->SetCamera(m_vCameraPtrList[i]->getKey());
                qDebug("Camera2-2 has been searched\n");
                break;
            case CAMERA3_1NAME:
                ui->Cam3_1->SetCamera(m_vCameraPtrList[i]->getKey());
                qDebug("Camera3-1 has been searched\n");
                break;
            case CAMERA3_2NAME:
                ui->Cam3_2->SetCamera(m_vCameraPtrList[i]->getKey());
                qDebug("Camera3-2 has been searched\n");
                break;
            case CAMERA4_1NAME:
                ui->Cam4_1->SetCamera(m_vCameraPtrList[i]->getKey());
                qDebug("Camera4-1 has been searched\n");
                break;
            case CAMERA4_2NAME:
                ui->Cam4_2->SetCamera(m_vCameraPtrList[i]->getKey());
                qDebug("Camera4-2 has been searched\n");
            default:
                break;
            }
        }
    }

}
