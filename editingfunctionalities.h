#ifndef EDITINGFUNCTIONALITIES_H
#define EDITINGFUNCTIONALITIES_H
#include"file_management.h"

class EditingFunctionalities
{
public:
    EditingFunctionalities();
    static string selectedSource;
    static string selectedDestination;
    static string selectedTransportation;
    static bool add(Edge e1,string source,string destination);
    static bool connection();
    static bool deleting();


};


#endif // EDITINGFUNCTIONALITIES_H
