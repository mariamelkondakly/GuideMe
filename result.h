#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include <QLabel>
#include "file_management.h"
#include "gui_management.h"
#include <deque>>
#include <qstring.h>
#include <set>
#include <vector>
namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT
    set<pair<int, string>> allpaths;

public:
    explicit Result(QWidget *parent = nullptr);
    void searching_roads(string node,
                         string distinatation,
                         unordered_map<string, bool> &vistited,
                         deque<pair<pair<string, string>, pair<string, int>>> &road);
    void display_roads();
    ~Result();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Result *ui;
};

#endif // RESULT_H
