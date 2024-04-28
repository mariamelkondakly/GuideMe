#include "result.h"
#include <QHBoxLayout>
#include "QSpacerItem"
#include "editorialOptions.h"
#include "ui_result.h"
#include "welcome.h"
#include <iostream>
using namespace std;
Result::Result(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Result)
{
    ui->setupUi(this);

    GUI_management::applyStylesheet(ui->widget, file_management::css_path + "/background.css");
    GUI_management::applyStylesheet(ui->pushButton, file_management::css_path + "/PushButton.css");
    GUI_management::applyStylesheet(ui->pushButton_2, file_management::css_path + "/PushButton.css");
    GUI_management::applyStylesheet(ui->title, file_management::css_path + "/titleLabel.css");

    display_roads();
}

void Result::searching_roads(string node,
                             string distinatation,
                             unordered_map<string, bool> &vistited,
                             deque<pair<pair<string, string>, pair<string, int>>> &road)
{
    if (vistited[node])
        return;

    if (node == distinatation) {
        string path = "";
        int total = 0;
        for (auto temp : road) {
            string source = temp.first.first, dist = temp.first.second;
            string transportation = temp.second.first;
            int cost = temp.second.second;
            path += source + " -> " + dist + " : " + transportation + " " + to_string(cost) + "$\n";
            total += cost;
        }
        allpaths.insert({total, path});
        return;
    }
    unordered_map<string, vector<Edge>>::iterator child;
    for (child = file_management::transportationMap[node].begin();
         child != file_management::transportationMap[node].end();
         child++) {
        for (auto transportation : child->second) {
            road.push_back(
                {{node, child->first}, {transportation.transportation, transportation.cost}});
            searching_roads(child->first, distinatation, vistited, road);
            road.pop_back();
            vistited[node] = true;
        }
    }
    vistited[node] = false;
}

void Result::display_roads()
{
    unordered_map<string, bool> visited;
    deque<pair<pair<string, string>, pair<string, int>>> road;
    searching_roads("Sohag", "cairo", visited, road);
    int cnt = 1;
    std::cout << allpaths.size() << "\n";

    QVBoxLayout *container = new QVBoxLayout();
    for (auto path : allpaths) {
        QString display_path = "Option ";
        display_path += to_string(cnt) + "#\n\n";
        display_path += path.second;
        display_path += "\nTotal : " + to_string(path.first) + "$\n";
        QLabel *label_path = new QLabel(display_path);
        GUI_management::applyStylesheet(label_path,
                                        file_management::css_path + "/Result_Widgets.css");
        container->addWidget(label_path);
        cnt++;
    }
    QWidget *parent = new QWidget();
    parent->setLayout(container);
    // GUI_management::applyStylesheet(parent,file_management::dir.relativeFilePath("/GuideMe/CSS_styling/transportationWidgets.css"));
    ui->all_roads_2->addWidget(parent);
}

Result::~Result()
{
    delete ui;
}

void Result::on_pushButton_clicked()
{
    hide();
    editorialFunctions *edit = new editorialFunctions();
    edit->show();
}

void Result::on_pushButton_2_clicked()
{
    hide();
    welcome *Welcome = new welcome();
    Welcome->show();
}
