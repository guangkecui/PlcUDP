#include "manager.h"
#include "omronpst.h"
#include <QtTest/QTest>
Manager::Manager(Fins *fins, Cameras *cams)
{
    _mutex.lock();
    isworking = false;
    isPolling = false;
    _mutex.unlock();
    m_fins = fins;
    m_cameras = cams;
    m_pTimer = nullptr;
    //fins接收函数与消息处理关联

    MotorPolled_Start.push_back(AUTO_START_1);
//    MotorPolled_Start.push_back(AUTO_START_2);
//    MotorPolled_Start.push_back(AUTO_START_3);
//    MotorPolled_Start.push_back(AUTO_START_4);
    MotorPolled_Inplace.push_back(AUTO_INPLACE_1);
//    MotorPolled_Inplace.push_back(AUTO_INPLACE_2);
//    MotorPolled_Inplace.push_back(AUTO_INPLACE_3);
//    MotorPolled_Inplace.push_back(AUTO_INPLACE_4);
    MotorPolled_End.push_back(AUTO_END_1);
//    MotorPolled_End.push_back(AUTO_END_2);
//    MotorPolled_End.push_back(AUTO_END_3);
//    MotorPolled_End.push_back(AUTO_END_4);
}

bool Manager::isWorking()
{
    return isworking;
}

void Manager::setWorking()
{
    _mutex.lock();
    isworking = true;
    _mutex.unlock();
}

void Manager::setMode(int mode)
{
    switch (mode) {
    case ModeType::ManualContinuous:
        workingMode = ManualContinuous;
        break;
    case ModeType::ManualStepping:
        workingMode = ManualStepping;
        break;
    case ModeType::Automatic:
        workingMode = Automatic;
        break;
    default:
        break;
    }
}

void Manager::setMotor(int motor)
{
    workingMotor = motor;
}

void Manager::setVelocity(double vec)
{
    velocity = vec;
}

/**********************************************
  函数名称：ManualWork
  输入参数：
  输出参数：
  函数功能：当指令管理器接收到指令并且指令模式为手动模式时，进入此函数
**********************************************/
void Manager::ManualWorkStepping()
{
    if(Command.size()==7){
        if(manualWorkDist>0&&manualWorkDist<MAXDISTANCE){//步进值介于0与maxdistance之间
            sendVelocity(workingMotor,velocity);//将速度信息发送给电机
            QByteArray dis = m_fins->hexstrToByteArray(DISTANCE_FLAG);
            dis.append(m_fins->doubleToByteArray(manualWorkDist));//将距离信息组合成指令
            if(m_fins->MemoryAreaWrite(dis)){//将距离信息发送过去
                message("指令管理器：distance指令发送成功\n");
            }
            else{
                concelWorking();
                emit message("指令管理器：distance指令发送失败\n");
                return;
            }
            if(m_fins->MemoryAreaWrite(Command)){//发送电机move指令
                message("指令管理器：move指令发送成功\n");
                concelWorking();
            }
            else{
                concelWorking();
                emit message("指令管理器：move指令发送失败.\n");
                return;
            }
        }
        else if(manualWorkDist==-1){
            if(m_fins->MemoryAreaWrite(Command)){//将Manual-Step模式指令发送给PLC
                message("指令管理器：Manual-Step模式设置成功\n");
                concelWorking();//管理器停止工作
            }
            else{
                concelWorking();
                emit message("指令管理器：Manual-Step模式设置失败\n");
            }
        }
        else{//停止按键按下
            if(m_fins->MemoryAreaWrite(Command)){//将stop指令发送给PLC
                message("指令管理器：stop指令发送成功\n");
                concelWorking();//管理器停止工作，等待停止按键的指令
            }
            else{
                concelWorking();
                emit message("指令管理器：stop指令发送失败。\n");
            }
        }
    }
    else{
        concelWorking();
        emit message("指令管理器：指令长度不为7.\n");
        return;
    }
}

/**********************************************
  函数名称：ManualWorkContinuous
  输入参数：
  输出参数：
  函数功能：连续工作模式，隶属于手动模式，按一下电机一直转知道按下停止键
        如果dist=0，说明停止键按下
        如果dist=-1，说明手动的step或continue模式被更改
        如果dist=else，说明move键按下，电机移动
**********************************************/
void Manager::ManualWorkContinuous()
{
    if(Command.size()==7){
        if(manualWorkDist==0){//停止按键
            if(m_fins->MemoryAreaWrite(Command)){//将stop指令发送给PLC
                concelWorking();//管理器停止工作，等待停止按键的指令
            }
            else{
                concelWorking();
                emit message("指令管理器：stop指令-发送失败。\n");
            }
        }
        else if(manualWorkDist==-1){
            if(m_fins->MemoryAreaWrite(Command)){//将指令发送给PLC
                emit message("指令管理器：Manual-Continuous模式-设置成功\n");
                concelWorking();//管理器停止工作，等待停止按键的指令
            }
            else{
                concelWorking();
                emit message("指令管理器：Manual-Continuous模式设置失败\n");
            }
        }
        else{
             sendVelocity(workingMotor,velocity);//先将速度信息发给电机
             if(m_fins->MemoryAreaWrite(Command)){//将运动指令发送给PLC
                 emit message("指令管理器：continue指令-发送成功\n");
                 concelWorking();//管理器停止工作，等待停止按键的指令
             }
             else{
                 concelWorking();
                 emit message("指令管理器：continue指令发送失败。\n");
             }
        }
    }
    else{
        concelWorking();
        emit message("指令管理器：指令长度不为7.\n");
        return;
    }

}

