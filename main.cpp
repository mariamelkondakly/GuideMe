#include "mainwindow.h"
#include <QApplication>
#include"file_management.h"
//#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char* argv[]) {
    unordered_map<string,unordered_map<string,vector<Edge>>> transportationMap;
    file_management::read(transportationMap);
    file_management::test(transportationMap);
    file_management::write(transportationMap);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    return 0;
}
