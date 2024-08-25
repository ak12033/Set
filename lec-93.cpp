#include <iostream>
#include <vector>
#include<unordered_map>
#include<list>
#include<queue>
#include <algorithm> // for std::reverse
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// create adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
         int v=edges[i].second;
        
        adj[u].push_back(v);
		adj[v].push_back(u);
    }

	//do bfs
	unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
	queue<int> q;
    q.push(s);
	parent[s] = -1;
    visited[s]=true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i:adj[front]){
            if (!visited[i]){
            	visited[i]=true;
				parent[i] = front;
				q.push(i); 
            }
        }
    }

	//prepare shortest path
	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);
	while(currentNode != s){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}
	reverse(ans.begin(),ans.end());
	return ans;

}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    cout << "Enter the edges (format: u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
    }

    int s, t;
    cout << "Enter the start node and target node: ";
    cin >> s >> t;

    // Get the shortest path
    vector<int> path = shortestPath(edges, n, m, s, t);

    // Print the result
    if (path.empty()) {
        cout << "No path exists from node " << s << " to node " << t << ".\n";
    } else {
        cout << "Shortest path from node " << s << " to node " << t << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}