/**********************************************
  函数名称：setManualWorkDist
  输入参数：dis:手动模式下每按一次，电机移动的距离
  输出参数：
  函数功能：
**********************************************/
void Manager::setManualWorkDist(double dis)
{
    manualWorkDist = dis;
}

/**********************************************
  函数名称：AutoWork
  输入参数：
  输出参数：
  函数功能：当指令管理器接收到指令并且指令模式为自动模式时，进入此函数
**********************************************/
void Manager::AutoWork()
{
    //powerOnMotors(5);//电机全部上电
    //MotorPolled_IsWorking.clear();
    //MotorPolled_EndWorking.clear();//初始化清零*/
    while(!MotorPolled_StartWorking.empty()){
        int motor = MotorPolled_StartWorking.back();
        MotorPolled_StartWorking.pop_back();
        powerOnMotors(motor);
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(MotorPolled_Start[motor-1]))){//先将自动模式开始标志位发送过去
            emit message(QString("指令管理器：%1号电机自动模式开始成功\n").arg(motor));
            MotorPolled_IsWorking.push_back(motor);
        }
        else{
            powerOffMotors(motor);
            emit message(QString("指令管理器：%1号电机自动模式开始失败\n").arg(motor));
            MotorPolled_EndWorking.push_back(motor);
        }
    }
    //QThread::msleep(500);

//    //*如果没有电机初始化成功*/
//    if(MotorPolled_IsWorking.size()==0){
//        emit message("指令管理器：四个电机自动模式初始化全部失败\n");
//        concelWorking();
//        QThread::msleep(500);
//        powerOffMotors(5);//电机断电
//        emit AutoModeEnd();//给mainwindow界面发送信号，自动模式结束
//        return;
//    }
}


void Manager::concelWorking()
{
    _mutex.lock();
    isworking = false;
    _mutex.unlock();
}

void Manager::addCommand(QByteArray cmd)
{
    _mutex.lock();
    Command = cmd;
    _mutex.unlock();
}

/**********************************************
  函数名称：MemoryClear
  输入参数：
  输出参数：
  函数功能：将mem指向的内存区域清零
**********************************************/
bool Manager::MemoryClear(QByteArray mem)
{
    int size = mem.at(5) - 0x00;
    QByteArray inm = mem;
    QByteArray tem = 0x00;
    for(int i = 0;i<size;++i){
        inm.append(tem);
    }
    return m_fins->MemoryAreaWrite(inm);
}

/**********************************************
  函数名称：isSuccessfulResponse
  输入参数：
  输出参数：
  函数功能：500ms内每5ms判断一次fins是否成功收到plc的响应，如果成功返回true，失败返回false
**********************************************/
bool Manager::isSuccessfulResponse()
{
//    for(int i=0;i<100;++i){
//        if(m_fins->isSendSuccess){
//            m_fins->isSendSuccess = false;
//            return true;
//        }
//        else{
//            QThread::msleep(cmdWaitTimes);
//        }
//    }
//    return false;
    if(m_fins->isSendSuccess){
        m_fins->isSendSuccess = false;
        return true;
    }
    else{
        return false;
    }
}

void Manager::setCmdWaitTimes(int time)
{
    cmdWaitTimes = time;
}

void Manager::setZeroMotorFlags(int motor)
{
    switch (motor) {
    case 1:{
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTOR_1));
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTORDOWN_1));
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTORSTOP_1));
        break;}
    case 2:
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTOR_2));
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTORDOWN_2));
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTORSTOP_2));
        break;
    case 3:
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTOR_3));
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTORDOWN_3));
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTORSTOP_3));
        break;
    case 4:
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTOR_4));
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTORDOWN_4));
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MOTORSTOP_4));
        break;
    default:
        break;
    }
}

