#include<bits/stdc++.h>

using namespace std;

class graph
{
    public: 
        unordered_map<int, list<int>> adj;  // Adjacency list
        vector<vector<int>> adjMatrix; // Adjacency matrix

    int numNodes; // Number of nodes

    graph(int n) : numNodes(n) {
        adjMatrix.resize(n, vector<int>(n, 0)); // Initialize matrix with zeros
    }

    void addEdge(int u, int v, bool direction)
    {
        if (u >= numNodes || v >= numNodes) {
            cout << "Error: Node index out of bounds." << endl;
            return;
        }
        adj[u].push_back(v);
        if(direction == 0)
        {
            adj[v].push_back(u);
        }
        adjMatrix[u][v] = 1;
        if (direction == 0) {
            adjMatrix[v][u] = 1;  // For undirected graph
        }
    } 

    void printAdjList()
    {
        for(auto i : adj)
        {
            cout<<"Printing adjacent list : ";
            cout<<i.first<<"->";
            for(auto j : i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

    void printAdjMatrix(){
        for (int i = 0; i<numNodes; i++) {
            for (int j = 0; j<numNodes; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }  
};

int main()
{
    int n, m;
    cout<<"Enter the number of nodes : "<<endl;
    cin>>n;

    cout<<"Enter the number of edges : "<<endl;
    cin>>m;

    graph g(n);

    cout<<"Enter the edges : "<<endl;
    for(int i = 0; i<m; i++)
    {
        int u, v;
        cin>> u >> v;

        g.addEdge(u, v, 0);
    }

    cout << "Adjacency List:" << endl;
    g.printAdjList();

    cout << "Adjacency Matrix:" << endl;
    g.printAdjMatrix();
}