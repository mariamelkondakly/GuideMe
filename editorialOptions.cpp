#include "editorialOptions.h"
#include "ui_editorialOptions.h"
#include "file_management.h"
#include "updatingtransportation.h"
#include "GUI_management.h"
#include <QDir>

bool editorialFunctions::deleteFlag = false;
bool editorialFunctions::editFlag = false;
bool editorialFunctions::addFlag = false;
editorialFunctions::editorialFunctions(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::editorialFunctions)

{
    ui->setupUi(this);

    GUI_management::applyStylesheet(ui->widget, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/background.css"));
    GUI_management::applyStylesheet(ui->label, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    GUI_management::applyStylesheet(ui->DeleteButton, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->AddButton, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->EditButton, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
}
editorialFunctions::~editorialFunctions()
{
    delete ui;
}


void editorialFunctions::on_DeleteButton_clicked()
{
    deleteFlag=true;
    editFlag=false;
    addFlag=false;
    hide();
    citiesSelection *window=new citiesSelection();
    window->show();


}


void editorialFunctions::on_EditButton_clicked()
{
    deleteFlag=false;
    editFlag=true;
    addFlag=false;
    hide();
    citiesSelection *window=new citiesSelection();
    window->show();
}


void editorialFunctions::on_AddButton_clicked()
{
    deleteFlag=false;
    editFlag=false;
    addFlag=true;
    hide();
    citiesSelection *window=new citiesSelection();
    window->show();
}