/**********************************************
  函数名称：setMotorToPosition
  输入参数：motor:电机号；position：指定位置
  输出参数：
  函数功能：令电机到达指定位置
**********************************************/
void Manager::setMotorToPosition(int motor, double position)
{
    //先将模式改为步进模式
    setWorking();
    int curWorkingMode = workingMode;
    if(curWorkingMode!=ManualStepping){
        //先给手动连续模式置0
        QByteArray ManualContinuousZero = m_fins->hexstrToByteArray(MANUALCONTINUOUS);
        ManualContinuousZero[ManualContinuousZero.size()-1] = (uint8_t)0x00;
        m_fins->MemoryAreaWrite(ManualContinuousZero);
        //给步进模式置1
        QByteArray ManualSteppingOne = m_fins->hexstrToByteArray(MANUALSTEPPING);
        m_fins->MemoryAreaWrite(ManualSteppingOne);
    }
    switch (motor) {
    case 1:{
        double curPosition = getMotorPosition(m_fins->hexstrToByteArray(POSITIONMOTOR1));//获得当前位置
        if(curPosition==-1){
            emit message(QString("指令管理器：获取电机位置失败\n"));
        }
        else{
            double differencePosition = (position-curPosition);//当前位置与指定位置的差值
            QByteArray dis = m_fins->hexstrToByteArray(DISTANCE_FLAG);
            dis.append(m_fins->doubleToByteArray(differencePosition>0?differencePosition:-differencePosition));//将距离信息组合成指令
            if(!m_fins->MemoryAreaWrite(dis)){//将距离信息发送过去
                break;
            }
            //sendVelocity(1,100);//发送速度100
            if(differencePosition>0){//电机应正转
                m_fins->MemoryAreaWrite(MOTOR_1);
            }
            else if(differencePosition<0){//电机反转
                m_fins->MemoryAreaWrite(MOTORDOWN_1);
            }
            else{
                break;
            }
        }
        break;}
    case 2:{
        double curPosition = getMotorPosition(m_fins->hexstrToByteArray(POSITIONMOTOR2));//获得当前位置
        if(curPosition==-1){
            emit message(QString("指令管理器：获取电机位置失败\n"));
        }
        else{
            double differencePosition = (position-curPosition);//当前位置与指定位置的差值
            QByteArray dis = m_fins->hexstrToByteArray(DISTANCE_FLAG);
            dis.append(m_fins->doubleToByteArray(differencePosition>0?differencePosition:-differencePosition));//将距离信息组合成指令
            if(!m_fins->MemoryAreaWrite(dis)){//将距离信息发送过去
                break;
            }
            //sendVelocity(2,100);//发送速度100
            if(differencePosition>0){//电机应正转
                m_fins->MemoryAreaWrite(MOTOR_2);
            }
            else if(differencePosition<0){//电机反转
                m_fins->MemoryAreaWrite(MOTORDOWN_2);
            }
            else{
                break;
            }
        }
        break;}
    case 3:{
        double curPosition = getMotorPosition(m_fins->hexstrToByteArray(POSITIONMOTOR3));//获得当前位置
        if(curPosition==-1){
            emit message(QString("指令管理器：获取电机位置失败\n"));
        }
        else{
            double differencePosition = (position-curPosition);//当前位置与指定位置的差值
            QByteArray dis = m_fins->hexstrToByteArray(DISTANCE_FLAG);
            dis.append(m_fins->doubleToByteArray(differencePosition>0?differencePosition:-differencePosition));//将距离信息组合成指令
            if(!m_fins->MemoryAreaWrite(dis)){//将距离信息发送过去
                break;
            }
            //sendVelocity(3,100);//发送速度100
            if(differencePosition>0){//电机应正转
                m_fins->MemoryAreaWrite(MOTOR_3);
            }
            else if(differencePosition<0){//电机反转
                m_fins->MemoryAreaWrite(MOTORDOWN_3);
            }
            else{
                break;
            }
        }
        break;}
    case 4:{
        double curPosition = getMotorPosition(m_fins->hexstrToByteArray(POSITIONMOTOR4));//获得当前位置
        if(curPosition==-1){
            emit message(QString("指令管理器：获取电机位置失败\n"));
        }
        else{
            double differencePosition = (position-curPosition);//当前位置与指定位置的差值
            QByteArray dis = m_fins->hexstrToByteArray(DISTANCE_FLAG);
            dis.append(m_fins->doubleToByteArray(differencePosition>0?differencePosition:-differencePosition));//将距离信息组合成指令
            if(!m_fins->MemoryAreaWrite(dis)){//将距离信息发送过去
                break;
            }
            //sendVelocity(4,100);//发送速度100
            if(differencePosition>0){//电机应正转
                m_fins->MemoryAreaWrite(MOTOR_4);
            }
            else if(differencePosition<0){//电机反转
                m_fins->MemoryAreaWrite(MOTORDOWN_4);
            }
            else{
                break;
            }
        }
        break;}
    default:
        break;
    }
//    if(curWorkingMode!=ManualStepping){
//        //先给步进连续模式置0
//        QByteArray ManualSteppingZero = m_fins->hexstrToByteArray(MANUALSTEPPING);
//        ManualSteppingZero[ManualSteppingZero.size()-1] = (uint8_t)0x00;
//        m_fins->MemoryAreaWrite(ManualSteppingZero);
//        //给连续模式置1
//        QByteArray ManualContinuousOne = m_fins->hexstrToByteArray(MANUALCONTINUOUS);
//        m_fins->MemoryAreaWrite(ManualContinuousOne);
//    }
    concelWorking();
}

/**********************************************
  函数名称：receiveCmdFromOrders
  输入参数：memory:内存区，flags:置1还是置0
  输出参数：
  函数功能：自定义发送命令
**********************************************/
void Manager::receiveCmdFromOrders(QString memory, bool flag)
{

    QByteArray cmd = m_fins->hexstrToByteArray(memory);
    QByteArray add;
    add.resize(1);
    if(flag){
        add[0] = (uint8_t)0x01;
        cmd.append(add);
    }
    else{
        add[0] = (uint8_t)0x00;
        cmd.append(add);
    }
    m_fins->MemoryAreaWrite(cmd);
}

QByteArray Manager::getCommand()
{
    return Command;
}

/**********************************************
  函数名称：getMotorPosition
  输入参数：Position:电机存储位置信息的QBytearray
  输出参数：电机当前的轴位置状态
  函数功能：
**********************************************/
double_t Manager::getMotorPosition(QByteArray Position)
{
    double poi = -1;
    if(m_fins->MemoryAreaRead(Position)){//先读取轴的位置信息
        QThread::msleep(100);
        poi = m_fins->byteArrayToDouble(m_fins->getRespFinsData());
        m_fins->clearRespFinsData();
    }
    return poi;
}

