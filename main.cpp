#include <QApplication>
#include"file_management.h"
#include "editorialOptions.h"
#include "citiesSelection.h"
#include "traversal.h"
#include "edit_view.h"
#include "welcome.h"
#include "updatingtransportation.h"
//#include <iostream>
#include "transportationdisplay.h"
#include"welcome.h"
using namespace std;


int main(int argc, char* argv[]) {

    file_management::read();
    //file_management::test();
    file_management::write();
    // Traversal::dfs(file_management::transportationMap,"Sohag");
     Traversal::bfs(file_management::transportationMap,"Sohag");

    QApplication a(argc, argv);
    welcome f;
    f.show();
    return a.exec();
}
