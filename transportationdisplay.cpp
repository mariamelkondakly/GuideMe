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
#include "welcome.h"
using namespace std;

transportationDisplay::transportationDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::transportationDisplay)
{
    ui->setupUi(this);
    this->showMaximized();
    this->setWindowTitle("All Transportation Means Available");

    GUI_management::applyStylesheet(ui->Container, file_management::css_path+"/background.css");
    GUI_management::applyStylesheet(ui->label,file_management::css_path+"/titleLabel.css");
    GUI_management::applyStylesheet(ui->pushButton,file_management::css_path+"/PushButton.css");
    vector<QWidget *> widgets=transportationCreate();
    for (int i=0;i<widgets.size();i++) {
        ui->verticalLayout->addWidget(widgets[i]);
    }
    QPushButton *homeButton=new QPushButton("Return home");
    GUI_management::applyStylesheet(homeButton,file_management::css_path+"/PushButton.css");
    connect(homeButton, &QPushButton::clicked, this, &transportationDisplay::homeButtonClicked);
    QHBoxLayout *buttonLooks=new QHBoxLayout();
    QSpacerItem *horizontalSpacer = new QSpacerItem(900, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    buttonLooks->addSpacerItem(horizontalSpacer);
    buttonLooks->addWidget(homeButton);
    if(editorialFunctions::addFlag){
        ui->verticalLayout->addLayout(buttonLooks);

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
        int cost = file_management::transportationMap[EditingFunctionalities::selectedSource][EditingFunctionalities::selectedDestination][i].cost;
        QString transportationCost = QString::number(cost)+"EGP";
        QLabel *transportation=new QLabel(transportationName);
        QLabel *transportationc=new QLabel(transportationCost);
        QPushButton *selectbutton=new QPushButton("select");

        if(editorialFunctions::addFlag){
            selectbutton->setVisible(false);
        }
        selectbutton->setProperty("transportationName", transportationName);
        connect(selectbutton, &QPushButton::clicked, this, &transportationDisplay::handleSelectButtonClicked);
        horizontalLayout->addWidget(transportation);
        horizontalLayout->addWidget(transportationc);
        horizontalLayout->addWidget(selectbutton);
        item->setLayout(horizontalLayout);

        GUI_management::applyStylesheet(transportation, file_management::css_path+("/listLabel.css"));
        GUI_management::applyStylesheet(transportationc, file_management::css_path+("/costLabel.css"));
        GUI_management::applyStylesheet(selectbutton, file_management::css_path+("/PushButton.css"));
        GUI_management::applyStylesheet(item,file_management::css_path+("/transportationWidgets.css"));
        transportationWidgets.push_back(item);


    }
    if(file_management::transportationMap[EditingFunctionalities::selectedSource][EditingFunctionalities::selectedDestination].size()==0){
        QLabel *label_notfound=new QLabel("There is no way between the two cities");
        GUI_management::applyStylesheet(label_notfound, file_management::css_path+"/Result_Widgets.css");

      transportationWidgets.push_back(label_notfound);
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

            alert.setText("This is a deletion process and cannot be reverted.");
            alert.setInformativeText("Are you sure you want to delete?");
            alert.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            alert.setDefaultButton(QMessageBox::Cancel);
            int ret=alert.exec();

            QLabel *warning=new QLabel("This is last Transportation, it can't be deleted.");
            GUI_management::applyStylesheet(warning, file_management::css_path+("/warningLabel.css"));
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

void transportationDisplay::homeButtonClicked(){
    hide();
    welcome *window=new welcome();
    window->show();

}

void transportationDisplay::on_pushButton_clicked()
{
    hide();
    welcome *w=new welcome();
    w->show();
}