/**********************************************
  函数名称：backToOrigin
  输入参数：电机标号
  输出参数：
  函数功能：令电机回到原点，向plc发送BACKTOORIGIN指令
**********************************************/
void Manager::backToOrigin(int motor)
{
    switch (motor) {
    case 1:{
        if(isOrigin(1)){
            emit message("指令管理器：电机1已回到原点\n");
            break;
        }
        QByteArray cmd1 = m_fins->hexstrToByteArray(BACKTOORIGIN_1);
        cmd1.append((uint8_t)0x01);
        if(m_fins->MemoryAreaWrite(cmd1))
            emit message("指令管理器：电机1回原点指令发送成功\n");
        else
            emit message("指令管理器：电机1回原点指令发送失败\n");
        break;}
    case 2:{
        if(isOrigin(2)){
            emit message("指令管理器：电机2已回到原点\n");
            break;
        }
        QByteArray cmd2 = m_fins->hexstrToByteArray(BACKTOORIGIN_2);
        cmd2.append((uint8_t)0x01);
        if(m_fins->MemoryAreaWrite(cmd2))
            emit message("指令管理器：电机2回原点指令发送成功\n");
        else
            emit message("指令管理器：电机2回原点指令发送失败\n");
        break;}
    case 3:{
        if(isOrigin(3)){
            emit message("指令管理器：电机3已回到原点\n");
            break;
        }
        QByteArray cmd3 = m_fins->hexstrToByteArray(BACKTOORIGIN_3);
        cmd3.append((uint8_t)0x01);
        if(m_fins->MemoryAreaWrite(cmd3))
            emit message("指令管理器：电机3回原点指令发送成功\n");
        else
            emit message("指令管理器：电机3回原点指令发送失败\n");
        break;}
    case 4:{
        if(isOrigin(4)){
            emit message("指令管理器：电机4已回到原点\n");
            break;
        }
        QByteArray cmd4 = m_fins->hexstrToByteArray(BACKTOORIGIN_4);
        cmd4.append((uint8_t)0x01);
        if(m_fins->MemoryAreaWrite(cmd4))
            emit message("指令管理器：电机4回原点指令发送成功\n");
        else
            emit message("指令管理器：电机4回原点指令发送失败\n");
        break;}
    default:
        break;
    }
}

/**********************************************
  函数名称：backToSafeLocation
  输入参数：电机标号
  输出参数：
  函数功能：让电机回到安全位置,5为所有电机
**********************************************/
void Manager::backToSafeLocation(int motor)
{
    switch (motor) {
    case 1:{
        QByteArray cmd = m_fins->hexstrToByteArray(SAFELOCATION_1);
        cmd.append((uint8_t)0x01);
        m_fins->MemoryAreaWrite(cmd);
        break;}
    case 2:{
        QByteArray cmd = m_fins->hexstrToByteArray(SAFELOCATION_2);
        cmd.append((uint8_t)0x01);
        m_fins->MemoryAreaWrite(cmd);
        break;}
    case 3:{
        QByteArray cmd = m_fins->hexstrToByteArray(SAFELOCATION_3);
        cmd.append((uint8_t)0x01);
        m_fins->MemoryAreaWrite(cmd);
        break;}
    case 4:{
        QByteArray cmd = m_fins->hexstrToByteArray(SAFELOCATION_4);
        cmd.append((uint8_t)0x01);
        m_fins->MemoryAreaWrite(cmd);
        break;}
    default:
        break;
    }
}

/**********************************************
  函数名称：isOrigin
  输入参数：电机标号
  输出参数：
  函数功能：判断电机是否在原点
**********************************************/
bool Manager::isOrigin(int motor)
{
    m_fins->clearRespFinsData();
    switch (motor) {
    case 1:
        if(m_fins->MemoryAreaRead(m_fins->hexstrToByteArray(ISORIGIN_1))){
            QByteArray data = m_fins->getRespFinsData();
            m_fins->clearRespFinsData();
            if(data.size()==1&&data.at(0) ==0x01){
                setOriginZero(1);
                return true;
            }
            else{
                setOriginZero(1);
                return false;
            }
        }
        else{
            emit message("指令管理器：电机1原点查询指令发送失败\n");
            return false;
        }
        break;
    case 2:
        if(m_fins->MemoryAreaRead(m_fins->hexstrToByteArray(ISORIGIN_2))){
            QByteArray data = m_fins->getRespFinsData();
            m_fins->clearRespFinsData();
            if(data.size()==1&&data.at(0) ==0x01){
                setOriginZero(2);
                return true;
            }
            else{
                setOriginZero(2);
                return false;
            }
        }
        else{
            emit message("指令管理器：电机2原点查询指令发送失败\n");
            return false;
        }
        break;
    case 3:
        if(m_fins->MemoryAreaRead(m_fins->hexstrToByteArray(ISORIGIN_3))){
            QByteArray data = m_fins->getRespFinsData();
            m_fins->clearRespFinsData();
            if(data.size()==1&&data.at(0) ==0x01){
                setOriginZero(3);
                return true;
            }
            else{
                setOriginZero(3);
                return false;
            }
        }
        else{
            emit message("指令管理器：电机3原点查询指令发送失败\n");
            return false;
        }
        break;
    case 4:
        if(m_fins->MemoryAreaRead(m_fins->hexstrToByteArray(ISORIGIN_4))){
            QByteArray data = m_fins->getRespFinsData();
            m_fins->clearRespFinsData();
            if(data.size()==1&&data.at(0) ==0x01){
                setOriginZero(4);
                return true;
            }
            else{
                setOriginZero(4);
                return false;
            }
        }
        else{
            emit message("指令管理器：电机4原点查询指令发送失败\n");
            return false;
        }
        break;
    default:
        setOriginZero(motor);
        return false;
        break;
    }
}

