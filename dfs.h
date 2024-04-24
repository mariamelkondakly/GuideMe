#ifndef DFS_H
#define DFS_H
#include <list>
using namespace std;
class DFS
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;
public:
    DFS(int V);
    void DF(int vertex);
};

#endif // DFS_H
