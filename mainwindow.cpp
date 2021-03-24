#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "omronpst.h"
#include <QDateTime>
#include <QMetaType>
#include <QFileDialog>
Q_DECLARE_METATYPE (QVector<double>)

using namespace QtDataVisualization;
using namespace omron;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
/***************私有变量初始化**************************************
 * */
    ui->setupUi(this);
    motorsPLC = new MotorUnit();
    finsPLC = new Fins();
    modePLC = nullptr;
    camerasPLC = new omron::Cameras();
    ParSet = new ParameterSetting(this);
    manualDialog = nullptr;
    picFileDialog = nullptr;
    m_SensorUnit = new sensorunit();
    if(m_SensorUnit->Sensor_1->ReadData(SENSORFILE_1,false))
        DisplayText(QString("The parameters of sensor 1 were successfully read."));
    else
        DisplayText(QString("Failed to read the parameters of sensor 1."));
    if(m_SensorUnit->Sensor_2->ReadData(SENSORFILE_2,false))
        DisplayText(QString("The parameters of sensor 2 were successfully read."));
    else
        DisplayText(QString("Failed to read the parameters of sensor 2."));
    if(m_SensorUnit->Sensor_3->ReadData(SENSORFILE_3,false))
        DisplayText(QString("The parameters of sensor 3 were successfully read."));
    else
        DisplayText(QString("Failed to read the parameters of sensor 3."));
    if(m_SensorUnit->Sensor_4->ReadData(SENSORFILE_4,false))
        DisplayText(QString("The parameters of sensor 4 were successfully read."));
    else
        DisplayText(QString("Failed to read the parameters of sensor 4."));

    ReadSensors = nullptr;
    scatter = new Q3DScatter();
    series = new QScatter3DSeries();//三维点代理
    unLimitseries = new QScatter3DSeries();//非限界内三维点代理
    Limitseries = new QScatter3DSeries();//限界三维点代理
/*********************************************************************/

/********************指令管理器线程初始化************************************
 * */
    qRegisterMetaType<QVector<double>>("QVector<double>");
    m_manager = new Manager(finsPLC,camerasPLC);
    m_manager->moveToThread(&managerThread);
    connect(this,SIGNAL(ManagerStart()),m_manager,SLOT(start()));
    connect(m_manager,SIGNAL(message(QString)),this,SLOT(receiveMessage(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(ManagerMotorPowerOn(int)),m_manager,SLOT(powerOnMotors(int)),Qt::QueuedConnection);//槽函数在mainwindow执行
    connect(this,SIGNAL(ManagerMotorPowerOff(int)),m_manager,SLOT(powerOffMotors(int)),Qt::QueuedConnection);//槽函数在mainwindow执行
    connect(this,SIGNAL(ManualEnd(QByteArray,QByteArray)),m_manager,SLOT(manualEnd(QByteArray,QByteArray)));
    connect(&managerThread,&QThread::finished,m_manager,&QObject::deleteLater);
    connect(m_manager,SIGNAL(AutoModeEnd()),this,SLOT(autoModeDistroyed()));
    connect(this,SIGNAL(startGetImage(int)),m_manager,SLOT(getCameraImage(int)));//开始采集图像信号
    connect(this,SIGNAL(setMotorFlagZero(int)),m_manager,SLOT(setZeroMotorFlags(int)));
    connect(camerasPLC,SIGNAL(message(QString)),this,SLOT(receiveMessageFromCameras(QString)));
    connect(this,SIGNAL(AutoEnd()),m_manager,SLOT(autoEnd()),Qt::BlockingQueuedConnection);
    connect(this,SIGNAL(cmdToOrigin(int)),m_manager,SLOT(backToOrigin(int)));
    connect(this,SIGNAL(cmdToSafeLocation(int)),m_manager,SLOT(backToSafeLocation(int)));
    connect(this,SIGNAL(sendMotorToPosition(int,double)),m_manager,SLOT(setMotorToPosition(int,double)));
    connect(this,SIGNAL(sendCmdToManger(QString,bool)),m_manager,SLOT(receiveCmdFromOrders(QString,bool)));
    managerThread.start();

/*************************************************************************/


/*******************图像处理线程初始化************************************
 */
    ImageProcessWorker = new ImageProce();
    ImageProcessWorker->moveToThread(&ImageProcessThread);
    connect(this,SIGNAL(ImageProcessStart()),ImageProcessWorker,SLOT(TestSlot()));
    connect(&ImageProcessThread,&QThread::finished,ImageProcessWorker,&QObject::deleteLater);
    connect(ImageProcessWorker,SIGNAL(sendPointToMainwindow(QVector<double>,QVector<double>,QVector<double>)),
            this,SLOT(receivePointFromImageProcess(QVector<double>,QVector<double>,QVector<double>)));
    connect(ImageProcessWorker,SIGNAL(sendMessageToMainwindow(QString)),
            this,SLOT(receiveMessageFromImageProcess(QString)));
    ImageProcessThread.start();
    ImageProcessWorker->setSensorUnit(m_SensorUnit);
    connect(m_manager,SIGNAL(singleImageProcess(QString,QString)),ImageProcessWorker,SLOT(receiveFilepathFromManagerToImageProcess(QString,QString)));
    connect(this,SIGNAL(sendIsSinglePointShow(bool)),ImageProcessWorker,SLOT(receiveIsSinglePointShowFromMaindow(bool)));
    connect(this,SIGNAL(sendThresholdToImageProcess(int)),ImageProcessWorker,SLOT(receiveThresholdFromMaindow(int)));
    /*************************************************************************/

    connect(ParSet,SIGNAL(updatePar()),this,SLOT(UpdateParameters()));

    camerasPLC->findCameras();//相当于Cameras初始化
    connect(finsPLC->getUdpSocket(),SIGNAL(readyRead()),this,SLOT(dealMsg()));
    unitUi();//自定义界面初始化
    readLimitInf(LIMITINFORMATION1);//读入限界文件
}

MainWindow::~MainWindow()
{
    delete ui;
    delete motorsPLC;
    delete finsPLC;
    delete camerasPLC;
    ImageProcessThread.quit();//关闭图像处理线程
    ImageProcessThread.wait();

    managerThread.quit();//关闭指令管理器线程
    managerThread.wait();
}


void MainWindow::DisplayText(const QString &str)
{
    QDateTime current_data_time = QDateTime::currentDateTime();
    QString current_time =  current_data_time.toString("[hh:mm:ss] ");
    current_time+=str;
    this->ui->textEdit_Msg->append(current_time);
}

void MainWindow::DisplayText(const QByteArray &bytes)
{
    DisplayText(this->finsPLC->byteArrayToHexstr(bytes));
}

void MainWindow::unitUi()
{
    this->setWindowTitle("HS-RSL");
    ui->EndListen->setEnabled(false);
    ui->ModeStart->setEnabled(false);
    ui->ModeStop->setEnabled(false);//选择模式开始按键失能
    setMotorsPtr();//读取motor参数
    setPicturePath();//读取picture保存路径

    /* *****************下面对scatterShow的初始化***********************
     * */
    QWidget *container = QWidget::createWindowContainer(scatter);
    //水平布局，父对象是widget
    QHBoxLayout *hLayout = new QHBoxLayout(ui->showScatter);
    //垂直布局
    QVBoxLayout *vLayout = new QVBoxLayout();
    //将container添加到水平布局中
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    series->setItemSize(0.008);//设置点的大小
    unLimitseries->setItemSize(0.005);
    Limitseries->setItemSize(0.005);
    Limitseries->setBaseColor(QColor(0,255,0));
    unLimitseries->setBaseColor(QColor(255,0,0));
    scatter->activeTheme()->setType(Q3DTheme::Theme(6));//设置黑色背景白色点
    scatter->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);//设置阴影
    //scatter->setOrthoProjection(false);
    //scatter->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFront);
//    scatter->axisX()->setRange(-10,10);
//    scatter->axisY()->setRange(-10,5000);
//    scatter->axisZ()->setRange(-1900,1900);
    scatter->setAspectRatio(0.7);
    scatter->addSeries(series);
    scatter->addSeries(Limitseries);
    scatter->addSeries(unLimitseries);
    scatter->show();
    ui->showScatter->show();
    scatter->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetRightLow);
    /******************************************************************
     * */
}

