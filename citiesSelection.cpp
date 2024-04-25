#include "citiesSelection.h"
#include "ui_citiesSelection.h"
#include "GUI_management.h"
#include <QDir>
#include <QApplication>
#include "editingfunctionalities.h"
#include<QWidget>
#include<QString>
#include<QFile>
#include<iostream>
using namespace std;

string EditingFunctionalities::selectedSource; // Definition for selectedSource
string EditingFunctionalities::selectedDestination;

citiesSelection::citiesSelection(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::citiesSelection)
{
    ui->setupUi(this);
    QDir dir("C:/Users/MARIAM/qt Projects"); //change it to make it run on your pc
    GUI_management::applyStylesheet(ui->widget, dir.relativeFilePath("/GuideMe/CSS_styling/background.css"));
    GUI_management::applyStylesheet(ui->title, dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    GUI_management::applyStylesheet(ui->next, dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->sourceLabel, dir.relativeFilePath("/GuideMe/CSS_styling/normalLabels.css"));
    GUI_management::applyStylesheet(ui->destinationLabel, dir.relativeFilePath("/GuideMe/CSS_styling/normalLabels.css"));
    GUI_management::applyStylesheet(ui->warning, dir.relativeFilePath("/GuideMe/CSS_styling/normalLabels.css"));
    GUI_management::applyStylesheet(ui->destination, dir.relativeFilePath("/GuideMe/CSS_styling/textfields.css"));
    GUI_management::applyStylesheet(ui->source, dir.relativeFilePath("/GuideMe/CSS_styling/textfields.css"));
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

    }

}

