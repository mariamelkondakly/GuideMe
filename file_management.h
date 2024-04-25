#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H
#include <QApplication>

#include <string>
#include <vector>

#include<unordered_map>
using namespace std;

struct Edge{
    string transportation;
    int cost;
};

class file_management
{
public:

    file_management();
    static unordered_map<string,unordered_map<string,vector<Edge>>> transportationMap;
    static void read();
    static void write();
    static void test();
};

#endif // FILE_MANAGEMENT_H
