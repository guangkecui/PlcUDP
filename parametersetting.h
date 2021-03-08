#ifndef PARAMETERSETTING_H
#define PARAMETERSETTING_H

#include <QDialog>

namespace Ui {
class ParameterSetting;
}

class ParameterSetting : public QDialog
{
    Q_OBJECT

public:
    explicit ParameterSetting(QWidget *parent = 0);
    ~ParameterSetting();
    void unitUi(void);

    QString getMotor1Text();
    QString getMotor2Text();
    QString getMotor3Text();
    QString getMotor4Text();
    QString getAutoptrText();
    QString getContinuousPtrText();
    QString getStepPtrText();
    QString getCamsptrText();
    QString getCmdWaitTime();

    QString getPLCIpText();
    QString getPLCPortText();
    QString getPCPortText();

    QString getPicturePath();
signals:
    void updatePar(void);
private slots:
    void on_buttonBox_accepted();

    void on_scanPath_clicked();

private:
    Ui::ParameterSetting *ui;
};

#endif // PARAMETERSETTING_H
