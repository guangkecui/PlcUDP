#include "fins.h"

omron::Fins::Fins()
{
    _finsCmd = new udpFinsCommand();
    isSendSuccess = false;

}

omron::Fins::~Fins()
{
    if(_finsCmd!=nullptr)
        delete _finsCmd;
}

bool omron::Fins::Connect(uint16_t ClientPort)
{
    return _finsCmd->Connect(ClientPort);
}

void omron::Fins::Close()
{
    _finsCmd->Close();
}

void omron::Fins::SetRemote(QString ipaddr, uint16_t port)
{
    _finsCmd->SetRemote(ipaddr,port);
}

bool omron::Fins::MemoryAreaRead(const QByteArray &datas)
{
    return _finsCmd->MemoryAreaRead(datas);
}

bool omron::Fins::MemoryAreaRead(omron::MemoryArea area, uint16_t address, uint8_t bit_position, uint16_t count)
{
    return _finsCmd->MemoryAreaRead(area,address,bit_position,count);
}

bool omron::Fins::MemoryAreaWrite(const QByteArray &datas)
{
    return _finsCmd->MemoryAreaWrite(datas);
}

bool omron::Fins::MemoryAreaWrite(omron::MemoryArea area, uint16_t address, uint8_t bit_position, uint16_t count, const QByteArray& data)
{
    return _finsCmd->MemoryAreaWrite(area,address,bit_position,count,data);
}

bool omron::Fins::ReadPlcStatus(QString memoryArea)
{
    QByteArray area = hexstrToByteArray(memoryArea);
    return _finsCmd->MemoryAreaRead(area);
}

bool omron::Fins::SendData(const QByteArray &data)
{
    return _finsCmd->SendData(data);
}

bool omron::Fins::ResvData()
{
    return _finsCmd->ResvData();
}

bool omron::Fins::getConnectStatus()
{
    return _finsCmd->ConnectStatus;
}

//把电机的写标签改成读标签
//02 | 00 00 05 | 00 01 | 01  -->MotorWriteLabel
//02 | 00 00 05 | 00 01       -->MotorReadLabel
QString omron::Fins::WriteLabelToReadLabel2(QByteArray label)
{
    QByteArray readLabel;readLabel.resize(6);
    for(int i=0;i<6;++i){
        readLabel[i] = label[i];
    }
    return byteArrayToHexstr(readLabel);
}



QByteArray omron::Fins::WriteLabelToReadLabel(QByteArray label)
{
    QByteArray readLabel;readLabel.resize(6);
    for(int i=0;i<6;++i){
        readLabel[i] = label[i];
    }
    return readLabel;
}

/**********************************************
  函数名称：lastByteSetZero
  输入参数：label :16进制的字符串
  输出参数：
  函数功能：将字符串的最后的”“0x01”变为"0x00"
**********************************************/
QByteArray omron::Fins::lastByteSetZero(QString label)
{
    QByteArray res = this->hexstrToByteArray(label);
    res[res.size()-1] = (uint8_t)0x00;
    return res;
}

//向queryMsg队列添加定时器需要轮询的消息
//必须提前判断queryMsg大小是否为1，必须等queryMsg里面的信息发送完成之后且
//发送成功之后才可添加
bool omron::Fins::addQueryMsg(QString message)
{
    if(!queryMsg.empty()){
        qDebug("之前的消息还未成功轮询 " );
        return false;
    }
    else{
        queryMsg.push_back(message);
    }
    return true;
}

QUdpSocket *omron::Fins::getUdpSocket()
{
    return _finsCmd->getUdpSocket();
}

QByteArray omron::Fins::getcmdFinsData()
{
    return _finsCmd->getcmdFinsData();
}

QByteArray omron::Fins::getRespFinsData()
{
    return _finsCmd->getRespFinsData();
}

void omron::Fins::clearRespFinsData()
{
    _finsCmd->clearRespFinsData();
}

int omron::Fins::getResponseDataLen()
{
    return _finsCmd->getResponseDataLen();
}

QByteArray omron::Fins::hexstrToByteArray(const QString str)
{
    QByteArray senddata;
    int hexdata, lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len / 2);
    char lstr, hstr;

    for (int i = 0; i < len;) {
        hstr = str.at(i).toLatin1();

        if (hstr == ' ') {
            i++;
            continue;
        }

        i++;

        if (i >= len) {
            break;
        }

        lstr = str.at(i).toLatin1();
        hexdata = convertHexChar(hstr);
        lowhexdata = convertHexChar(lstr);

        if ((hexdata == 16) || (lowhexdata == 16)) {
            break;
        } else {
            hexdata = hexdata * 16 + lowhexdata;
        }

        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}

QString omron::Fins::byteArrayToHexstr(QByteArray data)
{
    QString temp = "";
    QString hex = data.toHex();//十六进制显示，如0XFF显示为“FF”

    for (int i = 0; i < hex.length(); i = i + 2) {
        temp += hex.mid(i, 2) + " ";
    }

    return temp.trimmed().toUpper();
}

char omron::Fins::convertHexChar(char ch)
{
    if ((ch >= '0') && (ch <= '9')) {
        return ch - 0x30;
    } else if ((ch >= 'A') && (ch <= 'F')) {
        return ch - 'A' + 10;
    } else if ((ch >= 'a') && (ch <= 'f')) {
        return ch - 'a' + 10;
    } else {
        return (-1);
    }
}

QByteArray omron::Fins::doubleToByteArray(double input)
{
    QByteArray s;
    s.resize(8);
    memcpy(s.data(),&input,sizeof(input));
    for(int i=0;i<s.size();){
        char temp = s[i];
        s[i] = s[i+1];
        s[i+1] = temp;
        i+=2;
    }
    return s;
}

double omron::Fins::byteArrayToDouble(QByteArray input)
{
    QByteArray s = input;
    for(int i=0;i<s.size();){
        char temp = s[i];
        s[i] = s[i+1];
        s[i+1] = temp;
        i+=2;
    }
    double* f = nullptr;
    f = (double*)s.data();
    return *f;
}
