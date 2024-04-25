#include <QApplication>
#include"file_management.h"
#include "editorialOptions.h"
#include "citiesSelection.h"
#include "traversal.h"
//#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char* argv[]) {
    unordered_map<string,unordered_map<string,vector<Edge>>> transportationMap;
    file_management::read(transportationMap);
    file_management::test(transportationMap);
    file_management::write(transportationMap);
    Traversal::Traversall(transportationMap,"Sohag");
    QApplication a(argc, argv);
    editorialFunctions f;
    f.show();
    return a.exec();
}
