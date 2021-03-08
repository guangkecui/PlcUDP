#ifndef IFINSCOMMAND_H
#define IFINSCOMMAND_H
#include<QString>
#include <QByteArray>

namespace omron {

enum FinsCommandField:unsigned char
{
    ICF,
    RSC,
    GCT,
    DNA,
    DA1,
    DA2,
    SNA,
    SA1,
    SA2,
    PSID,
    MC,//读写命令
    SC,
    F_PARAM = 12,//读写区域标号
};
enum MemoryArea : unsigned char
{
    CIO_Bit = 0x30,
    WR_Bit = 0x31,
    HR_Bit = 0x32,
    AR_Bit = 0x33,
    CIO_Bit_FS = 0x70,
    WR_Bit_FS = 0x71,
    HR_Bit_FS = 0x72,
    CIO = 0xB0,
    WR = 0xB1,
    HR = 0xB2,
    AR = 0xB3,
    CIO_FS = 0xF0,
    WR_FS = 0xF1,
    HR_FS = 0xF2,
    TIM = 0x09,
    CNT = 0x09,
    TIM_FS = 0x49,
    CNT_FS = 0x49,
    TIM_PV = 0x89,
    CNT_PV = 0x89,
    DM_Bit = 0x02,
    DM = 0x82,
    TK_Bit = 0x06,
    TK = 0x46
};
enum FinsCommands
{
    MemoryAreaRead,
    MemoryAreaWrite,
    ControllerDataRead,
};
class IFinsCommand
    {
    public:
        explicit IFinsCommand(){}
        virtual ~IFinsCommand(){}
        virtual bool Connect(uint16_t ClientPort)=0;
        virtual void Close()=0;
        virtual void SetRemote(QString ipaddr,uint16_t port)=0;
        virtual bool MemoryAreaRead(MemoryArea area,uint16_t address,uint8_t bit_position,uint16_t count)=0;
        virtual bool MemoryAreaWrite(const QByteArray& data)=0;
        virtual bool MemoryAreaWrite(MemoryArea area,uint16_t address,uint8_t bit_position,uint16_t count,
                                     const QByteArray& data)=0;
        virtual QByteArray getcmdFinsData()=0;
        virtual QByteArray getRespFinsData()=0;
        virtual int getResponseDataLen()=0;
    };
}


#endif // IFINSCOMMAND_H
