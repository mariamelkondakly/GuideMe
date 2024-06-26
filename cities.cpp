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
#include <QObject>
#include "result.h"
using namespace std;
vector<string> vec_cities;

cities::cities(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cities)

{

    ui->setupUi(this);
    this->showMaximized();
    this->setWindowTitle("Cities");
    GUI_management::applyStylesheet(ui->scrollAreaWidgetContents,file_management::css_path+"/specialBackground.css");
    GUI_management::applyStylesheet(ui->label,file_management::css_path+"/titleLabel.css");
    if (Traversal::bfsflag==false){
        vec_cities=Traversal::dfs(EditingFunctionalities::selectedSource);
    }
    else{
        vec_cities=Traversal::bfs(EditingFunctionalities::selectedSource);
    }
    ::vector <QWidget*> vec = citiesDisplay(file_management::readFile(),vec_cities);
    cout<<"Vec_cities size "<<vec_cities.size()<<endl;
    cout<<"Vec size "<<vec.size()<<endl;
    for (int i=0 ; i<vec.size();i++) {
        ui->verticalLayout->addWidget(vec[i]);
        ui->verticalLayout->setStretch(i,5);
    }
    Traversal::unvisited(EditingFunctionalities::selectedSource);
}

cities::~cities()
{
    delete ui;
}

vector<QWidget*> cities::citiesDisplay(vector<QPair<std::string,std::string>> vector,::vector<string> vec_cities){
    ::vector <QWidget*> vec;
    for(int i = 1 ; i<vec_cities.size();i++){
        QWidget *containerWidget = new QWidget();
        QWidget *itemWidget = new QWidget();
        QString city = QString::fromStdString(vec_cities[i]);
        QLabel *imgLabel = new QLabel();
        for(int j=0 ; j<vector.size();j++){
            if(vec_cities[i]==vector[j].first){
                QString path = QString::fromStdString(vector[j].second);
                // QString ayHaga="";
                // ayHaga+="QWidget { background-image: url(";
                // ayHaga+=path;
                // ayHaga+=");}";
                imgLabel->setPixmap(path);
                imgLabel->setScaledContents(true);
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
        QSpacerItem *verticalSpacer = new QSpacerItem(20, 900, QSizePolicy::Expanding, QSizePolicy::Expanding);
        layout2->addWidget(imgLabel);

        layout2->addSpacerItem(verticalSpacer);
        layout2->addWidget(itemWidget);
        containerWidget->setLayout(layout2);

        select->setProperty("cityName", city);
        connect(select, &QPushButton::clicked, this, &cities::handleSelectButtonClicked);

        vec.push_back(containerWidget);

        GUI_management::applyStylesheet(cityName,file_management::css_path+"/titleLabel.css");
        GUI_management::applyStylesheet(select,file_management::css_path+"/PushButton.css");
        GUI_management::applyStylesheet(itemWidget, file_management::css_path+("/transportationWidgets.css"));

    }
    return vec;
}
void cities::handleSelectButtonClicked() {

    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        QString cityName = clickedButton->property("cityName").toString();
        EditingFunctionalities::selectedDestination = cityName.toStdString();
        hide();
        Result *window=new Result();
        window->show();
    }

}

