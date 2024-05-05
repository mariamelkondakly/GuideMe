#include "traversal.h"
#include <iostream>
#include <stack>
#include <queue>
#include "file_management.h"
using namespace std;
// DFS algorithm
map<string,bool>Traversal::visited;
bool Traversal:: bfsflag=false;
bool Traversal:: dfsflag=false;
vector<string> Traversal::dfs(string start) {
    stack<string> s;
    vector<string> vec_cities;
    visited[start] = true;
    s.push(start);
    while (!s.empty()) {

        string current = s.top();
        s.pop();
        vec_cities.push_back(current);
        unordered_map<string,vector<Edge>>::iterator child;
        for (child=file_management::transportationMap[current].begin();child !=file_management::transportationMap[current].end();child++) {
            if (!visited[child->first]) {
                visited[child->first] = true;
                s.push(child->first);
            }
        }
    }
    return vec_cities;
}
vector<string> Traversal::bfs (string start){
    queue<string>q;
    vector<string> vec_cities;
    visited[start]= true;
    q.push(start);
    while(!q.empty()){
        string currentNode =q.front() ;
        q.pop();
        vec_cities.push_back(currentNode);
         unordered_map<string,vector<Edge>>::iterator childNode;
        for (childNode=file_management::transportationMap[currentNode].begin();childNode !=file_management::transportationMap[currentNode].end();childNode++) {
             if (!visited[childNode->first]) {
                 visited[childNode->first] = true;
                 q.push(childNode->first);
             }
        }
    }
    cout<<"bfs size "<<vec_cities.size();
  return vec_cities;
}

void Traversal::unvisited (string start){
    queue<string>q;
    visited[start]= false;
    q.push(start);
    while(!q.empty()){
        string currentNode =q.front() ;
        q.pop();
        unordered_map<string,vector<Edge>>::iterator childNode;
        for (childNode=file_management::transportationMap[currentNode].begin();childNode !=file_management::transportationMap[currentNode].end();childNode++) {
            if (visited[childNode->first]) {
                visited[childNode->first] = false;
                q.push(childNode->first);
            }
        }
    }
}

