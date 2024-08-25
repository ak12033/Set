#include <iostream>
#include <vector>
#include<unordered_map> 
#include<list> 
#include<stack>
using namespace std;

void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int,list<int>> &adj){
    visited[node]=1;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour, visited, s, adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    // create adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,visited,s,adj);
        }
    }
    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main() {
    int v, e;

    // Input number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    cout << "Enter the edges (u v) where u -> v:" << endl;
    for (int i = 0; i < e; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> result = topologicalSort(edges, v, e);

    // Print the topological order
    cout << "Topological Sort Order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}