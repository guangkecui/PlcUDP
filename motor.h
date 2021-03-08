#ifndef MOTOR_H
#define MOTOR_H
#include <QByteArray>

namespace omron {
    class Motor
    {
    private:
        //02 | 00 00 05 | 00 01 | 01  -->MotorLabel
        //02 | 00 00 05 | 00 01 | 01  -->MOveUp
        //02 | 00 00 05 | 00 01 | 00  -->MOveUp Stop
        //02 | 00 00 06 | 00 01 | 01  -->MOveDown
        //02 | 00 00 06 | 00 01 | 00  -->MOveDown Stop
        QByteArray MotorLabel;
        bool isPower;
    public:
        explicit Motor(const QByteArray& motorlabel = QByteArray());

        /*电机向上移动*/
        QByteArray MoveUp();
        /*电机向上移动标志位置0*/
        QByteArray MoveUpZero();
        /*电机向上移动停止*/
        QByteArray MoveUpStop();
        /*电机向上移动停止置0*/
        QByteArray MoveUpStopZero();
        /*电机向下移动*/
        QByteArray MoveDown();
        /*电机向下移动置0*/
        QByteArray MoveDownZero();
        /*电机向上移动停止*/
        QByteArray MoveDownStop();
        /*电机向上移动停止置0*/
        QByteArray MoveDownStopZero();
        //电机是否已经上电
        bool ispower(void){return isPower;}
        void setPower(bool flag = true){isPower = flag;}
        QByteArray lastByteSetZero(QByteArray input);
        QByteArray getMotorLabel();
        void setMotorLabel(const QByteArray& motorlabel);
    };
}


#endif // MOTOR_H
