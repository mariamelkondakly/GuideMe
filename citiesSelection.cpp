#include "citiesSelection.h"
#include "ui_citiesSelection.h"
#include "GUI_management.h"
#include <QDir>
#include <QApplication>
#include<QWidget>
#include<QString>
#include<QFile>

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
    GUI_management::applyStylesheet(ui->destination, dir.relativeFilePath("/GuideMe/CSS_styling/textfields.css"));
    GUI_management::applyStylesheet(ui->source, dir.relativeFilePath("/GuideMe/CSS_styling/textfields.css"));


}

citiesSelection::~citiesSelection()
{
    delete ui;
}
