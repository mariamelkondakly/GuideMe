#include "cities.h"
#include "ui_cities.h"
#include <QWidget>
#include "file_management.h"
#include <QPair>
#include <vector>
#include <QLabel>
#include <QPushButton>
#include <QtWidgets>
#include "gui_management.h"
cities::cities(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cities)
{
    ui->setupUi(this);
    QDir dir("C:/Users/MARIAM/qt Projects"); //change it to make it run on your pc
    GUI_management::applyStylesheet(ui->widget, dir.relativeFilePath("/GuideMe/CSS_styling/specialBackground.css"));
    GUI_management::applyStylesheet(ui->label, dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    // foreach (vector<QWidget*> v , citiesDisplay(vector<QWidget*>)) {

    // }
}

cities::~cities()
{
    delete ui;
}

vector<QWidget*> citiesDisplay(vector<QPair<std::string,std::string>> vector){
    ::vector <QWidget*> vec;

    for(int i=0 ; i<vector.size();i++){
        QWidget *containerWidget = new QWidget();
        QWidget *itemWidget = new QWidget();

        QString city = QString::fromStdString(vector[i].first);
        QString path = QString::fromStdString(vector[i].second);

        QLabel *cityName = new QLabel(city);
        QPushButton *select = new QPushButton("select");
        containerWidget->setStyleSheet("QWidget { background-image: url(path); }");
        QHBoxLayout *layout = new QHBoxLayout();

        layout->addWidget(cityName);
        layout->addWidget(select);

        itemWidget->setLayout(layout);

        QVBoxLayout *layout2 = new QVBoxLayout();
        layout2->addWidget(itemWidget);

        vec.push_back(containerWidget);

        QDir dir("C:/Users/MARIAM/qt Projects"); //change it to make it run on your pc
        GUI_management::applyStylesheet(cityName, dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
        GUI_management::applyStylesheet(select, dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
        GUI_management::applyStylesheet(itemWidget, dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));

    }
    return vec;
}