//udp绑定端口
void MainWindow::StartListen()
{
    QString ServIp = ParSet->getPLCIpText();
    uint16_t ServPort = ParSet->getPLCPortText().toInt();
    uint16_t ClientPort = ParSet->getPCPortText().toInt();
    finsPLC->SetRemote(ServIp,ServPort);
    if(finsPLC->Connect(ClientPort)){
        DisplayText(QString("Success listen!"));
        ui->StartListen->setEnabled(false);
        ui->EndListen->setEnabled(true);
    }
    else{
        DisplayText(QString("ERROR --> Filed Listen!"));
    }

}

//udp解绑端口
void MainWindow::EndListen()
{
    finsPLC->getUdpSocket()->abort();
    DisplayText(QString("Stop Listen!"));
    finsPLC->Close();
    ui->StartListen->setEnabled(true);
    ui->EndListen->setEnabled(false);
}

//通过ParamerasSetting窗口设置电机参数、PLC-ip等
void MainWindow::setMotorsPtr()
{
    QString continuePtr = ParSet->getContinuousPtrText();
    if(motorsPLC->setManualContinuousFlag(this->finsPLC->hexstrToByteArray(continuePtr))){
        QString str("ManualContinue parameter has successful set :");str.append(continuePtr);
        DisplayText(str);
    }
    else{
        DisplayText(QString("ERROR --> ManualContinue parameter setting failed!"));
    }

    QString stepPtr = ParSet->getStepPtrText();
    if(motorsPLC->setManualStepFlag(this->finsPLC->hexstrToByteArray(stepPtr))){
        QString str("ManualStepping parameter has successful set :");str.append(stepPtr);
        DisplayText(str);
    }
    else{
        DisplayText(QString("ERROR --> ManualStepping parameter setting failed!"));
    }

    QString MotorsPrt_1 = ParSet->getMotor1Text();
    if(motorsPLC->setMotor1(this->finsPLC->hexstrToByteArray(MotorsPrt_1))){
        QString str("Motor_1's parameter has successful set :");str.append(MotorsPrt_1);
        DisplayText(str);
    }
    else{
        DisplayText(QString("ERROR --> Motor_1's parameter setting failed!"));
    }

    QString MotorsPrt_2 = ParSet->getMotor2Text();
    if(motorsPLC->setMotor2(this->finsPLC->hexstrToByteArray(MotorsPrt_2))){
        QString str("Motor_2's parameter has successful set :");str.append(MotorsPrt_2);
        DisplayText(str);
    }
    else{
        DisplayText(QString("ERROR --> Motor_2's parameter setting failed!"));
    }

    QString MotorsPrt_3 = ParSet->getMotor3Text();
    if(motorsPLC->setMotor3(this->finsPLC->hexstrToByteArray(MotorsPrt_3))){
        QString str("Motor_3's parameter has successful set :");str.append(MotorsPrt_3);
        DisplayText(str);
    }
    else{
        DisplayText(QString("ERROR --> Motor_3's parameter setting failed!"));
    }

    QString MotorsPrt_4 = ParSet->getMotor4Text();
    if(motorsPLC->setMotor4(this->finsPLC->hexstrToByteArray(MotorsPrt_4))){
        QString str("Motor_4's parameter has successful set :");str.append(MotorsPrt_4);
        DisplayText(str);
    }
    else{
        DisplayText(QString("ERROR --> Motor_4's parameter setting failed!"));
    }

    QString AutoPrt = ParSet->getAutoptrText();
    if(motorsPLC->setAutoFlag(this->finsPLC->hexstrToByteArray(AutoPrt))){
        QString str("AutoMode's parameter has successful set :");str.append(AutoPrt);
        DisplayText(str);
    }
    else{
        DisplayText(QString("ERROR --> AutoMode's parameter setting failed!"));
    }

    QString CamsPrt = ParSet->getCamsptrText();
    if(motorsPLC->setCamsFlag(this->finsPLC->hexstrToByteArray(CamsPrt))){
        QString str("CamsFlag's parameter has successful set :");str.append(CamsPrt);
        DisplayText(str);
    }
    else{
        DisplayText(QString("ERROR --> CamsFlag's parameter setting failed!"));
    }

    QString time = ParSet->getCmdWaitTime();
    m_manager->setCmdWaitTimes(time.toInt());
    DisplayText(QString("Command's wait time has successful set :%1 ms").arg(time));


}

