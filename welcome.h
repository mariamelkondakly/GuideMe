#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>

namespace Ui {
class welcome;
}

class welcome : public QWidget
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = nullptr);
    ~welcome();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::welcome *ui;
};

#endif // WELCOME_H
