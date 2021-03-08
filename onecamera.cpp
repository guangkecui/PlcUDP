#include "onecamera.h"
#include "GenICam/Camera.h"
#include "GenICam/StreamSource.h"
#include <QDebug>
#include<opencv2\opencv.hpp>
#include<string>
using namespace std;
omron::oneCamera::oneCamera()
{
}

omron::oneCamera::oneCamera(ICameraPtr inputCamera)
{
    m_pCamera = inputCamera;
    if(m_pCamera!=NULL){
        Name = m_pCamera->getSerialNumber();
    }
}

//打开相机
bool omron::oneCamera::CameraOpen()
{
    if(m_pCamera==NULL){
        return false;
    }
    if(m_pCamera->isConnected()){
        return true;
    }
    if(false == m_pCamera->connect()){
        return false;
    }
    return true;
}

//关闭相机
bool omron::oneCamera::CameraClose()
{
    if (NULL == m_pCamera)
    {
        return false;
    }
    if (false == m_pCamera->isConnected())
    {
        return true;
    }
    if (false == m_pCamera->disConnect())
    {
        return false;
    }
    return true;
}

bool omron::oneCamera::creatStreamSource()
{
    if(NULL == m_pCamera){
        return false;
    }
    m_pStreamSource = CSystem::getInstance().createStreamSource(m_pCamera);
    if(!m_pStreamSource.get()){
        return false;
    }
    return true;
}

//设置软触发
bool omron::oneCamera::CameraSetSoftTrig(void)
{
    // 设置触发器
    // set trigger
    CEnumNode nodeTriggerSelector(m_pCamera, "TriggerSelector");
    if (false == nodeTriggerSelector.isValid())
    {
        return false;
    }
    if (false == nodeTriggerSelector.setValueBySymbol("FrameStart"))
    {
        return false;
    }

    // 设置触发模式
    // set trigger mode
    CEnumNode nodeTriggerMode(m_pCamera, "TriggerMode");
    if (false == nodeTriggerMode.isValid())
    {
        return false;
    }
    if (false == nodeTriggerMode.setValueBySymbol("On"))
    {
        return false;
    }

    // 设置触发源为软触发
    // set triggerSource as software trigger
    CEnumNode nodeTriggerSource(m_pCamera, "TriggerSource");
    if (false == nodeTriggerSource.isValid())
    {
        return false;
    }
    if (false == nodeTriggerSource.setValueBySymbol("Software"))
    {
        return false;
    }
    return true;
}

//执行一次软中断
bool omron::oneCamera::ExecuteSoftTrig()
{
    if (NULL == m_pCamera)
    {
        return false;
    }

    CCmdNode nodeTriggerSoftware(m_pCamera, "TriggerSoftware");
    if (false == nodeTriggerSoftware.isValid())
    {
        return false;
    }
    if (false == nodeTriggerSoftware.execute())
    {
        return false;
    }
    return true;
}

void omron::oneCamera::FrameCallback(const CFrame &frame)
{
    imageBuff = QImage((uint8_t*)frame.getImage(),
                       frame.getImageWidth(),
                       frame.getImageHeight(),
                       QImage::Format_Grayscale8);
    m_pStreamSource->stopGrabbing();
    imageBuff.save("F:/HSRSL/Picture/FrameCallBack.jpg","JPG",100);
}

//horizontal:为true时左右翻转；vertical：为true时上下翻转
bool omron::oneCamera::getImage(QString SavePath,bool horizontal,bool vertical)
{
    if(false==CameraOpen()){
        return false;
    }
    if(NULL == m_pStreamSource.get()){
        m_pStreamSource = CSystem::getInstance().createStreamSource(m_pCamera);
    }

    bool isStartGrabbingSuccess = m_pStreamSource->startGrabbing();
    if (!isStartGrabbingSuccess)
    {
        return false;
    }
    CFrame frame;
    if(!m_pStreamSource->getFrame(frame,1000)){
        return false;
    }
//    CBoolNode light(m_pCamera,"LineInverter") ;
//    light.setValue(true);
    m_pStreamSource->stopGrabbing();
    imageBuff = QImage((uint8_t*)frame.getImage(),
                       frame.getImageWidth(),
                       frame.getImageHeight(),
                       QImage::Format_Grayscale8).mirrored(horizontal,vertical);
    imageBuff.save(SavePath,"BMP",100);
    return true;
}

/**********************************************
  函数名称：openDigitalIO
  输入参数：
  输出参数：
  函数功能：打开数字io，左相机(*_1)都是光板，右相机(*_2)都是激光条
**********************************************/
void omron::oneCamera::openDigitalIO()
{
    CBoolNode light(m_pCamera,"LineInverter") ;
    light.setValue(true);
}

/**********************************************
  函数名称：closeDigitalIO
  输入参数：
  输出参数：
  函数功能：关闭数字io，左相机(*_1)都是光板，右相机(*_2)都是激光条
**********************************************/
void omron::oneCamera::closeDigitalIO()
{
    CBoolNode light(m_pCamera,"LineInverter") ;
    light.setValue(false);
}

/**********************************************
  函数名称：loadCameraCfg
  输入参数：xmlFilename:配置文件路径
  输出参数：.size()=0:配置成功；.size()!=0：配置失败
  函数功能：配置相机属性，每次软件打开时，都读取相机配置文件
**********************************************/
QVector<QString> omron::oneCamera::loadCameraCfg(QString xmlFilename)
{
    QVector<QString> resInf;//返回信息
    Dahua::Infra::TVector< Dahua::Infra::CString >   vErrorList;
    if(m_pCamera->loadDeviceCfg(xmlFilename.toStdString().data(),vErrorList)!=0){
        resInf.push_back(QString("The following information camera configuration failed:"));
        for(int i=0;i<vErrorList.size();++i){
            QString errorInf(vErrorList[i].data());
            resInf.push_back(errorInf);
        }
    }
    else{
        resInf.push_back(QString("The camera is successfully configured."));
    }
    return resInf;

}