/**********************************************
  函数名称：setOriginZero
  输入参数：电机标号
  输出参数：
  函数功能：根据plc程序特性，每次需要对某个关联的标志位清零
**********************************************/
void Manager::setOriginZero(int motor)
{
    switch (motor) {
    case 1:
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(ORIGINLINK_1)));
        else
            emit message("指令管理器：电机1原点关联标志位清零失败\n");
        break;
    case 2:
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(ORIGINLINK_2)));
        else
            emit message("指令管理器：电机2原点关联标志位清零失败\n");
        break;
    case 3:
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(ORIGINLINK_3)));
        else
            emit message("指令管理器：电机3原点关联标志位清零失败\n");
        break;
    case 4:
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(ORIGINLINK_4)));
        else
            emit message("指令管理器：电机4原点关联标志位清零失败\n");
        break;
    default:
        break;
    }
}

/**********************************************
  函数名称：sendVelocity
  输入参数：motor:电机标号;inputVec:速度
  输出参数：
  函数功能：发送速度信息给电机
**********************************************/

void Manager::sendVelocity(int motor, double inputVec)
{
    QByteArray vec = m_fins->doubleToByteArray(inputVec);
    switch (motor) {
    case 1:
    {
        QByteArray mem = m_fins->hexstrToByteArray(VELOCITY_MANUAL);
        mem.append(vec);
        if(m_fins->MemoryAreaWrite(mem));
        else
            emit message("指令管理器：电机1的速度信息发送失败\n");
        break;}
    case 2:{
        QByteArray mem = m_fins->hexstrToByteArray(VELOCITY_MANUAL);
        mem.append(vec);
        if(m_fins->MemoryAreaWrite(mem));
        else{
            emit message("指令管理器：电机2的速度信息发送失败\n");}
        break;}
    case 3:{
        QByteArray mem = m_fins->hexstrToByteArray(VELOCITY_MANUAL);
        mem.append(vec);
        if(m_fins->MemoryAreaWrite(mem));
        else
            emit message("指令管理器：电机3的速度信息发送失败\n");
        break;}
    case 4:{
        QByteArray mem = m_fins->hexstrToByteArray(VELOCITY_MANUAL);
        mem.append(vec);
        if(m_fins->MemoryAreaWrite(mem));
        else
            emit message("指令管理器：电机4的速度信息发送失败\n");
        break;}
    default:
        break;
    }
}

/**********************************************
  函数名称：getPosition
  输入参数：相机标号
  输出参数：
  函数功能：获得轴的的位置信息
**********************************************/
void Manager::getPosition(int camera)
{
    switch (camera) {
    case Camera1_1:
    case Camera1_2:{
        if(m_fins->MemoryAreaRead(m_fins->hexstrToByteArray(POSITIONMOTOR1))){//先读取轴的位置信息
            QThread::msleep(100);
            double poi = m_fins->byteArrayToDouble(m_fins->getRespFinsData());
            m_fins->clearRespFinsData();
            QString poiNum = QString::number(poi,'f',4);
            m_cameras->camerasDis.Dis1 = poiNum;
        }
        else{
            emit message("1号电机的相对位置信息获取失败");
        }

        break;}
    case Camera2_1:
    case Camera2_2:
        if(m_fins->MemoryAreaRead(m_fins->hexstrToByteArray(POSITIONMOTOR2))){//先读取轴的位置信息
            QThread::msleep(100);
            double poi = m_fins->byteArrayToDouble(m_fins->getRespFinsData());
            m_fins->clearRespFinsData();
            m_cameras->camerasDis.Dis2 = QString::number(poi,'f',4);
        }
        else{
            emit message("2号电机的相对位置信息获取失败");
        }
        break;
    case Camera3_1:
    case Camera3_2:
        if(m_fins->MemoryAreaRead(m_fins->hexstrToByteArray(POSITIONMOTOR3))){//先读取轴的位置信息
            QThread::msleep(100);
            double poi = m_fins->byteArrayToDouble(m_fins->getRespFinsData());
            m_fins->clearRespFinsData();
            m_cameras->camerasDis.Dis3 = QString::number(poi,'f',4);
        }
        else{
            emit message("3号电机的相对位置信息获取失败");
        }
        break;
    case Camera4_1:
    case Camera4_2:
        if(m_fins->MemoryAreaRead(m_fins->hexstrToByteArray(POSITIONMOTOR4))){//先读取轴的位置信息
            QThread::msleep(100);
            double poi = m_fins->byteArrayToDouble(m_fins->getRespFinsData());
            m_fins->clearRespFinsData();
            m_cameras->camerasDis.Dis4= QString::number(poi,'f',4);
        }
        else{
            emit message("4号电机的相对位置信息获取失败");
        }
        break;
    default:
        break;
    }
}

