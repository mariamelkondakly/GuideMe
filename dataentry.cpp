#include "dataentry.h"
#include "ui_dataentry.h"
#include "file_management.h"
#include "GUI_management.h"
#include "editingfunctionalities.h"
#include "editorialOptions.h"
#include "cities.h"
#include "traversal.h"
#include"welcome.h"
 int DataEntry:: budget ;
DataEntry::DataEntry(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DataEntry)
{
    ui->setupUi(this);
    this->showMaximized();
    this->setWindowTitle("Data Entry");
    GUI_management::applyStylesheet(ui->widget,file_management::css_path+"/background.css");
    GUI_management::applyStylesheet(ui->label, file_management::css_path+"/normalLabels.css");
    GUI_management::applyStylesheet(ui->label_2, file_management::css_path+"/titleLabel.css");
    GUI_management::applyStylesheet(ui->label_3, file_management::css_path+"/normalLabels.css");
    GUI_management::applyStylesheet(ui->label_4, file_management::css_path+"/normalLabels.css");
    GUI_management::applyStylesheet(ui->label_5, file_management::css_path+"/warningLabel.css");
    GUI_management::applyStylesheet(ui->checkComplete, file_management::css_path+"/warningLabel.css");
    GUI_management::applyStylesheet(ui->pushButton,file_management::css_path+"/PushButton.css");
    GUI_management::applyStylesheet(ui->pushButton_2, file_management::css_path+"/PushButton.css");
     GUI_management::applyStylesheet(ui->back1putton, file_management::css_path+"/PushButton.css");
    GUI_management::applyStylesheet(ui->pushButton_3, file_management::css_path+"/PushButton.css");
    GUI_management::applyStylesheet(ui->lineEdit, file_management::css_path+"/textfields.css");
    GUI_management::applyStylesheet(ui->lineEdit_2, file_management::css_path+"/textfields.css");
    ui->label_5->setVisible(false);


    if(EditingFunctionalities::connection()){
        ui->checkComplete->setText("Remark: This Transportation map is completely connected.");

    }
    else{
        ui->checkComplete->setText(" Remark: This Transportation map is incomplete.");
    }
}

DataEntry::~DataEntry()
{
    delete ui;
}

void DataEntry::on_pushButton_clicked()
{
    Traversal::bfsflag=true;
    Traversal::dfsflag=false;
}


void DataEntry::on_pushButton_3_clicked()
{
  Traversal::dfsflag=true;
  Traversal::bfsflag=false;
}

void DataEntry::on_pushButton_2_clicked()
{
    if(EditingFunctionalities::selectedSource.empty()){
        ui->label_5->setVisible(true);
    }
    else{

        if (file_management::transportationMap.find(EditingFunctionalities::selectedSource) != file_management::transportationMap.end()) {
            if (budget>0 && check_budget)
            {
                ui->label_5->setVisible(false);
                if(!Traversal::bfsflag && !Traversal::dfsflag){
                    ui->label_5->setText("Please make sure you've chosen BFS or DFS");
                    ui->label_5->setVisible(true);
                }
                else {
                    hide();
                    cities *window=new cities();
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

void DataEntry::on_lineEdit_2_editingFinished()
{
   string cost_budget =ui->lineEdit_2->text().toStdString();
    check_budget=1;
    for(int i=0;i<cost_budget.length();i++){

       if(!(cost_budget[i]>='0'&&cost_budget[i]<='9'))
            check_budget=0;
           budget*=10;
           budget+=(int)(cost_budget[i]-'0');
    }
}


void DataEntry::on_lineEdit_editingFinished()
{
     EditingFunctionalities::selectedSource =ui->lineEdit->text().toStdString();

}



void DataEntry::on_back1putton_clicked()
{
    hide();
    welcome *window=new welcome();
    window->show();
}

