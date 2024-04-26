#ifndef EDITINGFUNCTIONALITIES_H
#define EDITINGFUNCTIONALITIES_H
#include"file_management.h"

class EditingFunctionalities
{
public:
    EditingFunctionalities();
    static string selectedSource;
    static string selectedDestination;
    static bool add(Edge e1,string source,string destination);

    static void deleting(Edge edge, unordered_map<string,unordered_map<string,vector<Edge>>>&transportationMap,string source,string destination);


};


#endif // EDITINGFUNCTIONALITIES_H