void Manager::getCameraImage(int camera)
{
    QString imagename1_lightON,
            imagename1_lightOFF,
            imagename2_lightON,
            imagename2_lightOFF;

    switch (camera) {
    case 1:{
        getPosition(1);//获取电机1的位置
        imagename2_lightOFF=m_cameras->getImageOfCamera(CAMERALABEL::Camera1_2,false);
        imagename1_lightOFF=m_cameras->getImageOfCamera(CAMERALABEL::Camera1_1,false);
        imagename2_lightON=m_cameras->getImageOfCamera(CAMERALABEL::Camera1_2,true);
        imagename1_lightON=m_cameras->getImageOfCamera(CAMERALABEL::Camera1_1,true);
        if(""==imagename2_lightOFF||""==imagename2_lightON)
            emit message(QString("相机1-2拍照失败"));
        else{
            emit singleImageProcess(imagename2_lightOFF,imagename2_lightON);
            emit message(QString("相机1-2拍照成功"));
        }


        if(""==imagename1_lightOFF||""==imagename1_lightON)
            emit message(QString("相机1-1拍照失败"));
        else{
            emit singleImageProcess(imagename1_lightOFF,imagename1_lightON);
            emit message(QString("相机1-1拍照成功"));
        }
        break;}
    case 2:{
        getPosition(3);
        imagename2_lightOFF=m_cameras->getImageOfCamera(CAMERALABEL::Camera2_2,false);
        imagename1_lightOFF=m_cameras->getImageOfCamera(CAMERALABEL::Camera2_1,false);
        imagename2_lightON=m_cameras->getImageOfCamera(CAMERALABEL::Camera2_2,true);
        imagename1_lightON=m_cameras->getImageOfCamera(CAMERALABEL::Camera2_1,true);

        if(""==imagename2_lightOFF||""==imagename2_lightON)
            emit message(QString("相机2-2拍照失败"));
        else{
            emit singleImageProcess(imagename2_lightOFF,imagename2_lightON);
            emit message(QString("相机2-2拍照成功"));
        }

        if(""==imagename1_lightOFF||""==imagename1_lightON)
            emit message(QString("相机2-1拍照失败"));
        else{
            emit singleImageProcess(imagename1_lightOFF,imagename1_lightON);
            emit message(QString("相机2-1拍照成功"));
        }
        break;}
    case 3:{
        getPosition(5);
        imagename2_lightOFF=m_cameras->getImageOfCamera(CAMERALABEL::Camera3_2,false);
        imagename1_lightOFF=m_cameras->getImageOfCamera(CAMERALABEL::Camera3_1,false);
        imagename2_lightON=m_cameras->getImageOfCamera(CAMERALABEL::Camera3_2,true);
        imagename1_lightON=m_cameras->getImageOfCamera(CAMERALABEL::Camera3_1,true);
        if(""==imagename2_lightOFF||""==imagename2_lightON)
            emit message(QString("相机3-2拍照失败"));
        else{
            emit singleImageProcess(imagename2_lightOFF,imagename2_lightON);
            emit message(QString("相机3-2拍照成功"));
        }


        if(""==imagename1_lightOFF||""==imagename1_lightON)
            emit message(QString("相机3-1拍照失败"));
        else{
            emit singleImageProcess(imagename1_lightOFF,imagename1_lightON);
            emit message(QString("相机3-1拍照成功"));
        }
        break;}
    case 4:{
        getPosition(7);
        imagename2_lightOFF=m_cameras->getImageOfCamera(CAMERALABEL::Camera4_2,false);
        imagename1_lightOFF=m_cameras->getImageOfCamera(CAMERALABEL::Camera4_1,false);
        imagename2_lightON=m_cameras->getImageOfCamera(CAMERALABEL::Camera4_2,true);
        imagename1_lightON=m_cameras->getImageOfCamera(CAMERALABEL::Camera4_1,true);
        if(""==imagename2_lightOFF||""==imagename2_lightON)
            emit message(QString("相机4-2拍照失败"));
        else{
            emit singleImageProcess(imagename2_lightOFF,imagename2_lightON);
            emit message(QString("相机4-2拍照成功"));
        }


        if(""==imagename1_lightOFF||""==imagename1_lightON)
            emit message(QString("相机4-1拍照失败"));
        else{
            emit singleImageProcess(imagename1_lightOFF,imagename1_lightON);
            emit message(QString("相机4-1拍照成功"));
        }
        break;}

    default:
        break;
    }
}



/**********************************************
  函数名称：powerOnMotors
  输入参数：
  输出参数：
  函数功能：给电机上电,5为给所有电机上电
**********************************************/

void Manager::powerOnMotors(int motor)
{
    //setWorking();
    switch (motor) {
    case 1:
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(POWERMOTOR_1))){//将电机1上电
            message("指令管理器：电机1上电成功\n");
        }
        else
            message("指令管理器：电机1上电失败\n");
        break;
    case 2:
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(POWERMOTOR_2))){//将电机2上电
            message("指令管理器：电机2上电成功\n");
        }
        else
            message("指令管理器：电机2上电失败\n");
        break;
    case 3:
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(POWERMOTOR_3))){//将电机3上电
            message("指令管理器：电机3上电成功\n");
        }
        else
            message("指令管理器：电机3上电失败\n");
        break;
    case 4:
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(POWERMOTOR_4))){//将电机4上电
            message("指令管理器：电机4上电成功\n");
        }
        else
            message("指令管理器：电机4上电失败\n");
        break;
    case 5:
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(POWERMOTOR_1))){//将电机1上电
            message("指令管理器：电机1上电成功\n");
        }
        else
            message("指令管理器：电机1上电失败\n");
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(POWERMOTOR_2))){//将电机2上电
            message("指令管理器：电机2上电成功\n");
        }
        else
            message("指令管理器：电机2上电失败\n");
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(POWERMOTOR_3))){//将电机3上电
             message("指令管理器：电机3上电成功\n");
        }
        else
            message("指令管理器：电机3上电失败\n");
        if(m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(POWERMOTOR_4))){//将电机4上电
            message("指令管理器：电机4上电成功\n");
        }
        else
            message("指令管理器：电机4上电失败\n");
        break;
    default:
        break;
    }


   //concelWorking();
}

