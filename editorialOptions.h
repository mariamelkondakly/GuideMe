#ifndef EDITORIALOPTIONS_H
#define EDITORIALOPTIONS_H
#include <QPixmap>
#include <QWidget>
#include <QPalette>
#include "citiesSelection.h"


namespace Ui {
class editorialFunctions;
}

class editorialFunctions : public QWidget
{
    Q_OBJECT

public:
    explicit editorialFunctions(QWidget *parent = nullptr);
    ~editorialFunctions();
    static bool deleteFlag;
    static bool addFlag;
    static bool editFlag;

private slots:
    void on_DeleteButton_clicked();

    void on_EditButton_clicked();

    void on_AddButton_clicked();

    void on_back1putton_clicked();

private:
    Ui::editorialFunctions *ui;
};

#endif // EDITORIALOPTIONS_H
