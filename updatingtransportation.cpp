#include "updatingtransportation.h"
#include "ui_updatingtransportation.h"
#include "gui_management.h"
#include "editingfunctionalities.h"
#include "transportationdisplay.h"

updatingTransportation::updatingTransportation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::updatingTransportation)
{
    ui->setupUi(this);
    GUI_management::applyStylesheet(ui->widget, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/background.css"));
    GUI_management::applyStylesheet(ui->title, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    GUI_management::applyStylesheet(ui->Update, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->TransportationCost, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/textfields.css"));
    GUI_management::applyStylesheet(ui->TransportationType, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/textfields.css"));
    GUI_management::applyStylesheet(ui->TransportationCostLabel, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/normalLabels.css"));
    GUI_management::applyStylesheet(ui->TransportationTypeLabel, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/normalLabels.css"));
    GUI_management::applyStylesheet(ui->TransportationTypeLabel, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/warningLabel.css"));

    ui->warning->setVisible(false);
}

updatingTransportation::~updatingTransportation()
{
    delete ui;
}


void updatingTransportation::on_Update_clicked()
{
    bool checkDigit = false, is_exist = false;
    int cost;
    if(ui->TransportationCost->text() == "" || ui->TransportationType->text() == ""){
        ui->warning->setText("Please enter valid Data!");
        ui->warning->setVisible(true);
    }
    else{
        for (Edge& edge : file_management::transportationMap[EditingFunctionalities::selectedSource][EditingFunctionalities::selectedDestination]){
            if(ui->TransportationType->text().toStdString() == edge.transportation){
                ui->warning->setText("This transportation already exists!");
                ui->warning->setVisible(true);
                is_exist = true;
            }
        }
        for(int i=0;i<ui->TransportationCost->text().size() ;i++ ){
            if(! isdigit(ui->TransportationCost->text().toStdString()[i]) ){
                checkDigit = true;
                ui->warning->setText("Please enter valid cost number!");
                ui->warning->setVisible(true);
                break;
            }
        }
        if(!checkDigit && is_exist == false){
            cost = stoi(ui->TransportationCost->text().toStdString());
            for (Edge& edge : file_management::transportationMap[EditingFunctionalities::selectedSource][EditingFunctionalities::selectedDestination]){
                if(edge.transportation == EditingFunctionalities::selectedTransportation){
                    edge.transportation = ui->TransportationType->text().toStdString();
                    edge.cost = cost;
                    hide();
                    transportationDisplay *transportationDisplayScene=new transportationDisplay();
                    transportationDisplayScene->show();
                }
            }
            for (Edge& edge : file_management::transportationMap[EditingFunctionalities::selectedDestination][EditingFunctionalities::selectedSource]){
                if(edge.transportation == EditingFunctionalities::selectedTransportation){
                    edge.transportation = ui->TransportationType->text().toStdString();
                    edge.cost = cost;
                    hide();
                    transportationDisplay *transportationDisplayScene=new transportationDisplay();
                    transportationDisplayScene->show();
                }
            }
        }
    }
}

