#include "udpfinscommand.h"
#include <QMessageBox>
#include <QtNetwork/QNetworkInterface>
#include <QThread>

omron::udpFinsCommand::udpFinsCommand(uint8_t ServiceID)
{
    udpTransport = new QUdpSocket();
    ConnectStatus = false;
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach(QHostAddress address,list){
        if(address.protocol()==QAbstractSocket::IPv4Protocol){
            clientIP = address.toString();
            break;
        }
    }//记录本机IP地址
    cmdFins.resize(12);
    cmdFins[PSID] = ServiceID;
}

omron::udpFinsCommand::~udpFinsCommand()
{
    if(udpTransport!=nullptr){
        delete udpTransport;
        udpTransport = nullptr;
    }
}

//建立udp通信
bool omron::udpFinsCommand::Connect(uint16_t ClientPort)
{
    if(udpTransport==nullptr){
        udpTransport = new QUdpSocket();
    }
    clientPort = ClientPort;//记录本机端口
    if(!(udpTransport->bind(QHostAddress::AnyIPv4,clientPort)))//绑定本机端口)
        return false;//绑定失败

    ConnectStatus = true;
    return true;//开始监听
}

//关闭udp通信
void omron::udpFinsCommand::Close()
{
    udpTransport->disconnect();
    delete udpTransport;
    udpTransport = nullptr;
    ConnectStatus = false;
}

//设置PLC远端IP-Port
void omron::udpFinsCommand::SetRemote(QString ipaddr, uint16_t port)
{
    servIP = ipaddr;
    servPort = port;
    cmdFins[DNA] = (uint8_t)0x00;
    cmdFins[DA1] = (uint8_t)QHostAddress(servIP).toIPv4Address();
    cmdFins[DA2] = (uint8_t)0x00;
    cmdFins[SNA] = (uint8_t)0x00;
    cmdFins[SA1] = (uint8_t)QHostAddress(clientIP).toIPv4Address();
    cmdFins[SA2] = (uint8_t)0x00;
}

//拼接要读取的指令
bool omron::udpFinsCommand::MemoryAreaRead(const QByteArray &data)
{
    if(!ConnectStatus)
        return false;
    cmdFins[ICF] = (uint8_t)0x80;
    cmdFins[RSC] = (uint8_t)0x00;
    cmdFins[GCT] = (uint8_t)0x02;

    cmdFins[MC] = (uint8_t)0x01;
    cmdFins[SC] = (uint8_t)0x01;

    cmdFins.remove(12,cmdFins.size()-12);//初始化cmdFins为12位.
    if(data.size()>0&&data.size()==6){
        cmdFins.append(data);
    }
    else{
        return false;
    }
    return SendData();
}

//定义要读取的指令
bool omron::udpFinsCommand::MemoryAreaRead(omron::MemoryArea area, uint16_t address, uint8_t bit_position, uint16_t count)
{
    if(!ConnectStatus)
        return false;
    cmdFins[ICF] = (uint8_t)0x80;
    cmdFins[RSC] = (uint8_t)0x00;
    cmdFins[GCT] = (uint8_t)0x02;

    cmdFins[MC] = (uint8_t)0x01;
    cmdFins[SC] = (uint8_t)0x01;

    cmdFins[F_PARAM] = area;
    cmdFins[F_PARAM + 1] = (uint8_t)((address >> 8) & 0xFF);
    cmdFins[F_PARAM + 2] = (uint8_t)(address & 0xFF);
    cmdFins[F_PARAM + 3] = (uint8_t)(bit_position);
    cmdFins[F_PARAM + 4] = (uint8_t)((count >> 8) & 0xFF);
    cmdFins[F_PARAM + 5] = (uint8_t)(count & 0xFF);

    finsCommandLen = 18;
    return SendData();
}

