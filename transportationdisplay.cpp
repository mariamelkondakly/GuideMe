#include "transportationdisplay.h"
#include "ui_transportationdisplay.h"
#include "gui_management.h"
#include "file_management.h"
#include "editingfunctionalities.h"
#include "editorialOptions.h"
#include <QLabel>
#include <QPushButton>
#include<iostream>
#include <QMessageBox>
#include "updatingtransportation.h"
using namespace std;

transportationDisplay::transportationDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::transportationDisplay)
{
    ui->setupUi(this);
    GUI_management::applyStylesheet(ui->container, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/background.css"));
    GUI_management::applyStylesheet(ui->label, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    vector<QWidget *> widgets=transportationCreate();
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
        selectbutton->setProperty("transportationName", transportationName);
        connect(selectbutton, &QPushButton::clicked, this, &transportationDisplay::handleSelectButtonClicked);
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
void transportationDisplay::handleSelectButtonClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender()); // Get the button that was clicked
    QString transportationName = clickedButton->property("transportationName").toString();
    EditingFunctionalities::selectedTransportation = transportationName.toStdString();
    if (clickedButton) {
        if(editorialFunctions::deleteFlag){
            QMessageBox alert;

            alert.setText("This is a deletion prrocess and cannot be reverted");
            alert.setInformativeText("Are you sure you want to delete?");
            alert.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            alert.setDefaultButton(QMessageBox::Cancel);
            int ret=alert.exec();

            QLabel *warning=new QLabel("This is last Transportation. It can't be deleted.");
            GUI_management::applyStylesheet(warning, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/warningLabel.css"));
            warning->setVisible(false);
            ui->verticalLayout->addWidget(warning);


            if(ret == QMessageBox::Yes){
                if(!EditingFunctionalities::deleting()){

                    warning->setVisible(true);
                }
                else{
                    warning->setVisible(false);
                    hide();
                    transportationDisplay *window=new transportationDisplay();
                    window->show();
                }


            }
        }
        else{

            hide();
            updatingTransportation * window=new updatingTransportation();
            window->show();
        }
    }
}
