
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
        file_management::transportationMap[destination][source].push_back(e1);
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

    transportationMap = file_management::transportationMap[EditingFunctionalities::selectedDestination][EditingFunctionalities::selectedSource];
    for (auto it = transportationMap.begin(); it != transportationMap.end(); ++it) {
        if (it->transportation == EditingFunctionalities::selectedTransportation) {
            transportationMap.erase(it);
            return true; // Deletion successful
        }
    }

 }

}

    static bool connection(unordered_map<string,unordered_map<string,vector<Edge>>> graph){

        unordered_map<string,unordered_map<string,vector<Edge>>> ::iterator it;
        //unordered_map<string,vector<Edge>> map2;
        int counter=0;
        int citiesCounter=0;
        for(it=graph.begin() ; it !=graph.end() ; it++){
            citiesCounter++;
        }
        for(it=graph.begin() ; it !=graph.end() ; it++){
            unordered_map<string,vector<Edge>> ::iterator it2;
            for(it2=it->second.begin() ; it2 !=it->second.end() ; it2++){
                counter++;
            }
            if(counter!=citiesCounter-1){
                return false;
            }
            counter=0;
        }
        return true;
    }


