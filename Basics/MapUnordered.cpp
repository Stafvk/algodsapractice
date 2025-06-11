//This is a file to demonstrate sorting in orderedmap and unorederedmap

#include<stdio.h>
#include<iostream>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
void displayValues(map<int,vector<pair<int,int>>> &mapPrint){
    for(const auto& [key,value]:mapPrint){
        cout<<key<<" :"; 
        for(const auto& pair:value){
            cout<<"{"<<pair.first<<","<<pair.second<<"}";
        }
    }
};
void displayValuesForUnordered(unordered_map<int,vector<pair<int,int>>> &mapPrint){
    for(const auto& [key,value]:mapPrint){
        cout<<key<<" :"; 
        for(const auto& pair:value){
            cout<<"{"<<pair.first<<","<<pair.second<<"}";
        }
    }
};
int main(){
map <int,vector<pair<int,int>>> sampleMap;
unordered_map <int,vector<pair<int,int>>> sampleUnorder;
sampleMap[0]={{2,6},{0,1},{2,5}};
sampleMap[1]= {{1,3}}   ;
sampleMap[-1]={{1,2}};
cout<<"Map before sorting"<<endl;
displayValues(sampleMap);
for(auto& [key,value]:sampleMap){
    sort(value.begin(),value.end());
}
cout<<endl<<"Map after sorting"<<endl;
displayValues(sampleMap);

/*Below is the output I am getting
Map before sorting
-1 :{1,2}0 :{2,6}{0,1}{2,5}1 :{1,3}
Map after sorting
-1 :{1,2}0 :{0,1}{2,5}{2,6}1 :{1,3}
*/
sampleUnorder[0]={{2,6},{0,1},{2,5}};
sampleUnorder[1]= {{1,3}}   ;
sampleUnorder[-1]={{1,2}};
cout<<endl<<"UnorderedMap before sorting"<<endl;
displayValuesForUnordered(sampleUnorder);
for(auto& [key,value]:sampleUnorder){
    sort(value.begin(),value.end());
}
cout<<endl<<"UnorderedMap after sorting"<<endl;
displayValuesForUnordered(sampleUnorder);
/*Unordered before and after sorting
UnorderedMap before sorting
0 :{2,6}{0,1}{2,5}1 :{1,3}-1 :{1,2}
Map after sorting
0 :{0,1}{2,5}{2,6}1 :{1,3}-1 :{1,2}

So the sorting applies to each value and the vectors in there
*/

//Below is demonstrating the case if the vectors were just numbers
map <int,int> sampleNoMap;
unordered_map <int,int> sampleNoUnorder;
sampleNoMap[0]=5;
sampleNoMap[1]= 3   ;
sampleNoMap[-1]=8;
cout<<"Map before sorting"<<endl;
   for(const auto& [key,value]:sampleNoMap)
        cout<<key<<" :"<<value; 
    
for(auto& [key,value]:sampleNoMap){
    sort(value.begin(),value.end());
}

cout<<endl<<"Map after sorting"<<endl;
for(const auto& [key,value]:sampleNoMap)
        cout<<key<<" :"<<value; 

sampleNoUnorder[0]=5;
sampleNoUnorder[1]= 3   ;
sampleNoUnorder[-1]=8;
cout<<"Map before sorting"<<endl;
   for(const auto& [key,value]:sampleNoUnorder)
        cout<<key<<" :"<<value; 
    
for(auto& [key,value]:sampleNoUnorder){
    sort(value.begin(),value.end());
}

cout<<endl<<"Map after sorting"<<endl;
for(const auto& [key,value]:sampleNoUnorder)
        cout<<key<<" :"<<value; 
};
//We get an error because we cannot sort based on values!!