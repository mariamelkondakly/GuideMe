#include "dataentry.h"
#include "ui_dataentry.h"
#include "file_management.h"
#include "GUI_management.h"
#include "editingfunctionalities.h"
#include "editorialOptions.h"
DataEntry::DataEntry(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DataEntry)
{
    ui->setupUi(this);
    GUI_management::applyStylesheet(ui->widget, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/background.css"));
    GUI_management::applyStylesheet(ui->label, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    GUI_management::applyStylesheet(ui->label_2, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    GUI_management::applyStylesheet(ui->label_3, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    GUI_management::applyStylesheet(ui->label_4, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    GUI_management::applyStylesheet(ui->label_5, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    GUI_management::applyStylesheet(ui->pushButton, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->pushButton_2, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->pushButton_3, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->lineEdit, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/textfields.css"));
    GUI_management::applyStylesheet(ui->lineEdit_2, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/textfields.css"));
    ui->label_5->setVisible(false);
}

DataEntry::~DataEntry()
{
    delete ui;
}

void DataEntry::on_pushButton_clicked()
{

}


void DataEntry::on_pushButton_3_clicked()
{

}


void DataEntry::on_pushButton_2_clicked()
{
    if(EditingFunctionalities::selectedSource.empty()){
        ui->label_5->setVisible(true);
    }
    else{
        if (file_management::transportationMap.find(EditingFunctionalities::selectedSource) != file_management::transportationMap.end()) {
            if (file_management::transportationMap[EditingFunctionalities::selectedSource].find(EditingFunctionalities::selectedDestination) !=
                file_management::transportationMap[EditingFunctionalities::selectedSource].end())
            {
                ui->label_5->setVisible(false);
                if(editorialFunctions::addFlag){

                }
                else {
                    hide();
                    transportationDisplay *window=new transportationDisplay();
                    window->show();
                }
            }
            else{
                ui->label_5->setText("Please make sure you've entered the right budget");
                ui->label_5->setVisible(true);
            }
        }
        else{
            ui->label_5->setText("Please make sure you've entered the right source");
            ui->label_5->setVisible(true);
        }
    }
}

