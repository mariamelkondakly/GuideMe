#include "mainwindow.h"
#include <QApplication>
#include"file_management.h"
//#include <iostream>
#include <string>
#include <vector>
using namespace std;

//function el add
//*******************************************************
void add(Edge e1,unordered_map<string,unordered_map<string, vector<Edge>>>&transportationMap,string source,string destination){
    //check source and destaination waiting
    bool exist=0;
    for (int i = 0; i < transportationMap[source][destination].size() ; i++) {
        if(transportationMap[source][destination] [i].transportation==e1.transportation){
            exist=1;
        }
    }
    if(exist==0){
        transportationMap[source][destination].push_back(e1);
    }else{
     //kda yb2a hwa mawgod
    }

}
//*******************************************************

int main(int argc, char* argv[]) {
    unordered_map<string,unordered_map<string, vector<Edge>>> transportationMap;
    file_management::read(transportationMap);
    file_management::test(transportationMap);
    file_management::write(transportationMap);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    return 0;
}