/**********************************************
  函数名称：setPicturePath
  输入参数：
  输出参数：
  函数功能：设置相机图片的保存路径
**********************************************/
void MainWindow::setPicturePath()
{
    QString PicturePath = ParSet->getPicturePath();
    camerasPLC->SavePath = PicturePath;
}

/**********************************************
  函数名称：ScatterAddonePoint
  输入参数：point的x,y,z坐标
  输出参数：
  函数功能：向widget添加一个点，并显示
**********************************************/
void MainWindow::ScatterAddonePoint(double x, double y, double z)
{
    if(isInLimits(x,y,z)){
        series->dataProxy()->addItem(QVector3D(x, z, y));
    }
    else{
        unLimitseries->dataProxy()->addItem(QVector3D(x, z, y));
    }
}

/**********************************************
  函数名称：ScatterClearPoints
  输入参数：
  输出参数：
  函数功能：清空widget上的点
**********************************************/
void MainWindow::ScatterClearPoints()
{
    int nums = series->dataProxy()->itemCount();
    series->dataProxy()->removeItems(0,nums);
}

QByteArray MainWindow::getCameraPosition(int cameraLable)
{
    switch (cameraLable) {
    case Camera1_1:
    case Camera1_2:
        if(getCameraPosition(CAMERA1POSITION))
            return finsPLC->getRespFinsData();
        return QByteArray();
        break;
    case Camera2_1:
    case Camera2_2:
        if(getCameraPosition(CAMERA2POSITION))
            return finsPLC->getRespFinsData();
        return QByteArray();
        break;
    case Camera3_1:
    case Camera3_2:
        if(getCameraPosition(CAMERA3POSITION))
            return finsPLC->getRespFinsData();
        return QByteArray();
        break;
    case Camera4_1:
    case Camera4_2:
        if(getCameraPosition(CAMERA4POSITION))
            return finsPLC->getRespFinsData();
        return QByteArray();
        break;
    default:
        return QByteArray();
        break;
    }
}

bool MainWindow::getCameraPosition(QString cameraLable)
{
    if(m_manager->isWorking()){
        DisplayText(QString("有指令正在执行，请稍后尝试拍照\n"));
    }
    else{
        if(finsPLC->MemoryAreaWrite(finsPLC->hexstrToByteArray(cameraLable))){//将指令发送给PLC
            while (!finsPLC->isSendSuccess);//等待plc返回响应码
            finsPLC->isSendSuccess = false;
            DisplayText(QString("相机位置获取成功\n"));
            return true;
        }
        else{
            DisplayText(QString("相机位置获取失败\n"));
        }
    }
    return false;
}

