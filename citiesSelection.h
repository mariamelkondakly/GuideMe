#ifndef CITIESSELECTION_H
#define CITIESSELECTION_H
#include <QWidget>

namespace Ui {
class citiesSelection;
}

class citiesSelection : public QWidget
{
    Q_OBJECT

public:
    explicit citiesSelection(QWidget *parent = nullptr);
    ~citiesSelection();

private:
    Ui::citiesSelection *ui;
};

#endif // CITIESSELECTION_H
