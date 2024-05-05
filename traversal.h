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
    static vector<string> dfs(string start);
  static vector<string> bfs(string start);
    static void unvisited(string start);
};

#endif // TRAVERSAL_H