/**********************************************
  函数名称：readLimitInf
  输入参数：LimitInfFile:存储限界文件的txt路径
  输出参数：
  函数功能：通过读取限界文件的txt，载入struct LimitInf;
**********************************************/
void MainWindow::readLimitInf(QString LimitInfFile)
{
    m_limit.lowerPart_linearEquation.clear();
    m_limit.lowerPart_rightMargin.clear();
    m_limit.upperPart_linearEquation.clear();
    m_limit.upperPart_rightMargin.clear();
    m_limit.limitPoints.clear();

    int LimitseriesCount = Limitseries->dataProxy()->itemCount();
    Limitseries->dataProxy()->removeItems(0,LimitseriesCount);

    std::ifstream readin;//文件读入流
    double Dividing;//上下两部分的分界线
    string Up;int numUp;//上半部分的段数
    string Down;int numDown;//下半部分的段数
    readin.open(LimitInfFile.toStdString().c_str());//打开文件
    if(!readin.is_open()){
        DisplayText(QString("限界文件打开失败！\n"));
        readin.close();
        return;
    }
    readin>>Dividing;
    m_limit.DividingLine = Dividing;
    readin>>Up;
    numUp = (int)(Up[3]-'0');
    for(int i =0;i<numUp;++i){
        double rightMargin;
        readin>>rightMargin;
        m_limit.upperPart_rightMargin.push_back(rightMargin);
    }
    for(int i=0;i<numUp;++i){
        double k,b;
        readin>>k>>b;
        m_limit.upperPart_linearEquation.push_back(make_pair(k,b));
    }
    readin>>Down;
    numDown = (int)(Down[3]-'0');
    for(int i =0;i<numDown;++i){
        double rightMargin;
        readin>>rightMargin;
        m_limit.lowerPart_rightMargin.push_back(rightMargin);
    }
    for(int i=0;i<numDown;++i){
        double k,b;
        readin>>k>>b;
        m_limit.lowerPart_linearEquation.push_back(make_pair(k,b));
    }
    for(int i=0;i<m_limit.upperPart_rightMargin.size();++i){
        double step = 0.5;
        double start = 0;
        if(i!=0)
            start = m_limit.upperPart_rightMargin[i-1];
        double end = m_limit.upperPart_rightMargin[i];
        double k,b,y,z,x;
        while(start<=end){
            k = m_limit.upperPart_linearEquation[i].first;
            b = m_limit.upperPart_linearEquation[i].second;
            y = start;
            z = k*y+b;
            x = 0;
            m_limit.limitPoints.push_back(QVector3D(x,y,z));
            start+=step;
        }
        if(i>=(m_limit.upperPart_rightMargin.size()-2)){
            if(i==(m_limit.upperPart_rightMargin.size()-2)){
                double zstart = m_limit.DividingLine;
                double zend = k*y+b;
                while(zstart<zend){
                    m_limit.limitPoints.push_back(QVector3D(x,y,zstart));
                    zstart+=step;
                }
            }
            if(i==(m_limit.upperPart_rightMargin.size()-1)){
                double zstart = m_limit.DividingLine;
                double zend = k*y+b;
                while(zstart<zend){
                    m_limit.limitPoints.push_back(QVector3D(x,y,zstart));
                    zstart+=step;
                }
            }
        }
    }
    for(int i=0;i<m_limit.lowerPart_rightMargin.size();++i){
        double step = 0.5;
        double start = 0;
        if(i!=0)
            start = m_limit.lowerPart_rightMargin[i-1];
        double end = m_limit.lowerPart_rightMargin[i];
        double k,b,y,z,x;
        while(start<=end){
            k = m_limit.lowerPart_linearEquation[i].first;
            b = m_limit.lowerPart_linearEquation[i].second;
            y = start;
            z = k*y+b;
            x = 0;
            m_limit.limitPoints.push_back(QVector3D(x,y,z));
            start+=step;
        }
        if(i>=(m_limit.lowerPart_rightMargin.size()-3)){
            if(i==(m_limit.lowerPart_rightMargin.size()-3)){
                double zstart = m_limit.lowerPart_linearEquation[i+1].first*end+m_limit.lowerPart_linearEquation[i+1].second;
                double zend = k*y+b;
                while(zstart>zend){
                    m_limit.limitPoints.push_back(QVector3D(x,y,zstart));
                    zstart-=step;
                }
            }
            if(i==(m_limit.lowerPart_rightMargin.size()-2)){
                double zstart = m_limit.DividingLine;
                double zend = k*y+b;
                while(zstart>zend){
                    m_limit.limitPoints.push_back(QVector3D(x,y,zstart));
                    zstart-=step;
                }
            }
            if(i==(m_limit.lowerPart_rightMargin.size()-1)){
                double zstart = m_limit.DividingLine;
                double zend = k*y+b;
                while(zstart>zend){
                    m_limit.limitPoints.push_back(QVector3D(x,y,zstart));
                    zstart-=step;
                }
            }
        }
    }
    int n = m_limit.limitPoints.size();
    for(int i=0;i<n;++i){
        QVector3D poi = m_limit.limitPoints[i];
        poi.setY(0-poi.y());
        m_limit.limitPoints.push_back(poi);
    }
    readin.close();
    for(int i=0;i<m_limit.limitPoints.size();++i){
        Limitseries->dataProxy()->addItem(QVector3D(0,m_limit.limitPoints[i].z(),m_limit.limitPoints[i].y()));
    }
}

