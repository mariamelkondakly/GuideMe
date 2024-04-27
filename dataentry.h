#ifndef DATAENTRY_H
#define DATAENTRY_H

#include <QWidget>

namespace Ui {
class DataEntry;
}

class DataEntry : public QWidget
{
    Q_OBJECT

public:
    explicit DataEntry(QWidget *parent = nullptr);
    ~DataEntry();
    static int budget ;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_editingFinished();

private:
    Ui::DataEntry *ui;
};

#endif // DATAENTRY_H
