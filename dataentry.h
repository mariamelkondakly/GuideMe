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
    static int number_visited_governates;
    bool check_budget;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_editingFinished();

    void on_back1putton_clicked();


private:
    Ui::DataEntry *ui;
};

#endif // DATAENTRY_H
