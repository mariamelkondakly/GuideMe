
#include "editingfunctionalities.h"


EditingFunctionalities::EditingFunctionalities() {}
string EditingFunctionalities::selectedTransportation;

//Add function

bool EditingFunctionalities::add(Edge e1,string source,string destination){

    //check source and destaination waiting
    bool exist=0;
    for (int i = 0; i < file_management::transportationMap[source][destination].size() ; i++) {
        if(file_management::transportationMap[source][destination] [i].transportation==e1.transportation){
            exist=1;
        }
    }
    if(exist==0){
        file_management::transportationMap[source][destination].push_back(e1);
    }else{
        return 0;
    }
    return 1;
}

//Delete function
bool EditingFunctionalities::deleting() {
    if (file_management::transportationMap[EditingFunctionalities::selectedSource][EditingFunctionalities::selectedDestination].size() == 1) {
        return false; // If there is only one transportation option, cannot delete
    }
    else{
    auto& transportationMap = file_management::transportationMap[EditingFunctionalities::selectedSource][EditingFunctionalities::selectedDestination];

    // Find the selected transportation option and delete it
    for (auto it = transportationMap.begin(); it != transportationMap.end(); ++it) {
        if (it->transportation == EditingFunctionalities::selectedTransportation) {
            transportationMap.erase(it);
            return true; // Deletion successful
        }
    }
    }

}