/**********************************************
  函数名称：isInLimits
  输入参数：Horizontal:横向坐标；Longitudinal：纵向坐标
  输出参数：true：在限界内；false：不在限界内
  函数功能：判断三维点是否在限界内
**********************************************/
bool MainWindow::isInLimits(int Inputx,int Inputy, int Inputz)
{
    if(Inputz<0||Inputz>4800){
        return false;
    }
    double y = Inputy<0?(-Inputy):Inputy;
    double z = Inputz;
    double divline = m_limit.DividingLine;
    if(z>divline){
        int numUp = m_limit.upperPart_rightMargin.size();
        if(y>m_limit.upperPart_rightMargin[numUp-1]){
            return false;
        }
        for(int i = 0;i<numUp;++i){
            if(y<=m_limit.upperPart_rightMargin[i]){
                double k = m_limit.upperPart_linearEquation[i].first;
                double b = m_limit.upperPart_linearEquation[i].second;
                double limitz = k*y+b;
                return z<=limitz?true:false;
            }
        }
    }
    else{
        int numDown = m_limit.lowerPart_rightMargin.size();
        if(y>m_limit.lowerPart_rightMargin[numDown-1]){
            return false;
        }
        for(int i =0;i<numDown;++i){
            if(y<=m_limit.lowerPart_rightMargin[i]){
                double k = m_limit.lowerPart_linearEquation[i].first;
                double b = m_limit.lowerPart_linearEquation[i].second;
                double limitz = k*y+b;
                return z>=limitz?true:false;
            }
        }
    }
    return true;
}

void MainWindow::dealMsg()
{
    if(finsPLC->ResvData()){//fins接收到数据，并且响应的数据显示发送的指令没有问题
        finsPLC->isSendSuccess = true;
    }
    else
        finsPLC->isSendSuccess = false;//fins接收到数据，但是响应的数据显示发送的指令有问题

}

void MainWindow::UpdateParameters()
{
    setMotorsPtr();//重新设置电机参数
    setPicturePath();//重新加载图片保存路径
    if(finsPLC->getConnectStatus()){
        EndListen();//先udp解绑
        StartListen();//重新读取plc-ip、plc-port.pc-port，并绑定udp
    }
    DisplayText(QString("参数更新完成......"));
}

void MainWindow::receiveMessage(QString msg)
{
    DisplayText(msg);
}

void MainWindow::receiveMessageFromManualDiaglog(QString msg)
{
    DisplayText(msg);
}

void MainWindow::receiveMessageFromCameras(QString msg)
{
    DisplayText(msg);
}

/**********************************************
  函数名称：receiveCommandFromManualDiaglog
  输入参数：cmd:指令
            dist：步进值信息
            vec：速度信息
            _workingMode:工作模式
            motor:电机标号
  输出参数：
  函数功能：从手动控制界面接收指令
**********************************************/
void MainWindow::receiveCommandFromManualDiaglog(QByteArray cmd, double dis, double vec, int _workingMode, int motor)
{
    while(m_manager->isWorking());
//    for(int i = 0;i<100;++i){
//        if(m_manager->isWorking())
//            QThread::msleep(5);
//        else
//            break;
//    }
    if(!m_manager->isWorking()){//判断控制器是否在工作，如果没有在工作
        m_manager->addCommand(cmd);//将需要执行的指令加入到控制器中，由控制器安排这条指令的发送
        m_manager->setMode(_workingMode);//将指令的模式设置为手动模式（步进或连续）
        m_manager->setManualWorkDist(dis);//设置电机移动多长距离
        m_manager->setMotor(motor);//设置哪个电机工作
        m_manager->setVelocity(vec);//设置电机工作的速度
        m_manager->setWorking();//将控制器的状态设置为正在工作
        emit ManagerStart();
    }
    else{
        DisplayText(QString("指令管理器：正在执行上一条指令，请稍后再发送指令\n"));
    }
}

void MainWindow::receivePointFromImageProcess(QVector<double> x, QVector<double> y, QVector<double> z)
{
    for(int i=0;i<x.size();++i){
        ScatterAddonePoint(x[i],y[i],z[i]);
    }
}

void MainWindow::receiveMessageFromImageProcess(QString msg)
{
    DisplayText(msg);
}

void MainWindow::receivePathdFromPicfileDiaglog(QString path)
{
    ImageProcessWorker->setPictureFilePath(path);
    DisplayText(QString("Picture path selected :%1").arg(path));
}

/**********************************************
  函数名称：manualDialogDistroyed
  输入参数：
  输出参数：
  函数功能：手动控制界面关闭，将主界面按键使能，让电机下电
**********************************************/
void MainWindow::manualDialogDistroyed()
{
    ui->manualMode->setEnabled(true);//选择手动模式按键使能
    ui->autoMode->setEnabled(true);//选择自动模式按键使能
    ui->ModeStart->setEnabled(true);//选择模式开始按键使能
    emit ManualEnd(motorsPLC->getManualStepFlag(),motorsPLC->getManualContinuousFlag());//手动步进和手动连续模式取消
//    emit setMotorFlagZero(1);
//    emit setMotorFlagZero(2);
//    emit setMotorFlagZero(3);
//    emit setMotorFlagZero(4);
    emit ManagerMotorPowerOff(5);//手动界面关闭，电机下电
}

