#include "dfs.h"
#include <iostream>
#include <list>
using namespace std;
DFS::DFS(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}
// DFS algorithm
void DFS::DF(int vertex) {
    visited[vertex] = true;
    list<int> adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DF(*i);
}






























class Graph
{
private:
    int n;
    int **A;
public:
    Graph(int siz = 2);
    ~Graph();
    bool isConnected(int, int);
    void addEdge(int x, int y);
    void DFS(int , int);
};

Graph::Graph(int siz)
{
    int i, j;
    if (siz < 2) n = 2;
    else n = siz;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
}

Graph::~Graph()
{
    for (int i = 0; i < n; ++i)
        delete [] A[i];
    delete [] A;
}

bool Graph::isConnected(int x, int y)
{
    return (A[x-1][y-1] == 1);
}

void Graph::addEdge(int x, int y)
{
    A[x-1][y-1] = A[y-1][x-1] = 1;
}

void Graph::DFS(int x, int required)
{
    stak s;
    bool *visited = new bool[n+1];
    int i;
    for(i = 0; i <= n; i++)
        visited[i] = false;
    s.push(x);
    visited[x] = true;
    if(x == required) return;
    cout << " Depth first Search starting from vertex ";
    cout <<  x << " : " << endl;
    while(!s.isEmpty())
    {
        int k = s.pop();
        if(k == required) break;
        cout<<k<<" ";
        for (i = n; i >= 0 ; --i)
            if (isConnected(k, i) && !visited[i])
            {
                s.push(i);
                visited[i] = true;
            }
    }
    cout<<endl;
    delete [] visited;
}