void Manager::powerOffMotors(int motor)
{
    switch (motor) {
    case 5:
        if(m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(POWERMOTOR_1))){//将电机1下电
            message("指令管理器：电机1下电成功\n");
        }
        else
            message("指令管理器：电机1下电失败\n");
        if(m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(POWERMOTOR_2))){//将电机2下电
            message("指令管理器：电机2下电成功\n");
        }
        else
            message("指令管理器：电机2下电失败\n");
        if(m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(POWERMOTOR_3))){//将电机3下电
            message("指令管理器：电机3下电成功\n");
        }
        else
            message("指令管理器：电机3下电失败\n");
        if(m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(POWERMOTOR_4))){//将电机4下电
            message("指令管理器：电机4下电成功\n");
        }
        else
            message("指令管理器：电机4下电失败\n");
        break;
    case 1:
        if(m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(POWERMOTOR_1))){//将电机1下电
            message("指令管理器：电机1下电成功\n");
        }
        else
            message("指令管理器：电机1下电失败\n");
        break;
    case 2:
        if(m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(POWERMOTOR_2))){//将电机2下电
            message("指令管理器：电机2下电成功\n");
        }
        else
            message("指令管理器：电机2下电失败\n");
        break;
    case 3:
        if(m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(POWERMOTOR_3))){//将电机3下电
            message("指令管理器：电机3下电成功\n");
        }
        else
            message("指令管理器：电机3下电失败\n");
        break;
    case 4:
        if(m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(POWERMOTOR_4))){//将电机4下电
            message("指令管理器：电机4下电成功\n");
        }
        else
            message("指令管理器：电机4下电失败\n");
        break;
    default:
        break;
    }

}

void Manager::manualEnd(QByteArray step, QByteArray continuous)
{
    setWorking();
    //先给手动步进模式置0
    step[step.size()-1] = (uint8_t)0x00;
    m_fins->MemoryAreaWrite(step);
    //先给手动连续模式置0
    continuous[continuous.size()-1] = (uint8_t)0x00;
    m_fins->MemoryAreaWrite(continuous);
    //所有电机相关标志位清零
    setZeroMotorFlags(1);
    setZeroMotorFlags(2);
    setZeroMotorFlags(3);
    setZeroMotorFlags(4);
    concelWorking();
}

/**********************************************
  函数名称：autoEnd
  输入参数：
  输出参数：
  函数功能：自动模式强制性停止
**********************************************/
void Manager::autoEnd()
{
    m_pTimer->stop();
    //先将自动模式开始标志位清零

    for(int i=0;i<MotorPolled_Start.size();++i)
        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero( MotorPolled_Start[i]));
    //先将自动模式到位标志位清零
    for(int i=0;i<MotorPolled_Inplace.size();++i){
        QByteArray setPosition = m_fins->hexstrToByteArray(MotorPolled_Inplace[i]);
        char zero = (uint8_t)0x00;
        setPosition.push_back(zero);
        m_fins->MemoryAreaWrite(setPosition);
    }
    for(int i=0;i<MotorPolled_End.size();++i){
        QByteArray setPosition = m_fins->hexstrToByteArray(MotorPolled_End[i]);
        char zero = (uint8_t)0x00;
        setPosition.push_back(zero);
        m_fins->MemoryAreaWrite(setPosition);
    }
    emit AutoModeEnd();//告诉mainwindow自动模式结束，将案件使能
    concelWorking();
    powerOffMotors(5);
    emit message("指令管理器：自动模式强制关闭\n");
}

void Manager::start()
{
        switch (workingMode) {
        case ManualContinuous:
            ManualWorkContinuous();
            break;
        case ManualStepping:
            ManualWorkStepping();
            break;
        case Automatic:
            AutoWork();
            //*如果有电机初始化成功*/
            if(MotorPolled_IsWorking.size()>0){
                if(m_pTimer!=nullptr)
                    delete m_pTimer;
                m_pTimer = new QTimer(this);
                connect(m_pTimer,SIGNAL(timeout()),this,SLOT(timerPollDeal()));
                m_pTimer->start(2000);//定时器开启
            }
            //powerOffMotors();
            break;
        default:
            break;
        }
}