/**********************************************
  函数名称：autoModeDistroyed
  输入参数：
  输出参数：
  函数功能：自动控制模式结束，使主界面按键使能,电机下电部分已在指令控制器中完成
**********************************************/
void MainWindow::autoModeDistroyed()
{
    ui->manualMode->setEnabled(true);//选择手动模式按键使能
    ui->autoMode->setEnabled(true);//选择自动模式按键使能
    ui->ModeStart->setEnabled(true);//选择模式开始按键使能
    ui->ModeStop->setEnabled(false);//选择模式开始按键失能

}

void MainWindow::on_StartListen_clicked()
{
    StartListen();
}

void MainWindow::on_EndListen_clicked()
{
    EndListen();
}

void MainWindow::on_manualMode_clicked()
{
    if(modePLC!=nullptr){
        delete modePLC;
    }
    modePLC = new Mode(Manual,*motorsPLC);
    DisplayText(QString("Manual mode selected."));
    ui->ModeStart->setEnabled(true);//模式开始按键使能
    //m_pTimer.start(1000);//开启定时器
}

void MainWindow::on_autoMode_clicked()
{
    if(modePLC!=nullptr){
        delete modePLC;
    }
    modePLC = new Mode(Automatic,*motorsPLC);
    DisplayText(QString("Automatic mode selected."));
    ui->ModeStart->setEnabled(true);//模式开始按键使能
    //m_pTimer.start(1000);//开启定时器
}


void MainWindow::on_textClear_clicked()
{
    ui->textEdit_Msg->clear();
}

/**********************************************
  函数名称：CamerasGetImage
  输入参数：
  输出参数：
  函数功能：根据相机号向manger发送采集图像信号
**********************************************/
void MainWindow::CamerasGetImage(uchar cam)
{
    switch (cam) {
    case 1:{
        emit startGetImage(1);
        break;}
    case 2:
        emit startGetImage(2);
        break;
    case 3:
        emit startGetImage(3);
        break;
    case 4:
        emit startGetImage(4);
        break;
    default:
        break;
    }
}

void MainWindow::on_actionSetting_triggered()
{
    ParSet->show();
}

void MainWindow::on_actionCameraSetting_triggered()
{
    CamerasPrtWidget = new SetCamerasPrtWidget(camerasPLC->getCameraPtrList());
    CamerasPrtWidget->show();
}

/*模式开始工作
1，若为手动模式，新建一个手动控制界面
2，若为自动模式，向指令管理器传输自动控制指令*/
void MainWindow::on_ModeStart_clicked()
{

    camerasPLC->newTimeFolder();//新建一个文件夹，拍的图片全保存到这个文件夹下
    ModeType m_type = modePLC->getModeType();
    sendCmdToManger(ORIGINLINK_1,false);//原点关联标志位清零
    sendCmdToManger(ORIGINLINK_2,false);
    sendCmdToManger(ORIGINLINK_3,false);
    sendCmdToManger(ORIGINLINK_4,false);
    switch (m_type) {
    case ModeType::Automatic:
        //emit ManagerMotorPowerOn();//电机上电
        if(!m_manager->isWorking()){
            m_manager->setMode(ModeType::Automatic);
            m_manager->addCommand(modePLC->getAutoPrt());
            m_manager->setWorking();
            ui->manualMode->setEnabled(false);//选择手动模式按键失能
            ui->autoMode->setEnabled(false);//选择自动模式按键失能
            ui->ModeStart->setEnabled(false);//选择模式开始按键失能
            ui->ModeStop->setEnabled(true);//选择模式开始按键使能
            emit ManagerStart();//线程开始工作
        }
        else{
            DisplayText(QString("消息管理器：正在工作，请稍后再发送指令\n"));
        }
        break;
    case ModeType::Manual:
        if(manualDialog!=nullptr)
            delete manualDialog;//先删除之前的子窗口
        manualDialog = new manualmodeDialog(motorsPLC,this);//新建手动控制界面
        connect(manualDialog,SIGNAL(message(QString)),
                    this,SLOT(receiveMessageFromManualDiaglog(QString)));
        connect(manualDialog,SIGNAL(sendCommand(QByteArray,double,double,int,int)),
                    this,SLOT(receiveCommandFromManualDiaglog(QByteArray,double,double,int,int)));
        connect(manualDialog,SIGNAL(sendCameraCmd(uchar)),
                this,SLOT(CamerasGetImage(uchar)));
        connect(manualDialog,SIGNAL(finished(int)),this,SLOT(manualDialogDistroyed()));
        connect(this,SIGNAL(ManualStart()),manualDialog,SLOT(uintMaunal()));
        connect(manualDialog,SIGNAL(sendMotorToPosition(int,double)),this,SLOT(getCmdMotorToPosition(int,double)));
        manualDialog->show();
        emit ManagerMotorPowerOn(5);//全部电机上电
        emit ManualStart();//默认设置步进连续模式
        ui->manualMode->setEnabled(false);//选择手动模式按键失能
        ui->autoMode->setEnabled(false);//选择自动模式按键失能
        ui->ModeStart->setEnabled(false);//选择模式开始按键失能
        break;
    default:
        break;
    }
//    emit cmdToOrigin(1);//将各电机回原点
//    emit cmdToOrigin(2);
//    emit cmdToOrigin(3);
//    emit cmdToOrigin(4);
}

