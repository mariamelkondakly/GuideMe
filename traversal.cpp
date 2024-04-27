#include "traversal.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// DFS algorithm
map<string,bool>Traversal::visited;
bool Traversal:: bfsflag=false;
bool Traversal:: dfsflag=false;
vector<string> Traversal::dfs( unordered_map<string,unordered_map<string,vector<Edge>>> &transportationMap, string start) {
    stack<string> s;
    vector<string> vec_cities;
    visited[start] = true;
    s.push(start);
    while (!s.empty()) {

        string current = s.top();
        s.pop();
        vec_cities.push_back(current);
        unordered_map<string,vector<Edge>>::iterator child;
        for (child=transportationMap[current].begin();child !=transportationMap[current].end();child++) {
            if (!visited[child->first]) {
                visited[child->first] = true;
                s.push(child->first);
            }
        }
    }
    return vec_cities;
}
vector<string> Traversal::bfs (unordered_map<string,unordered_map<string,vector<Edge>>> &transportationMap, string start){
    queue<string>q;
    vector<string> vec_cities;
    visited[start]= true;
    q.push(start);
    while(!q.empty()){
        string currentNode =q.front() ;
        q.pop();
        vec_cities.push_back(currentNode);
         unordered_map<string,vector<Edge>>::iterator childNode;
        for (childNode=transportationMap[currentNode].begin();childNode !=transportationMap[currentNode].end();childNode++) {
             if (!visited[childNode->first]) {
                 visited[childNode->first] = true;
                 q.push(childNode->first);
             }
        }
    }
  return vec_cities;
}
