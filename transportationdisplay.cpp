#include "transportationdisplay.h"
#include "ui_transportationdisplay.h"
#include "gui_management.h"
#include "file_management.h"
#include "editingfunctionalities.h"
#include <QLabel>
#include <QPushButton>
#include<iostream>
using namespace std;

transportationDisplay::transportationDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::transportationDisplay)
{
    ui->setupUi(this);
    GUI_management::applyStylesheet(ui->container, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/background.css"));
    GUI_management::applyStylesheet(ui->label, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    vector<QWidget *> widgets=transportationCreate();
    cout<<widgets.size();
    for (int i=0;i<widgets.size();i++) {
        ui->verticalLayout->addWidget(widgets[i]);
    }

}

transportationDisplay::~transportationDisplay()
{
    delete ui;

}

 vector<QWidget *>transportationDisplay::transportationCreate()
{
    vector<QWidget *> transportationWidgets;
    for(int i=0;i<file_management::transportationMap[EditingFunctionalities::selectedSource][EditingFunctionalities::selectedDestination].size();i++){
        QWidget *item=new QWidget();
        QHBoxLayout *horizontalLayout = new QHBoxLayout();
        QString transportationName = QString::fromStdString(file_management::transportationMap[EditingFunctionalities::selectedSource][EditingFunctionalities::selectedDestination][i].transportation);
        QLabel *transportation=new QLabel(transportationName);
        QPushButton *selectbutton=new QPushButton("select");
        horizontalLayout->addWidget(transportation);
        horizontalLayout->addWidget(selectbutton);
        item->setLayout(horizontalLayout);
        GUI_management::applyStylesheet(transportation, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/normalLabels.css"));
        GUI_management::applyStylesheet(selectbutton, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
        GUI_management::applyStylesheet(item,file_management::dir.relativeFilePath("/GuideMe/CSS_styling/transportationWidgets.css"));


        transportationWidgets.push_back(item);
    }
    return transportationWidgets;
}
