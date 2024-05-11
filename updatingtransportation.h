#ifndef UPDATINGTRANSPORTATION_H
#define UPDATINGTRANSPORTATION_H
#include "file_management.h"
#include <QWidget>

namespace Ui {
class updatingTransportation;
}

class updatingTransportation : public QWidget
{
    Q_OBJECT

public:
    explicit updatingTransportation(QWidget *parent = nullptr);
    ~updatingTransportation();

private slots:
    void on_Update_clicked();

private:
    Ui::updatingTransportation *ui;
};

#endif // UPDATINGTRANSPORTATION_H
