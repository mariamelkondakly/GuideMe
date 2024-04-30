#ifndef CITIES_H
#define CITIES_H

#include <QWidget>
#include <vector>
#include <QPair>
// #include <Qstring>
using namespace std;

namespace Ui {
class cities;
}

class cities : public QWidget
{
    Q_OBJECT

public:
    explicit cities(QWidget *parent = nullptr);
    vector<QWidget*> citiesDisplay(vector<QPair<std::string,std::string>>,vector<string> vec_cities);

    ~cities();

public slots:
    void handleSelectButtonClicked();


private:
    Ui::cities *ui;
};

#endif // CITIES_H
