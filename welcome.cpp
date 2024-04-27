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
    ui->setupUi(this);
    GUI_management::applyStylesheet(ui->widget, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/background.css"));
    GUI_management::applyStylesheet(ui->label, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    GUI_management::applyStylesheet(ui->pushButton, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->pushButton_2, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->label_2, file_management::dir.relativeFilePath("/GuideMe/CSS_styling/welcometitle.css"));
}

welcome::~welcome()
{
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

