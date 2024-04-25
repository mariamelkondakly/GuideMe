#include "traversal.h"
#include <iostream>
#include <stack>
using namespace std;
// DFS algorithm
map<string,bool>Traversal::visited;
void Traversal::Traversall( unordered_map<string,unordered_map<string,vector<Edge>>> &transportationMap, string start) {
    stack<string> s;
    visited[start] = true;
    s.push(start);
    while (!s.empty()) {

        string current = s.top();
        s.pop();
        cout << current << " ";
        unordered_map<string,vector<Edge>>::iterator child;
        for (child=transportationMap[current].begin();child !=transportationMap[current].end();child++) {
            if (!visited[child->first]) {
                visited[child->first] = true;
                s.push(child->first);
            }
        }
    }
}
