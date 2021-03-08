#ifndef FINDPICFILE_H
#define FINDPICFILE_H

#include <QDialog>

namespace Ui {
class FindPicFile;
}

class FindPicFile : public QDialog
{
    Q_OBJECT

public:
    explicit FindPicFile(QWidget *parent = 0);
    ~FindPicFile();

private slots:
    void on_find_clicked();
    void on_buttonBox_accepted();

signals:
    void sendFilePathToMainwindow(QString path);
private:
    Ui::FindPicFile *ui;
    QString path;
};

#endif // FINDPICFILE_H
