#ifndef EDITORIALOPTIONS_H
#define EDITORIALOPTIONS_H
#include <QPixmap>
#include <QWidget>
#include <QPalette>

namespace Ui {
class editorialFunctions;
}

class editorialFunctions : public QWidget
{
    Q_OBJECT

public:
    explicit editorialFunctions(QWidget *parent = nullptr);
    ~editorialFunctions();

private:
    Ui::editorialFunctions *ui;
};

#endif // EDITORIALOPTIONS_H
