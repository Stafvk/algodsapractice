#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Graphs{
unordered_map<int,list<int>> m;
bool undirected;  //correction you don't need this here since you can declare it in the parameter efinntion here./
public:
 void addEdge(int u, int v,bool undirected){
    m[u].push_back(v);
    if(undirected){
        m[v].push_back(u);
    }
};
void print(){
    for(auto i:m){
        cout<<i.first<<" :";
        for(auto j:i.second)
            cout<<j<<" ";
        
    }
}
};
int main()
{
    int m,n;
    int u,v;
cout<<"enter number of nodes";
cin>>n;
cout<<"enter number of edges";
cin>>m;
Graphs g;
for(int i=0;i<m;i++){
    cout<<"enter the two nodes:";
    cin>>u;
    cin>>v;
g.addEdge(u,v,1);
g.print();
}

}