/**********************************************
  函数名称：on_actionCameraParm_triggered
  输入参数：
  输出参数：
  函数功能：新建一个传感器读文件窗口
**********************************************/
void MainWindow::on_actionCameraParm_triggered()
{
    if(ReadSensors!= nullptr)
        delete ReadSensors;
    ReadSensors = new ReadSensorsDialog(m_SensorUnit,this);
    ReadSensors->show();
}

/**********************************************
  on_openPictureFile_clicked
  输入参数：
  输出参数：
  函数功能：新建一个读取保存图片的文件夹窗口
**********************************************/
void MainWindow::on_openPictureFile_clicked()
{
    if(picFileDialog!=nullptr)
        delete picFileDialog;
    picFileDialog = new FindPicFile(this);
    connect(picFileDialog,SIGNAL(sendFilePathToMainwindow(QString)),
            this,SLOT(receivePathdFromPicfileDiaglog(QString)));
    picFileDialog->show();
}

/**********************************************
  函数名称：on_startProcess_clicked
  输入参数：
  输出参数：
  函数功能：开始图像处理（应先提前设置好相机的参数文件txt\dat,并设置好
            图片的文件路径）
**********************************************/
void MainWindow::on_startProcess_clicked()
{

    if(m_SensorUnit->Sensor_1->ReadData(SENSORFILE_1,false))
        DisplayText(QString("The parameters of sensor 1 were successfully read."));
    else
        DisplayText(QString("Failed to read the parameters of sensor 1."));
    if(m_SensorUnit->Sensor_2->ReadData(SENSORFILE_2,false))
        DisplayText(QString("The parameters of sensor 2 were successfully read."));
    else
        DisplayText(QString("Failed to read the parameters of sensor 2."));
    if(m_SensorUnit->Sensor_3->ReadData(SENSORFILE_3,false))
        DisplayText(QString("The parameters of sensor 3 were successfully read."));
    else
        DisplayText(QString("Failed to read the parameters of sensor 3."));
    if(m_SensorUnit->Sensor_4->ReadData(SENSORFILE_4,false))
        DisplayText(QString("The parameters of sensor 4 were successfully read."));
    else
        DisplayText(QString("Failed to read the parameters of sensor 4."));
}

/**********************************************
  函数名称：on_ModeStop_clicked
  输入参数：
  输出参数：
  函数功能：主要用于自动模式强制性停止
**********************************************/
void MainWindow::on_ModeStop_clicked()
{
    emit AutoEnd();
}

void MainWindow::on_BacktoOrigin_1_clicked()
{
    if(motorsPLC->motor1->ispower()){
        //emit setMotorFlagZero(1);
        //emit ManagerMotorPowerOn(1);
        emit cmdToOrigin(1);
    }
    else{
        DisplayText(QString("1号电机请先上电\n"));
    }
}

void MainWindow::on_BacktoOrigin_2_clicked()
{
    if(motorsPLC->motor2->ispower()){
        //emit setMotorFlagZero(2);
        //emit ManagerMotorPowerOn(1);
        emit cmdToOrigin(2);
    }
    else{
        DisplayText(QString("2号电机请先上电\n"));
    }
}

void MainWindow::on_BacktoOrigin_3_clicked()
{
    if(motorsPLC->motor3->ispower()){
        //emit setMotorFlagZero(3);
        //emit ManagerMotorPowerOn(1);
        emit cmdToOrigin(3);
    }
    else{
        DisplayText(QString("3号电机请先上电\n"));
    }
}

void MainWindow::on_BacktoOrigin_4_clicked()
{
    if(motorsPLC->motor4->ispower()){
        //emit setMotorFlagZero(4);
        //emit ManagerMotorPowerOn(1);
        emit cmdToOrigin(4);
    }
    else{
        DisplayText(QString("1号电机请先上电\n"));
    }
}

void MainWindow::on_BacktoOrigin_all_clicked()
{
    if(!motorsPLC->motor4->ispower()){
        DisplayText(QString("电机请先上电\n"));
        return;
    }
//    emit setMotorFlagZero(1);
//    emit setMotorFlagZero(2);
//    emit setMotorFlagZero(3);
//    emit setMotorFlagZero(4);
    //emit ManagerMotorPowerOn(5);
    emit cmdToOrigin(1);
    emit cmdToOrigin(2);
    emit cmdToOrigin(3);
    emit cmdToOrigin(4);
}

void MainWindow::getCmdMotorToPosition(int motor, double position)
{
    emit sendMotorToPosition(motor,position);
}

void MainWindow::on_BacktoSafe_1_clicked()
{
    emit setMotorFlagZero(1);
    //emit ManagerMotorPowerOn(1);
    emit cmdToSafeLocation(1);
}

