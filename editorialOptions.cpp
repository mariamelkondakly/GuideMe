#include "editorialOptions.h"
#include "ui_editorialOptions.h"
#include "GUI_management.h"
#include <QDir>
editorialFunctions::editorialFunctions(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::editorialFunctions)

{
    QWidget editorialfunction;
    ui->setupUi(this);
    QDir dir("C:/Users/MARIAM/qt Projects"); //change it to make it run on your pc
    GUI_management::applyStylesheet(ui->widget, dir.relativeFilePath("/GuideMe/CSS_styling/background.css"));
    GUI_management::applyStylesheet(ui->label, dir.relativeFilePath("/GuideMe/CSS_styling/titleLabel.css"));
    GUI_management::applyStylesheet(ui->pushButton, dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->pushButton_2, dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));
    GUI_management::applyStylesheet(ui->pushButton_3, dir.relativeFilePath("/GuideMe/CSS_styling/PushButton.css"));


}
editorialFunctions::~editorialFunctions()
{
    delete ui;
}

