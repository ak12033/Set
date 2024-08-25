#include <iostream>
#include <vector>
#include<unordered_map> 
#include<list> 
#include<queue>
using namespace std;

//                                   Topological sort using BFS(Kahn's Algorithm)

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    // create adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int> indegree(v); 
	for(auto i:adj) {
	    for(auto j: i.second) {
	        indegree[j]++; 
	    }
	}

    //0 indegree walo ko push kardo
    queue<int> q;
    for(int i = 0;i<v;i++) {
	    if(indegree[i] == 0) {
	        q.push(i); 
        }
    }

    //do bfs
    vector<int> ans;
    while(!q.empty()) {
	    int front = q.front(); 
	    q.pop(); 
	        
        //ans store
        ans.push_back(front);
	    
        for(auto neighbour : adj[front]) {
	        indegree[neighbour]--;
	        if(indegree[neighbour] == 0) {
	            q.push(neighbour); 
	        }
	    }
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