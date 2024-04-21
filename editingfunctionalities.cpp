#include "editingfunctionalities.h"


EditingFunctionalities::EditingFunctionalities() {}

//Add function
void EditingFunctionalities::add(Edge e1,unordered_map<string,unordered_map<string, vector<Edge>>>&transportationMap,string source,string destination){
        //check source and destaination waiting
        bool exist=0;
        for (int i = 0; i < transportationMap[source][destination].size() ; i++) {
            if(transportationMap[source][destination] [i].transportation==e1.transportation){
                exist=1;
            }
        }
        if(exist==0){
            transportationMap[source][destination].push_back(e1);
        }else{
            //kda yb2a hwa mawgod
        }

    }

//Delete function
    void EditingFunctionalities:: deleting(Edge edge, unordered_map<string,unordered_map<string,vector<Edge>>>&transportationMap,string source,string destination){
        for (int i = 0; i < transportationMap[source][destination].size() ; i++) {
            if(transportationMap[source][destination] [i].transportation==edge.transportation && transportationMap[source][destination] [i].cost==edge.cost){
                transportationMap[source][destination].pop_back();
            }else{
                ///not found
            }
        }
    }

