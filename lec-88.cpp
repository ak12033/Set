#include<iostream>
#include <unordered_map>
#include<queue>
#include<list>
using namespace std;

bool isCyclicBFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        node = q.front();
        q.pop();
        // counter for already visited nodes
        int cnt = 0;
        //traversing the adjacency list
        for(int i: adjList[node]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            } else {
                cnt++;
            }
        }
        
        // if the number of visited nodes in any adjacency list is >=2 then there is a cycle.
        if(cnt >= 2)
            return true;
    }
    return false;
}

bool iscyclicBFS(int src,    unordered_map<int,bool> &visited,   unordered_map<int,list<int>> adj){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto neighbour: adj[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
    }
    return false;
}

bool iscyclicDFS(int node,int parent, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adj){
    visited[node]=true;
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycledetected=iscyclicDFS(neighbour, node,visited,adj);
            if(cycledetected)
                return true;
        }
        else if(neighbour != parent){
           //cycle present
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //to handle disconnected components 
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){

            //approach 1
            bool ans1 = isCyclicBFS(i,visited,adj);

            //approach 2
            bool ans2 = iscyclicBFS(i,visited,adj);

            //approach 3
            bool ans3 = iscyclicDFS(i,-1,visited,adj);

            if(ans1 == 1){
                return "Yes";
            } 
        }
    }
    return "No";
}

int main() {
    int n, m;
    cout << "Enter the number of nodes (n) and edges (m): ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter the edges (u v) where u and v are node indices:" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i][0] = u;
        edges[i][1] = v;
    }

    // Detect cycle
    string result = cycleDetection(edges, n, m);
    cout << "Cycle detected: " << result << endl;

    return 0;
}