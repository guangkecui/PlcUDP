#ifndef MANUALMODEDIALOG_H
#define MANUALMODEDIALOG_H

#include <QDialog>
#include"motorunit.h"

namespace Ui {
class manualmodeDialog;
}

class manualmodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit manualmodeDialog(omron::MotorUnit* motors,QWidget *parent = 0);
    ~manualmodeDialog();
signals:
    void message(QString msg);
    void sendCommand(QByteArray cmd,double dis,double vec,int _workingMode,int motor);
    void sendCameraCmd(uchar cmd);
    void sendMotorToPosition(int motor,double position);
private slots:
    void uintMaunal();

    void on_motor1_up_clicked();

    void on_motor1_down_clicked();

    void on_motor2_up_clicked();

    void on_motor2_down_clicked();

    void on_motor3_up_clicked();

    void on_motor3_down_clicked();

    void on_motor4_up_clicked();

    void on_motor4_down_clicked();

    void on_camera_1_clicked();

    void on_camera_2_clicked();

    void on_camera_3_clicked();

    void on_camera_4_clicked();

    void on_motor1upStop_clicked();

    void on_motor1downStop_clicked();

    void on_motor2upStop_clicked();

    void on_motor2downStop_clicked();

    void on_motor3upStop_clicked();

    void on_motor3downStop_clicked();

    void on_motor4upStop_clicked();

    void on_motor4downStop_clicked();

    void on_stepping_toggled(bool checked);

    void on_continuous_toggled(bool checked);

    void on_startToPosition_1_clicked();

    void on_startToPosition_2_clicked();

    void on_startToPosition_3_clicked();

    void on_startToPosition_4_clicked();

   // void on_pushButton_2_clicked();

private:
    Ui::manualmodeDialog *ui;
    omron::MotorUnit* m_motors;
    omron::ModeType workingMode;//连续模式还是步进模式
};

#endif // MANUALMODEDIALOG_H
