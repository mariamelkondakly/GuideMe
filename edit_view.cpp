#include "edit_view.h"
#include "ui_edit_view.h"
#include"gui_management.h"
#include"file_management.h"
#include"editingfunctionalities.h"
#include<iostream>
#include"transportationdisplay.h"
#include"citiesSelection.h"
using namespace std;

edit_view::edit_view(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::edit_view)
{
    ui->setupUi(this);
    GUI_management::applyStylesheet(ui->label_3,file_management::css_path+"/titleLabel.css");
    GUI_management::applyStylesheet(ui->widget,file_management::css_path+"/background.css");
    GUI_management::applyStylesheet(ui->label,file_management::css_path+"/normalLabels.css");
    GUI_management::applyStylesheet(ui->pushButton,file_management::css_path+"/PushButton.css");
    GUI_management::applyStylesheet(ui->label_2,file_management::css_path+"/normalLabels.css");
    GUI_management::applyStylesheet(ui->label_4,file_management::css_path+"/normalLabels.css");
    GUI_management::applyStylesheet(ui->lineEdit,file_management::css_path+"/textfields.css");
    GUI_management::applyStylesheet(ui->lineEdit_2,file_management::css_path+"/textfields.css");
    GUI_management::applyStylesheet(ui->pushButton_2,file_management::css_path+"/PushButton.css");

}

edit_view::~edit_view()
{
    delete ui;
}

void edit_view::on_pushButton_clicked()
{
    bool check=1;
    string transportationName=ui->lineEdit_2->text().toStdString();
    string transportationCost=ui->lineEdit->text().toStdString();
    int cost=0;
    if(transportationName.empty()||transportationCost.empty())
        check=0;


    for (int i = 0; i <transportationCost.size(); i++) {
        if((transportationCost[i]<'0'||transportationCost[i]>'9'))
            check=0;

    }

    if(check==1){
        int cost=stoi(transportationCost);
        cout<<transportationName<<" "<<cost<<endl;
        bool valdation=EditingFunctionalities::add({transportationName,cost},EditingFunctionalities::selectedSource,EditingFunctionalities::selectedDestination);
        if(!valdation){
            ui->label_4->setText("the transportation is already exist !!");
        }
        else{
            hide();
            transportationDisplay* window=new transportationDisplay() ;
            window->show();
        }
    }else
        ui->label_4->setText("please fill the right transpotation name and transportation cost !!");


}


void edit_view::on_pushButton_2_clicked()
{
    hide();
    citiesSelection* city=new citiesSelection();
    city->show();
}

