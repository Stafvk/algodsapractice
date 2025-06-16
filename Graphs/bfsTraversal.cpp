//This code is to practice BFS Traversal on a Graph( I am taking Undirected graph here)
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include<list>
using namespace std;

// Declare the BFS function
vector<int> BFS(vector<int> vertices, vector<vector<int>> edges,int noedges){
    unordered_map<int,bool> visited;
    vector<int> result;
    queue<int> q;
    int a=size(edges);
    vector<list<int>> adj(noedges);
for(int i=0;i<size(edges);i++){
   adj[edges[i][0]].push_back(edges[i][1]);
   adj[edges[i][1]].push_back(edges[i][0]);
}
// for(int i=0;i<noedges;i++){
 if(!visited[0]) {
    q.push(0);
    visited[0]=true;
    }
while(!q.empty()){
    int temp=q.front();
    q.pop();
    result.push_back(temp);
  for(int j:adj[temp]){
    if(!visited[j]){
    q.push(j);
    visited[j]=true;
    }
  }
}
    // }
// }
  return result;
}

int main() {
  //Take the input here
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<int> vertices(n);
    cout << "Enter vertex labels:\n";
    for (int i = 0; i < n; ++i) {
        cin >> vertices[i];
    }

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> result = BFS(vertices, edges,n);

    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

//We need the commented for loop incase of disconnected components in the graph