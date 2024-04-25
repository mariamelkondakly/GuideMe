#include <QApplication>
#include"file_management.h"
#include "editorialOptions.h"
//#include <iostream>
#include "transportationdisplay.h"
using namespace std;


int main(int argc, char* argv[]) {
    file_management::read();
    // file_management::test();
    file_management::write();

    QApplication a(argc, argv);
    editorialFunctions f;
    f.show();
    return a.exec();
}
