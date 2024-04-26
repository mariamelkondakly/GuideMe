#include "citiesSelection.h"
#include "ui_citiesSelection.h"
#include "file_management.h"
#include "editorialOptions.h"


using namespace std;

string EditingFunctionalities::selectedSource; // Definition for selectedSource
string EditingFunctionalities::selectedDestination;
bool found=false;

citiesSelection::citiesSelection(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::citiesSelection)
{
    ui->setupUi(this);
    GUI_management::applyStylesheet(ui->widget, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/background.css"));
    GUI_management::applyStylesheet(ui->title, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    GUI_management::applyStylesheet(ui->next, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->sourceLabel, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/normalLabels.css"));
    GUI_management::applyStylesheet(ui->destinationLabel, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/normalLabels.css"));
    GUI_management::applyStylesheet(ui->warning, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/warningLabel.css"));
    GUI_management::applyStylesheet(ui->destination, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/textfields.css"));
    GUI_management::applyStylesheet(ui->source, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/textfields.css"));
    ui->warning->setVisible(false);

}

citiesSelection::~citiesSelection()
{
    delete ui;
}

void citiesSelection::on_source_editingFinished()
{
    EditingFunctionalities::selectedSource=ui->source->text().toStdString();
}


void citiesSelection::on_destination_editingFinished()
{
    EditingFunctionalities::selectedDestination=ui->destination->text().toStdString();
}


void citiesSelection::on_next_clicked()
{
    if(EditingFunctionalities::selectedSource.empty()||EditingFunctionalities::selectedDestination.empty()){
        ui->warning->setVisible(true);
    }
    else{
        if (file_management::transportationMap.find(EditingFunctionalities::selectedSource) != file_management::transportationMap.end()) {
            if (file_management::transportationMap[EditingFunctionalities::selectedSource].find(EditingFunctionalities::selectedDestination) !=
                file_management::transportationMap[EditingFunctionalities::selectedSource].end())
            {
                ui->warning->setVisible(false);
                if(editorialFunctions::addFlag){

                }
                else {
                    hide();
                    transportationDisplay *window=new transportationDisplay();
                    window->show();
                }
            }
            else{
                ui->warning->setText("Please make sure you've entered the right destination");
                ui->warning->setVisible(true);
            }
        }
        else{
            ui->warning->setText("Please make sure you've entered the right source");
            ui->warning->setVisible(true);
        }
    }

}
