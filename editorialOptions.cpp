#include "editorialOptions.h"
#include "ui_editorialOptions.h"
#include "file_management.h"

#include "GUI_management.h"
#include "welcome.h"
#include <QDir>

bool editorialFunctions::deleteFlag = false;
bool editorialFunctions::editFlag = false;
bool editorialFunctions::addFlag = false;
editorialFunctions::editorialFunctions(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::editorialFunctions)

{
    ui->setupUi(this);
    this->showMaximized();
    this->setWindowTitle("Choosing your editing preference");
    GUI_management::applyStylesheet(ui->widget,file_management::css_path+"/background.css");
    GUI_management::applyStylesheet(ui->label, file_management::css_path+"/titleLabel.css");
    GUI_management::applyStylesheet(ui->DeleteButton, file_management::css_path+"/PushButton.css");
    GUI_management::applyStylesheet(ui->AddButton, file_management::css_path+"/PushButton.css");
    GUI_management::applyStylesheet(ui->EditButton, file_management::css_path+"/PushButton.css");
    GUI_management::applyStylesheet(ui->back1putton, file_management::css_path+"/PushButton.css");
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


void editorialFunctions::on_back1putton_clicked()
{
    hide();
    welcome *window=new welcome();
    window->show();
}

