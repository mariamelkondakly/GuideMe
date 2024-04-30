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
using namespace std;
cities::cities(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cities)

{
    vector<string> vec_cities;
    ui->setupUi(this);

    GUI_management::applyStylesheet(ui->scrollArea,file_management::css_path+"/specialBackground.css");
    GUI_management::applyStylesheet(ui->label,file_management::css_path+"/titleLabel.css");
    if (Traversal::bfsflag==false){
        vec_cities=Traversal::dfs(file_management::transportationMap,EditingFunctionalities::selectedSource);
    }
    else{
        vec_cities=Traversal::bfs(file_management::transportationMap,EditingFunctionalities::selectedSource);
    }
    ::vector <QWidget*> vec = citiesDisplay(file_management::readFile(),vec_cities);
    for (int i=0 ; i<vec.size();i++) {
        ui->verticalLayout->addWidget(vec[i]);
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
                QString ayHaga="";
                ayHaga+="QWidget { background-image: url(";
                ayHaga+=path;
                ayHaga+="); height:200px; background-size:cover;}";
                containerWidget->setStyleSheet(ayHaga);
                break;
             }
        }
        QHBoxLayout *layout = new QHBoxLayout();
        QLabel *cityName = new QLabel(city);
        QPushButton *select = new QPushButton("select");
        layout->addWidget(cityName);
        layout->addWidget(select);
        itemWidget->setLayout(layout);
        QVBoxLayout *layout2=new QVBoxLayout();
        QSpacerItem *verticalSpacer = new QSpacerItem(20, 900, QSizePolicy::Minimum, QSizePolicy::Expanding);
        layout2->addSpacerItem(verticalSpacer);
        layout2->addWidget(itemWidget);
        containerWidget->setLayout(layout2);

        vec.push_back(containerWidget);

        GUI_management::applyStylesheet(cityName,file_management::css_path+"/titleLabel.css");
        GUI_management::applyStylesheet(select,file_management::css_path+"/PushButton.css");
        GUI_management::applyStylesheet(itemWidget, file_management::dir.relativeFilePath("/transportationWidgets.css"));

    }
    return vec;
}
