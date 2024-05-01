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

QString file_management::css_path="C:/Users/mosta_ckzl9f2/OneDrive/Documents/GitHub/second/GuideMe/CSS_styling";
unordered_map<string, unordered_map<string, vector<Edge>>> file_management::transportationMap;
QDir file_management::dir("C:/Users\mosta_ckzl9f2\OneDrive\Documents\GitHub\second");
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

}
void file_management:: test2(){
    for(int i=0;i < readFile().size();i++){
        cout<<readFile()[i].first<<" "<<readFile()[i].second<<endl;
}
}
void file_management::  read()
{
    ifstream data_read("transportation_data.txt");
    string line;
    while (getline(data_read, line)) {
        string source, destination,transportation;
        int cost;
        istringstream iss(line);
        string dash;
        iss >> source >>dash>> destination ;
        while (iss >>transportation>>cost) {
            transportationMap[source][destination].push_back({transportation, cost});
             transportationMap[destination][source].push_back({transportation, cost});
        }
    }
    data_read.close();
}
void file_management::write()
{
  map<pair<string,string>,bool>written;

    ofstream data_write("transportation_data.txt");
    for (const auto& source_data : transportationMap) {
        for (const auto& destination_data : source_data.second) {
            if(!written[{source_data.first,destination_data.first}])
            {
            data_write << source_data.first << " - "
                       << destination_data.first << " ";
            for (const auto& edge : destination_data.second) {
                data_write<< edge.transportation << " "
                           << edge.cost <<" ";
            }
            data_write<<"\n";

            written[{source_data.first,destination_data.first}]=1;
            written[{destination_data.first,source_data.first}]=1;
            }
        }
    }
    data_write.close();
 }

// vector<QPair<string,string>> file_management::readFile(){
//     fstream myFile;
//     myFile.open("backgrounds.txt", ios::in);
//     string line;
//     vector<QPair<string,string>> pair;
//     if(myFile.is_open()){
//         while(getline(myFile, line)){
//             string city, path;
//             QString p;
//             istringstream iss(line);
//             if(iss >> city >> path){
//                 p = QString::fromStdString(path);
//                 QString newPath = QString::fromStdString(dir.relativeFilePath(p).toStdString());
//                 pair.push_back({city, newPath.toStdString()});
//             }
//         }
//         myFile.close();
//     }
//     return pair;
// }

 vector<QPair<string,string>> file_management::readFile(){
     fstream myFile;
     myFile.open("backgrounds.txt");
     string line;
     vector<QPair<string,string>> pair;
     if(myFile.is_open()){
         while(getline(myFile, line)){
             string city, path;
             QString p;
             istringstream iss(line);
             if(iss >> city >> path){
                 p = QString::fromStdString(path);
                 QString newPath = QString::fromStdString(dir.relativeFilePath(p).toStdString());
                 pair.push_back({city, newPath.toStdString()}); // Push newPath instead of path
             }
         }
         myFile.close();
     } else {
         cout << "Error: Could not open the file 'backgrounds.txt'" << endl;
     }

     // // Print contents of pair vector
     // cout << "Contents of pair vector:" << endl;
     // for(const auto& p : pair) {
     //     cout << p.first << " : " << p.second << endl;
     // }

     return pair;
 }







