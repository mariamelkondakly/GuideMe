#include "updatingtransportation.h"
#include "ui_updatingtransportation.h"
#include "gui_management.h"
#include "welcome.h"
#include "editingfunctionalities.h"

updatingTransportation::updatingTransportation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::updatingTransportation)
{
    ui->setupUi(this);
    GUI_management::applyStylesheet(ui->widget, file_management::css_path+"/background.css");
    GUI_management::applyStylesheet(ui->title, file_management::css_path+"/titleLabel.css");
    GUI_management::applyStylesheet(ui->Update, file_management::css_path+"/PushButton.css");
    GUI_management::applyStylesheet(ui->TransportationCost, file_management::css_path+"/textfields.css");
    GUI_management::applyStylesheet(ui->TransportationType,file_management::css_path+"/textfields.css");
    GUI_management::applyStylesheet(ui->TransportationCostLabel,file_management::css_path+"/normalLabels.css");
    GUI_management::applyStylesheet(ui->TransportationTypeLabel, file_management::css_path+"/normalLabels.css");
    GUI_management::applyStylesheet(ui->warning, file_management::css_path+"/warningLabel.css");

}

updatingTransportation::~updatingTransportation()
{
    delete ui;
}

void updatingTransportation::on_Update_clicked()
{
    bool checkDigit = false;
    int cost;
    if(ui->TransportationCost->text() == "" || ui->TransportationType->text() == ""){
        ui->warning->setVisible(true);
    }
    else{
        for(int i=0;i<ui->TransportationCost->text().size() ;i++ ){
            if(! isdigit(ui->TransportationCost->text().toStdString()[i]) ){
                checkDigit = true;
                break;
            }
        }
        if(! checkDigit){
            cost = stoi(ui->TransportationCost->text().toStdString());
            for (Edge& edge : file_management::transportationMap[EditingFunctionalities::selectedSource][EditingFunctionalities::selectedDestination]){
                if(edge.transportation == EditingFunctionalities::selectedTransportation){
                    edge.transportation = ui->TransportationType->text().toStdString();
                    edge.cost = cost;
                    hide();
                    welcome *Welcome=new welcome();
                    Welcome->show();
                }
            }
        }
    }
}
