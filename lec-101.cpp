#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//                                                               Bellman Ford

vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &edges){

    vector<int> dist(n+1, 1e8);
    dist[src] = 0;

    //n-1 times
    for(int i=1;i<n;i++){
        //traverse on edge list
        for(int j=0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && (dist[u] + wt < dist[v])){
                dist[v] = dist[u] +wt;
            }
        }
    }

    //check for negative cycle 
    bool flag =0; 
    for(int j=0;j<m;j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != 1e9 && (dist[u] + wt < dist[v])){
            flag =1;
        }
    }

    //if negative cycle then flag =1
    if(flag == 0){
       return dist;
    }
    return{}; 
}

int main() {
    int n, m, src;

    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    cout << "Enter the edges in the format (u v wt) where u and v are vertices and wt is the weight:" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    vector<int> distances = bellmanFord(n, m, src, edges);

    if (distances.empty()) {
        cout << "Graph contains a negative weight cycle." << endl;
    } else {
        cout << "Vertex distances from source " << src << ":" << endl;
        for (int i = 1; i <= n; ++i) {
            if (distances[i] == numeric_limits<int>::max()) {
                cout << "Vertex " << i << ": INF" << endl;
            } else {
                cout << "Vertex " << i << ": " << distances[i] << endl;
            }
        }
    }

    return 0;
}