#ifndef AUTODIALOG_H
#define AUTODIALOG_H

#include <QDialog>

namespace Ui {
class autoDialog;
}

class autoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit autoDialog(QWidget *parent = 0);
    ~autoDialog();

private slots:
    void on_ok_1_clicked();
    void on_ok_2_clicked();
    void on_ok_3_clicked();
    void on_ok_4_clicked();

signals:
    void sendAutoCmdToMainwindow(int input_motor,
                                 double input_step);
private:
    Ui::autoDialog *ui;
};

#endif // AUTODIALOG_H
