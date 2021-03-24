#ifndef OMRONPST_H
#define OMRONPST_H
/*定义所有初始化需要用到的参数*/
#include <vector>
#include <QVector3D>

using std::vector;
using std::pair;
namespace omron{
    #define PLCNX1P2_IP "192.168.250.1"
    #define PLCNX1P2_PORT "9600"
    #define HOSTPC_IP "192.168.250.5"
    #define HOSTPC_PORT "6666"
    #define SENSORFILEDIRECTORY "D:/HSRSL/SensorData/"
    #define SENSORFILE_1 "D:/HSRSL/SensorData/SensorData_1.txt"
    #define SENSORFILE_2 "D:/HSRSL/SensorData/SensorData_2.txt"
    #define SENSORFILE_3 "D:/HSRSL/SensorData/SensorData_3.txt"
    #define SENSORFILE_4 "D:/HSRSL/SensorData/SensorData_4.txt"
    #define LIMITINFORMATION1 "D:/HSRSL/LimitInformation/LimitInf1.txt"
    #define LIMITINFORMATION2 "D:/HSRSL/LimitInformation/LimitInf2.txt"
    #define POINTCLOUDSAVEDIR "D:/HSRSL/PointCloudData/"
    #define CameraConfiguration1_1 "D:/HSRSL/CameraConfiguration/CameraConfiguration1_1.mvcfg"
    #define CameraConfiguration1_2 "D:/HSRSL/CameraConfiguration/CameraConfiguration1_2.mvcfg"
    #define CameraConfiguration2_1 "D:/HSRSL/CameraConfiguration/CameraConfiguration2_1.mvcfg"
    #define CameraConfiguration2_2 "D:/HSRSL/CameraConfiguration/CameraConfiguration2_2.mvcfg"
    #define CameraConfiguration3_1 "D:/HSRSL/CameraConfiguration/CameraConfiguration3_1.mvcfg"
    #define CameraConfiguration3_2 "D:/HSRSL/CameraConfiguration/CameraConfiguration3_2.mvcfg"
    #define CameraConfiguration4_1 "D:/HSRSL/CameraConfiguration/CameraConfiguration4_1.mvcfg"
    #define CameraConfiguration4_2 "D:/HSRSL/CameraConfiguration/CameraConfiguration4_2.mvcfg"

    #define MOTORLABELLEN 7
    #define MANUALCONTINUOUS "31000001000101"//手动连续模式标志位
    #define MANUALSTEPPING   "31000002000101"//手动步进模式标志位

    #define MOTOR_1         "31000003000101"//电机1up标志位
    #define MOTORDOWN_1     "31000004000101"//电机1down标志位
    #define MOTORSTOP_1     "31000005000101"//电机1停止标志位
    #define MOTOR_2         "31000006000101"//电机2up标志位
    #define MOTORDOWN_2     "31000007000101"//电机2down标志位
    #define MOTORSTOP_2     "31000008000101"//电机2停止标志位
    #define MOTOR_3         "31000009000101"//电机3up标志位
    #define MOTORDOWN_3     "3100000A000101"//电机3down标志位
    #define MOTORSTOP_3     "3100000B000101"//电机3停止标志位
    #define MOTOR_4         "3100000D000101"//电机4up标志位
    #define MOTORDOWN_4     "3100000E000101"//电机4down标志位
    #define MOTORSTOP_4     "3100000F000101"//电机4停止标志位

    #define AUTOPTR "31000104000101"//自动控制标志位

    #define POWERMOTOR_1 "31000105000101"//电机1上电标志位
    #define POWERMOTOR_2 "31000106000101"//电机2上电标志位
    #define POWERMOTOR_3 "31000107000101"//电机3上电标志位
    #define POWERMOTOR_4 "31000108000101"//电机4上电标志位
    #define POSITIONMOTOR1 "82000A000004"//电机1轴的位置 D10
    #define POSITIONMOTOR2 "820014000004"//电机2轴的位置 D20
    #define POSITIONMOTOR3 "82001E000004"//电机3轴的位置 D30
    #define POSITIONMOTOR4 "820028000004"//电机4轴的位置 D40

    #define AUTO_START_1 "31000109000101"//电机1自动模式开启标志位
    #define AUTO_START_2 "3100010A000101"//电机2自动模式开启标志位
    #define AUTO_START_3 "3100010B000101"//电机3自动模式开启标志位
    #define AUTO_START_4 "3100010C000101"//电机4自动模式开启标志位

    #define AUTO_INPLACE_1 "3100010D0001"//电机1自动模式到位标志位
    #define AUTO_INPLACE_2 "3100010E0001"//电机2自动模式到位标志位
    #define AUTO_INPLACE_3 "3100010F0001"//电机3自动模式到位标志位
    #define AUTO_INPLACE_4 "310002010001"//电机4自动模式到位标志位

