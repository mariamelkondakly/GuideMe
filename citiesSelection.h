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

private slots:
    void on_source_editingFinished();

    void on_destination_editingFinished();

    void on_next_clicked();

private:
    Ui::citiesSelection *ui;
};

#endif // CITIESSELECTION_H
