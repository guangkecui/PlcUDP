#ifndef FINS_H
#define FINS_H

#include <QObject>
#include <QUdpSocket>
#include "udpfinscommand.h"
#include <QQueue>

#define DEFFAULT_PORT 9600
namespace omron {

    class Fins
    {

    private:
        udpFinsCommand* _finsCmd;
    public:
        bool isSendSuccess;//发送是否成功

        QQueue<QString> queryMsg;//需要定期查询的消息，size=1，没有用到

        Fins();
        ~Fins();
        bool Connect(uint16_t ClientPort);//连接udp-fins
        void Close();//关闭udp-fins
        void SetRemote(QString ipaddr,uint16_t port = DEFFAULT_PORT);//设置plc的ip和port
        //从plc读数据
        bool MemoryAreaRead(const QByteArray& datas);
        bool MemoryAreaRead(MemoryArea area,uint16_t address,uint8_t bit_position,uint16_t count);
        //向plc写数据
        bool MemoryAreaWrite(const QByteArray& datas);
        bool MemoryAreaWrite(MemoryArea area,uint16_t address,uint8_t bit_position,uint16_t count,const QByteArray& data);
        bool ReadPlcStatus(QString memoryArea);

        bool SendData(const QByteArray&data = QByteArray());
        bool ResvData();
        bool getConnectStatus();

        QByteArray WriteLabelToReadLabel(QByteArray label);
        QString WriteLabelToReadLabel2(QByteArray label);
        QByteArray lastByteSetZero(QString label);
        bool addQueryMsg(QString message);
        QUdpSocket * getUdpSocket();
        QByteArray getcmdFinsData();
        QByteArray getRespFinsData();
        void clearRespFinsData();
        int getResponseDataLen();
        static QByteArray hexstrToByteArray(const QString str);
        static QString byteArrayToHexstr(QByteArray data);
        static char convertHexChar(char ch);
        static QByteArray doubleToByteArray(double input);
        static double byteArrayToDouble(QByteArray input);
    };
}


#endif // FINS_H