    #define AUTO_END_1 "310002020001"//电机1自动模式结束标志位
    #define AUTO_END_2 "310002030001"//电机2自动模式结束标志位
    #define AUTO_END_3 "310002040001"//电机3自动模式结束标志位
    #define AUTO_END_4 "310002050001"//电机4自动模式结束标志位

    #define BACKTOORIGIN_1 "310002060001"//电机1回原点命令
    #define BACKTOORIGIN_2 "310002070001"//电机2回原点命令
    #define BACKTOORIGIN_3 "310002080001"//电机1回原点命令
    #define BACKTOORIGIN_4 "310002090001"//电机2回原点命令
    #define ISORIGIN_1 "3100020A0001"//电机1是否在原点
    #define ISORIGIN_2 "3100020B0001"//电机2是否在原点
    #define ISORIGIN_3 "3100020C0001"//电机1是否在原点
    #define ISORIGIN_4 "3100020D0001"//电机2是否在原点
    #define ORIGINLINK_1 "310003010001"//电机1原点关联标志位
    #define ORIGINLINK_2 "310003020001"//电机2原点关联标志位
    #define ORIGINLINK_3 "310003030001"//电机3原点关联标志位
    #define ORIGINLINK_4 "310003040001"//电机4原点关联标志位
    #define VELOCITY_MANUAL "820032000004" //存储手动模式电机的速度信息，4个字节 D50

    #define SAFELOCATION_1 "310002060001"//电机1的安全位置标志位
    #define SAFELOCATION_2 "310003060001"//电机1的安全位置标志位
    #define SAFELOCATION_3 "310002080001"//电机1的安全位置标志位
    #define SAFELOCATION_4 "310003080001"//电机1的安全位置标志位

    #define MAXDISTANCE 4000 //  电机能移动的最大距离
    #define DISTANCE_FLAG "820064000004"//在此设置plc每次的步进值 D100

    #define CAMSLEN 6
    #define CAMADRESS "3100000C0003"//自动模式中，当PLC到位之后，将对应的相机置位
                                    //PC读取对应的数据，根据数据对对应的相机拍照
    //       | 02 | 00 00 05 | 00 03|
    //       | DM | 起始地址  | 长度  |
    //   0      0       0   PLC正在工作
    //   0      0       1   1号相机到位
    //   0      1       0   2号相机到位
    //   0      1       1   3号相机到位
    //   1      0       0   4号相机到位
    //   1      1       1   PLC停止工作

//相机当前的位置
#define CAMERA1POSITION "820000010002"
#define CAMERA2POSITION "820000030002"
#define CAMERA3POSITION "820000050002"
#define CAMERA4POSITION "820000070002"

    #define CAMERA1_1NAME 22989995//相机的序列号
    #define CAMERA1_2NAME 22989961
    #define CAMERA2_1NAME 22989983
    #define CAMERA2_2NAME 22991561
    #define CAMERA3_1NAME 23467905
    #define CAMERA3_2NAME 22990003
    #define CAMERA4_1NAME 22990004
    #define CAMERA4_2NAME 22991554

    #define DEFAULTIMAGEPATH "D:/HSRSL/Picture"

    #define CMDWAITTIME "0"//指令等待时长
    enum ModeType{
        Manual,
        ManualContinuous,//连续模式，按一下不会停，直到按下停止键
        ManualStepping,//步进型，按一下走一个步进值
        Automatic//自动控制型，每次电机自己步进1mm后便自动停止、拍照
    };
    enum CAMERALABEL{
        Camera1_1=1,
        Camera1_2=2,
        Camera2_1=3,
        Camera2_2=4,
        Camera3_1=5,
        Camera3_2=6,
        Camera4_1=7,
        Camera4_2=8
    };
struct CommandPacket{
    QByteArray cmd;//指令
    int motor;//正在工作的电机
    int dis;//步进距离信息
    int vec;//速度信息
};

//**保存限界信息***********//

struct LimitInf{
    vector<double> upperPart_rightMargin;//上半部分右边界
    vector<pair<double,double>> upperPart_linearEquation;//上半部分直线方程,<k,b>  z=k*y+b;
    vector<double> lowerPart_rightMargin;//下半部分右边界
    vector<pair<double,double>> lowerPart_linearEquation;//下半部分直线方程,<k,b>  z=k*y+b;
    double DividingLine;//上下两部分的分界线
    vector<QVector3D> limitPoints;//限界点坐标
};
}
#endif // OMRONPST_H
