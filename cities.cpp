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
#include "traversal.h"
#include "editingfunctionalities.h"
#include <iostream>
cities::cities(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cities)

{
    vector<string> vec_cities;
    ui->setupUi(this);
    GUI_management::applyStylesheet(ui->widget, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/specialBackground.css"));
    GUI_management::applyStylesheet(ui->label,file_management:: dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    if (Traversal::bfsflag==false){
        vec_cities=Traversal::dfs(file_management::transportationMap,EditingFunctionalities::selectedSource);
    }
    else{
        vec_cities=Traversal::bfs(file_management::transportationMap,EditingFunctionalities::selectedSource);
    }
    ::vector <QWidget*> vec=citiesDisplay(file_management::readFile(),vec_cities);
    for (int i=0 ; i<vec.size();i++) {
        ui->verticalLayout_2->addWidget(vec[i]);
    }
}

cities::~cities()
{
    delete ui;
}

vector<QWidget*> cities::citiesDisplay(vector<QPair<std::string,std::string>> vector,::vector<string> vec_cities){
    ::vector <QWidget*> vec;
    for(int i=0 ; i<vec_cities.size();i++){
        QWidget *containerWidget = new QWidget();
        QWidget *itemWidget = new QWidget();
        QString city = QString::fromStdString(vec_cities[i]);
        for(int j=0 ; j<vector.size();j++){
            if(vec_cities[i]==vector[j].first){
        QString path = QString::fromStdString(vector[i].second);
        containerWidget->setStyleSheet("QWidget { background-image: url(path); }");
        break;
             }
        }
        QHBoxLayout *layout = new QHBoxLayout();
        QLabel *cityName = new QLabel(city);
        QPushButton *select = new QPushButton("select");
        layout->addWidget(cityName);
        layout->addWidget(select);

        itemWidget->setLayout(layout);

        QVBoxLayout *layout2 = new QVBoxLayout();
        layout2->addWidget(itemWidget);

        vec.push_back(containerWidget);
        cout<<vec.size();
        GUI_management::applyStylesheet(cityName,file_management:: dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
        GUI_management::applyStylesheet(select,file_management:: dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
        GUI_management::applyStylesheet(itemWidget, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));

    }
    return vec;
}
