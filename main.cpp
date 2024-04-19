#include "mainwindow.h"
#include <QApplication>
#include"file_management.h"
using namespace std;

int main(int argc, char* argv[]) {
    file_management::read();
    file_management::test();
    file_management::write();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
