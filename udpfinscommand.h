#ifndef UDPFINSCOMMAND_H
#define UDPFINSCOMMAND_H
#include<QUdpSocket>
#include"ifinscommand.h"
#include <QMutex>

using namespace std;
namespace omron{
class udpFinsCommand : public IFinsCommand
{
private:
    int finsCommandLen =0;
    int finsResponseLen=0;
    QByteArray respFins;

    QByteArray cmdFins;
    QUdpSocket * udpTransport;
    QString servIP;
    uint16_t servPort;
    QString clientIP;
    uint16_t clientPort;
    QMutex _mutex;
public:
    QByteArray respFinsData;
    udpFinsCommand(uint8_t ServiceID=0x00);
    ~udpFinsCommand();
    bool ConnectStatus;
    virtual bool Connect(uint16_t ClientPort);//绑定本机端口，显示本机ip
    virtual void Close();//关闭udp
    virtual void SetRemote(QString ipaddr,uint16_t port);//设置远端(plc)的IP和port
    virtual bool MemoryAreaRead(const QByteArray& data);
    virtual bool MemoryAreaRead(MemoryArea area,uint16_t address,uint8_t bit_position,uint16_t count);
    virtual bool MemoryAreaWrite(const QByteArray& data);
    virtual bool MemoryAreaWrite(MemoryArea area,uint16_t address,uint8_t bit_position,uint16_t count,const QByteArray& data);
    virtual bool SendData(const QByteArray&data = QByteArray());
    virtual bool ResvData();
    QUdpSocket * getUdpSocket();
    virtual QByteArray getcmdFinsData();
    virtual QByteArray getRespFinsData();
    virtual void clearRespFinsData();
    virtual int getResponseDataLen();
};
}
#endif // UDPFINSCOMMAND_H