//拼接要发送的fins指令
bool omron::udpFinsCommand::MemoryAreaWrite(const QByteArray &data)
{
    if(!ConnectStatus)
        return false;
    cmdFins[ICF] = (uint8_t)0x80;
    cmdFins[RSC] = (uint8_t)0x00;
    cmdFins[GCT] = (uint8_t)0x02;

    cmdFins[MC] = (uint8_t)0x01;
    cmdFins[SC] = (uint8_t)0x02;

    cmdFins.remove(12,cmdFins.size()-12);//初始化cmdFins为10位.
    if(data.size()>0&&(data.size()==7||data.size()==14)){
        cmdFins.append(data);
    }
    else{
        return false;
    }
    return SendData();
}

bool omron::udpFinsCommand::MemoryAreaWrite(omron::MemoryArea area, uint16_t address, uint8_t bit_position, uint16_t count, const QByteArray& data)
{
    if(!ConnectStatus)
        return false;
    cmdFins[ICF] = (uint8_t)0x80;
    cmdFins[RSC] = (uint8_t)0x00;
    cmdFins[GCT] = (uint8_t)0x02;

    cmdFins[MC] = (uint8_t)0x01;
    cmdFins[SC] = (uint8_t)0x02;

    cmdFins[F_PARAM] = area;
    cmdFins[F_PARAM + 1] = (uint8_t)((address >> 8) & 0xFF);
    cmdFins[F_PARAM + 2] = (uint8_t)(address & 0xFF);
    cmdFins[F_PARAM + 3] = (uint8_t)(bit_position);
    cmdFins[F_PARAM + 4] = (uint8_t)((count >> 8) & 0xFF);
    cmdFins[F_PARAM + 5] = (uint8_t)(count & 0xFF);

    finsCommandLen = 18;
    return SendData(data);
}


//发送fins指令
bool omron::udpFinsCommand::SendData(const QByteArray &data)
{
    //数据合并
    if(!ConnectStatus)
        return false;
    if(data.size()>0){
        cmdFins.append(data);
    }
    if(udpTransport->writeDatagram(cmdFins,QHostAddress(servIP),servPort)!=cmdFins.size())
        return false;

    return true;
}

//接收响应指令
bool omron::udpFinsCommand::ResvData()
{
    do{
        //_mutex.lock();
        finsResponseLen = udpTransport->pendingDatagramSize();//记录接收到的数据长度
        respFins.resize(finsResponseLen);//定义接受数组的大小
        udpTransport->readDatagram(respFins.data(),respFins.size(),&QHostAddress(servIP),&servPort);
        if(finsResponseLen==14||finsResponseLen>14){
            if(respFins.at(12)!=(uint8_t)0x00||respFins.at(13)!=(uint8_t)0x00){//检查错误码
                QByteArray error = respFins.mid(12,2);
                QString s(error.toHex());
                QString inf = "Command error :  ";inf.append(s);
                //qDebug()<<inf;
//                QMessageBox msg;
//                msg.setText(inf);
//                msg.exec();
                //return false;
            }
            if(finsResponseLen>14){//if has data
                respFinsData.clear();
                respFinsData.resize((finsResponseLen-14));
                for(int idx = 0; idx < (finsResponseLen-14); ++idx){//从响应帧中提取回复的数据
                    respFinsData[idx] = respFins[14+idx];
                }
            }
        }
        //_mutex.unlock();
    }
    while (udpTransport->hasPendingDatagrams());//阻塞，有数据到来
    return true;
}

QUdpSocket *omron::udpFinsCommand::getUdpSocket()
{
    return udpTransport;

}

QByteArray omron::udpFinsCommand::getcmdFinsData()
{
    return cmdFins;
}

QByteArray omron::udpFinsCommand::getRespFinsData()
{
    return respFinsData;
}

void omron::udpFinsCommand::clearRespFinsData()
{
    respFinsData.clear();
}

int omron::udpFinsCommand::getResponseDataLen()
{
    return respFinsData.size();
}