/**********************************************
  函数名称：timerPollDeal
  输入参数：
  输出参数：
  函数功能：定时器定时处理函数
**********************************************/
void Manager::timerPollDeal()
{
    //判断是否还有需要轮询的电机
    if(MotorPolled_IsWorking.size()==0){
        MotorPolled_EndWorking.clear();
        concelWorking();
        powerOffMotors(5);
        emit AutoModeEnd();
        emit message("指令管理器：定时器关闭\n");
        m_pTimer->stop();
        return;
    }

    //m_pTimer->stop();
    //*轮询是否有电机置位，若有则进行拍照
    //并将图像处理信号发送至imageprocess线程
    //若没有，则判断是否有电机结束
    //轮询是否有电机结束，若有则将结束的电机号从数组中清除，更新数组*/
    for(int i =0;i<MotorPolled_IsWorking.size();++i){
        int motor = MotorPolled_IsWorking[i]-1;//记录电机号
        if(m_fins->MemoryAreaRead(m_fins->hexstrToByteArray(MotorPolled_Inplace[motor]))){
            QThread::msleep(1000);
                QByteArray data= m_fins->getRespFinsData();
                m_fins->clearRespFinsData();//把数据清空
                if( data[0]==(char)0x01){//电机已到位
                    getPosition((CAMERALABEL)(2*motor+1));
                    QString imageLightOFF1 = m_cameras->getImageOfCamera((CAMERALABEL)(2*MotorPolled_IsWorking[i]-1),false);
                    QString imageLightOFF2 = m_cameras->getImageOfCamera((CAMERALABEL)(2*MotorPolled_IsWorking[i]),false);
                    QString imageLightON1 = m_cameras->getImageOfCamera((CAMERALABEL)(2*MotorPolled_IsWorking[i]-1),true);
                    QString imageLightON2 = m_cameras->getImageOfCamera((CAMERALABEL)(2*MotorPolled_IsWorking[i]),true);
                    if(imageLightOFF1==""||imageLightON1==""){ //对相应的相机进行拍照
                        emit message(QString("指令管理器：%1号相机拍照失败\n").arg(2*MotorPolled_IsWorking[i]-1));
                    }
                    else{
                        emit message(QString("指令管理器：%1号相机拍照成功\n").arg(2*MotorPolled_IsWorking[i]-1));
                        emit singleImageProcess(imageLightOFF1,imageLightON1);
                    }
                    if(imageLightOFF2==""||imageLightON2==""){ //对相应的相机进行拍照
                        emit message(QString("指令管理器：%1号相机拍照失败\n").arg(2*MotorPolled_IsWorking[i]));
                    }
                    else{
                        emit message(QString("指令管理器：%1号相机拍照成功\n").arg(2*MotorPolled_IsWorking[i]));
                        emit singleImageProcess(imageLightOFF2,imageLightON2);
                    }
                    //对到位标志位置为0
                    QByteArray setPosition = m_fins->hexstrToByteArray(MotorPolled_Inplace[motor]);
                    char zero = (uint8_t)0x00;
                    setPosition.push_back(zero);
                    if(m_fins->MemoryAreaWrite(setPosition)){
                        emit message(QString("指令管理器：%1号电机Inplace位成功清0\n").arg(motor+1));
                    }
                    else{
                        emit message(QString("指令管理器：%1号电机Inplace位清0失败\n").arg(motor+1));
                    }
                    //对开始标志位置1
                    m_fins->MemoryAreaWrite(m_fins->hexstrToByteArray(MotorPolled_Start[motor]));
                }
                else{
                    emit message(QString("指令管理器：%1号电机未到位\n").arg(motor+1));
                }
            //}
        }
        else{
            emit message(QString("指令管理器：%1号电机Inplace轮询失败\n").arg(motor+1));
        }

        //再轮询自动模式下正在工作的电机，是否有结束的
        if(m_fins->MemoryAreaRead(m_fins->hexstrToByteArray(MotorPolled_End[motor]))){
            QThread::msleep(40);
                QByteArray res=m_fins->getRespFinsData();
                m_fins->clearRespFinsData();//把数据清空
                if( res[0] == (char)0x01){//电机已结束
                    //将相应相机的Start位置为0
                    m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MotorPolled_Start[motor]));
                    //将相应相机的End位置为0
                    QByteArray setPosition = m_fins->hexstrToByteArray(MotorPolled_Start[motor]);
                    char zero = (uint8_t)0x00;
                    setPosition.push_back(zero);
                    m_fins->MemoryAreaWrite(setPosition);
                    //更新数组,先将需要剔除的电机号记录在endWorking中，在for循环之后再根据endWorking将isworking更新
                    MotorPolled_EndWorking.push_back(motor);
                    emit message(QString("指令管理器：%1号电机结束工作\n").arg(motor+1));
                }

        }
        else{
            emit message(QString("指令管理器：%1号电机End轮询失败\n").arg(motor+1));
        }
    }
    //根据endWorking将isworking更新
    for(int i=0;i<MotorPolled_EndWorking.size();++i){
        MotorPolled_IsWorking.removeOne(MotorPolled_EndWorking[i]);
    }

//    //根据更新后的数组 将自动模式开始位重新置0
//    for(int i=0;i<MotorPolled_EndWorking.size();++i){
//        int motor = MotorPolled_EndWorking[i];
//        m_fins->MemoryAreaWrite(m_fins->lastByteSetZero(MotorPolled_Start[motor-1]));
//    }
    //m_pTimer->start(2000);

}

/**********************************************
  函数名称：udpReceiveDeal
  输入参数：
  输出参数：
  函数功能：fins响应函数
**********************************************/
//void Manager::udpReceiveDeal()
//{

//    if(m_fins->ResvData()){
//        m_fins->isSendSuccess = true;
//    }
//    else{
//        m_fins->isSendSuccess = false;
//    }

//}
