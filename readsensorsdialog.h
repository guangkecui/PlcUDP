#ifndef READSENSORSDIALOG_H
#define READSENSORSDIALOG_H

#include <QDialog>
#include "sensorunit.h"
#include "omronpst.h"
using namespace omron;
/**********************************************
  函数名称：
  输入参数：
  输出参数：
  函数功能：传感器的读入文件工作
**********************************************/
namespace Ui {
class ReadSensorsDialog;
}

class ReadSensorsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReadSensorsDialog(sensorunit* InputSenUnit = nullptr, QWidget *parent = 0);
    ~ReadSensorsDialog();

private slots:
    void on_open_1_clicked();

    void on_open_2_clicked();

    void on_open_3_clicked();

    void on_open_4_clicked();

    void on_buttonBox_accepted();

private:
    Ui::ReadSensorsDialog *ui;
    sensorunit* m_SensorUnit;
};

#endif // READSENSORSDIALOG_H
