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
    static void read(unordered_map<string,unordered_map<string, vector<Edge>>>&transportationMap);
    static void write(unordered_map<string,unordered_map<string, vector<Edge>>>&transportationMap);
    static void test(unordered_map<string,unordered_map<string, vector<Edge>>>&transportationMap);
};

#endif // FILE_MANAGEMENT_H
