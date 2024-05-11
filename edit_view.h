#ifndef EDIT_VIEW_H
#define EDIT_VIEW_H

#include <QWidget>

namespace Ui {
class edit_view;
}

class edit_view : public QWidget
{
    Q_OBJECT

public:
    explicit edit_view(QWidget *parent = nullptr);
    ~edit_view();

private slots:
    void on_pushButton_clicked();

\
private:
    Ui::edit_view *ui;
};

#endif // EDIT_VIEW_H
