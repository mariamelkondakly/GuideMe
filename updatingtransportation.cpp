#include "updatingtransportation.h"
#include "ui_updatingtransportation.h"
#include "gui_management.h"

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

}

updatingTransportation::~updatingTransportation()
{
    delete ui;
}

void updatingTransportation::on_TransportationType_textEdited(const QString &arg1)
{

}

