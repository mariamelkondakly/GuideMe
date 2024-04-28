#include "updatingtransportation.h"
#include "ui_updatingtransportation.h"
#include "gui_management.h"

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

}

updatingTransportation::~updatingTransportation()
{
    delete ui;
}

// void updatingTransportation::on_TransportationType_textEdited(const QString &arg1)
// {

// }

