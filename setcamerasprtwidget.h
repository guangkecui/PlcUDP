#ifndef SETCAMERASPRTWIDGET_H
#define SETCAMERASPRTWIDGET_H
#include "GenICam/System.h"
#include <QWidget>
#include "omronpst.h"


namespace Ui {
class SetCamerasPrtWidget;
}

class SetCamerasPrtWidget : public QWidget
{
    Q_OBJECT

public:

    explicit SetCamerasPrtWidget(Dahua::Infra::TVector<Dahua::GenICam::ICameraPtr> CameraPtrList,
                                 QWidget *parent = 0);
    ~SetCamerasPrtWidget();
    void unitUi(void);
private:
    Ui::SetCamerasPrtWidget *ui;
    Dahua::Infra::TVector<Dahua::GenICam::ICameraPtr> m_vCameraPtrList;	// 发现的相机列表 | List of cameras found

};

#endif // SETCAMERASPRTWIDGET_H