void MainWindow::on_BacktoSafe_2_clicked()
{
    emit setMotorFlagZero(2);
    //emit ManagerMotorPowerOn(2);
    emit cmdToSafeLocation(2);
}

void MainWindow::on_BacktoSafe_3_clicked()
{
    emit setMotorFlagZero(3);
    //emit ManagerMotorPowerOn(3);
    emit cmdToSafeLocation(3);
}

void MainWindow::on_BacktoSafe_4_clicked()
{
    emit setMotorFlagZero(4);
    //emit ManagerMotorPowerOn(4);
    emit cmdToSafeLocation(4);
}

void MainWindow::on_BacktoSafe_all_clicked()
{
    emit setMotorFlagZero(1);
    emit setMotorFlagZero(2);
    emit setMotorFlagZero(3);
    emit setMotorFlagZero(4);
    //emit ManagerMotorPowerOn(5);
    emit cmdToSafeLocation(5);
}

void MainWindow::on_clearScatter_clicked()
{
    int seriesCount = series->dataProxy()->itemCount();
    series->dataProxy()->removeItems(0,seriesCount);
    int unLimitseriesCount = unLimitseries->dataProxy()->itemCount();
    unLimitseries->dataProxy()->removeItems(0,unLimitseriesCount);
}

void MainWindow::on_motorsPowerOn_clicked()
{
    emit ManagerMotorPowerOn(1);
    emit ManagerMotorPowerOn(2);
    emit ManagerMotorPowerOn(3);
    emit ManagerMotorPowerOn(4);
    motorsPLC->motor1->setPower();
    motorsPLC->motor2->setPower();
    motorsPLC->motor3->setPower();
    motorsPLC->motor4->setPower();
}

void MainWindow::on_motorsPowerOff_clicked()
{
    emit ManagerMotorPowerOff(1);
    emit ManagerMotorPowerOff(2);
    emit ManagerMotorPowerOff(3);
    emit ManagerMotorPowerOff(4);
    motorsPLC->motor1->setPower(false);
    motorsPLC->motor2->setPower(false);
    motorsPLC->motor3->setPower(false);
    motorsPLC->motor4->setPower(false);
}

void MainWindow::on_actionSavePointCloud_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save File"),
                                                    POINTCLOUDSAVEDIR,
                                                    tr("Text files(*.txt)"));
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        DisplayText(QString("保存点云数据失败\n"));
        return;
    }
    QTextStream out(&file);
    int seriesNum = series->dataProxy()->itemCount();
    for(int i =0 ;i<seriesNum;++i){
        out<<"1 "<<series->dataProxy()->itemAt(i)->x()
          <<" "<<series->dataProxy()->itemAt(i)->y()
         <<" "<<series->dataProxy()->itemAt(i)->z()<<endl;
    }
    int unlimmitSeriesNum = unLimitseries->dataProxy()->itemCount();
    for(int i=0;i<unlimmitSeriesNum;++i){
        out<<"2 "<<unLimitseries->dataProxy()->itemAt(i)->x()
          <<" "<<unLimitseries->dataProxy()->itemAt(i)->y()
         <<" "<<unLimitseries->dataProxy()->itemAt(i)->z()<<endl;
    }
    file.close();
    DisplayText(filename.append(QString(" 文件保存成功\n")));
}

void MainWindow::on_actionReadPointCloud_triggered()
{
    on_clearScatter_clicked();
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),
                                                    POINTCLOUDSAVEDIR,
                                                    tr("Text files(*.txt)"));
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        DisplayText(QString("打开点云数据失败\n"));
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList  strs=  line.split(" ");
        int isUnlimit = strs[0].toInt();
        double x = strs[1].toDouble();
        double y = strs[2].toDouble();
        double z = strs[3].toDouble();
        if(isUnlimit==1){
            series->dataProxy()->addItem(QVector3D(x,y,z));
        }
        else{
            unLimitseries->dataProxy()->addItem(QVector3D(x,y,z));
        }
    }
    file.close();
}

/**********************************************
  函数名称：on_readLimit_currentIndexChanged
  输入参数：
  输出参数：
  函数功能：选择限界
**********************************************/
void MainWindow::on_readLimit_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        readLimitInf(LIMITINFORMATION1);
        break;
    case 1:
        readLimitInf(LIMITINFORMATION2);
    default:

        break;
    }
}

void MainWindow::on_FrontView_clicked()
{
    scatter->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetRightLow);
    //默认正视图
}

/**********************************************
  函数名称：on_isSinglePointShow_stateChanged
  输入参数：
  输出参数：
  函数功能：给图像处理线程发送指令，令其是否单点显示
**********************************************/
void MainWindow::on_isSinglePointShow_stateChanged(int arg1)
{
    switch (arg1) {
    case Qt::Checked:
        emit sendIsSinglePointShow(true);
        DisplayText(QString("单点显示\n"));
        break;
    case Qt::Unchecked:
        emit sendIsSinglePointShow(false);
        DisplayText(QString("取消单点显示\n"));
        break;
    default:
        break;
    }
}


void MainWindow::on_threshold_valueChanged(int arg1)
{
    emit sendThresholdToImageProcess(arg1);
}
