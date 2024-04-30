#include "welcome.h"
#include "ui_welcome.h"
#include "GUI_management.h"
#include "file_management.h"
#include "editorialOptions.h"
#include "dataentry.h"
welcome::welcome(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::welcome)
{
file_management::read();
file_management::readFile();

    //----------////////
    ui->setupUi(this);
    GUI_management::applyStylesheet(ui->widget,file_management::css_path+"/background.css");
    GUI_management::applyStylesheet(ui->label,file_management::css_path+"/titleLabel.css");
    GUI_management::applyStylesheet(ui->pushButton, file_management::css_path+"/PushButton.css");
    GUI_management::applyStylesheet(ui->pushButton_2, file_management::css_path+"/PushButton.css");
    GUI_management::applyStylesheet(ui->label_2, file_management::css_path+"/welcometitle.css");
}

welcome::~welcome()
{
    file_management::write();
    delete ui;
}

void welcome::on_pushButton_clicked()
{
     hide();
    DataEntry *window=new DataEntry();
     window->show();
}


void welcome::on_pushButton_2_clicked()
{
    hide();
    editorialFunctions *window=new editorialFunctions();
    window->show();
}

