#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<limits.h>
#include <bits/stdc++.h>
using namespace std;

//                                              Dijkstra's algorithm function

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {

    //create adjajency list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i = 0 ; i < edges ; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //creation of distance array with infinite value initially 
    vector<int> dist(vertices); 
    for(int i = 0 ; i < vertices ; i++)
    {
        dist[i] = INT_MAX;
    }

    //creation of set on basis(distance, node)
    set<pair<int,int>> st;

    //initialize distance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty())
    {   
        //fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){

                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                
                //if record found, then erase it
                if(record != st.end()){
                    st.erase(record);
                }

                //distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                
                //record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));      
            }
        }
    }
    return dist;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    
    cout << "Enter the number of edges: ";
    cin >> edges;
    
    vector<vector<int>> edgesList(edges);
    
    cout << "Enter the edges in the format (u v w) where u and v are node indices and w is the weight:\n";
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edgesList[i] = {u, v, w};
    }
    
    int source;
    cout << "Enter the source node: ";
    cin >> source;

    // Ensure the source node is within bounds
    if (source < 0 || source >= vertices) {
        cout << "Invalid source node.\n";
        return 1;
    }

    // Run Dijkstra's algorithm
    vector<int> distances = dijkstra(edgesList, vertices,edges, source);

    // Output the shortest distances from the source
    cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < vertices; ++i) {
        cout << "Node " << i << ": " << distances[i] << "\n";
    }

    return 0;
}