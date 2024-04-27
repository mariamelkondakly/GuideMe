#include "file_management.h"
#include <QApplication>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include<unordered_map>
#include <QPair>
#include <vector>
#include <QString>

using namespace std;


unordered_map<string, unordered_map<string, vector<Edge>>> file_management::transportationMap;
QDir file_management::dir("C:/Users/dell/Desktop");
void file_management::test(){
    for (const auto& source_data : transportationMap) {
        for (const auto& destination_data : source_data.second) {
            cout << source_data.first << " "
                 << destination_data.first << " ";
            for (const auto& edge : destination_data.second) {
                cout<< edge.transportation << " "
                     << edge.cost <<" ";
            }
            cout<<endl;
        }
    }

} void file_management::  read()
{
    ifstream data_read("transportation_data.txt");
    string line;
    while (getline(data_read, line)) {
        string source, destination,transportation;
        int cost;
        istringstream iss(line);
        iss >> source >> destination ;
        while (iss >>transportation>>cost) {
            transportationMap[source][destination].push_back({transportation, cost});
        }
    }
    data_read.close();
}
void file_management::write()
{

    ofstream data_write("transportation_data.txt");
    for (const auto& source_data : transportationMap) {
        for (const auto& destination_data : source_data.second) {
            data_write << source_data.first << " "
                       << destination_data.first << " ";
            for (const auto& edge : destination_data.second) {
                data_write<< edge.transportation << " "
                           << edge.cost <<" ";
            }
            data_write<<"\n";
        }
    }
    data_write.close();
 }

vector<QPair<string,string>> file_management::readFile(){
    fstream myFile;
    myFile.open("project.txt" , ios::in);
    string line;
    vector<QPair<string,string>> pair;
    if(myFile.is_open()){
        while(getline(myFile,line)){
            string city , path;
            QString p;
            istringstream iss(line);
            if(iss >>city>>path){
                p=QString::fromStdString(path);
               QString newPath = QString::fromStdString(dir.relativeFilePath(p).toStdString());
                pair.push_back({city,path});
            }
        }
        myFile.close();
    }
    return pair;
}





