#include <QApplication>
#include"file_management.h"
#include "editorialOptions.h"
#include "citiesSelection.h"
#include "traversal.h"
#include "edit_view.h"
#include "welcome.h"
#include "updatingtransportation.h"
//#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {
    file_management::read();
    file_management::readFile();
  //  file_management::test();

    QApplication a(argc, argv);
    welcome f;
    f.show();

    return a.exec();
}
