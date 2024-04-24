#include "mainwindow.h"
#include "dfs.h"
#include <QApplication>
#include"file_management.h"
using namespace std;

int main(int argc, char* argv[]) {
    file_management::read();
    file_management::test();
    file_management::write();
    DFS d= *new DFS(5) ;
    d.DF();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
