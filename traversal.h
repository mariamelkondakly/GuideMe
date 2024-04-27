#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include <String>
#include<unordered_map>
#include "file_management.h"
using namespace std;
class Traversal
{
public:
    static bool bfsflag;
    static bool dfsflag;
  static map<string,bool> visited;
    static vector<string> dfs(unordered_map<string,unordered_map<string,vector<Edge>>> &transportationMap,string start);
  static vector<string> bfs(unordered_map<string,unordered_map<string,vector<Edge>>> &transportationMap,string start);
};

#endif // TRAVERSAL_H
