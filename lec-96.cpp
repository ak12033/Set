#include <bits/stdc++.h> 
using namespace std;

//                                                Prim's MST

//                                                approach 1

/*
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
     //for given particular node corresponding      //another node with its weight  
      unordered_map<int,list<pair<int,int>>>adj;
      for(int i=0;i<g.size();i++)
       {
         int u = g[i].first.first;
         int v=  g[i].first.second;
         int weight =g[i].second;

        adj[u].push_back(make_pair(v,weight));
         adj[v].push_back(make_pair(u,weight));
        }

//n+1 -> we representing index number as a node

      vector<int>key(n+1);  //weight of node 
      vector<bool> mst(n+1);  //it check given node //is in mst
        vector<int>parent(n+1);

        for(int i=0;i<=n;i++)
         {
              //in starting every value in infinity 
           key[i] =INT_MAX;
           parent[i] = -1;
           mst[i] = false;
          }
       //we mark source node as 0 and parent as -1     //in starting 
          key[1] = 0;
          parent[1] = -1;
      for(int i=1;i<n;i++)
          { 
              //find minimum from key 
           int minimum = INT_MAX;
           int u ;// it we have to find out on that base //we mark mst as true 

          //here we find u 
           for(int v=1;v<=n;v++)
           {
             if(mst[v] ==false && key[v]<minimum )
              {
                u =v;
                  minimum = key[v];
               }
            }
           //mark minimum node as true
              mst[u] =true;
 
            //check u adjacent node 
            for(auto it: adj[u])
             {
              int v = it.first;
              int weight = it.second;
               if(mst[v] ==false && weight < key[v])
                 {
                   parent[v] = u;
                    key[v] = weight;
                     }
               }
          }
      vector<pair<pair<int, int>, int>> result;
       for(int i =2;i<=n;i++)
         {
           result.push_back({{parent[i],i},key[i]});
           }
      return result; 
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges[i] = {{u, v}, weight};
    }

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);

    cout << "Edges in the MST:\n";
    for (const auto &edge : mst)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int weight = edge.second;
        cout << u << " - " << v << ": " << weight << "\n";
    }

    return 0;
}
*/

//                                                 approach 2 using min heap

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for(auto i : g) {
        int u = i.first.first;
        int v = i.first.second;
        int w = i.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

		// min heap to get node with minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	  // let source as 1, and inititally distance of source is 0
		// {weight, node}  
		pq.push({0, 1});

    vector<int> key(n+1, INT_MAX), parent(n+1, -1), visited(n+1, 0);

    parent[1] = -1;
		// weight to reach i is key[i]
    key[1] = 0;

    while(pq.size()) {
        int w = pq.top().first;
        int node = pq.top().second;
        visited[node] = 1;
        pq.pop();

				// find node with minimum weight and to to its neighbour 
        for(auto neg: adj[node]) {
            int toGo = neg.first;
            int toGoWeg = neg.second;

						// if to react node N from key[N] update weight(key[N]) with distance from node to N
            if(visited[toGo] == 0 && toGoWeg < key[toGo]) {

                key[toGo] = toGoWeg;
                parent[toGo] = node;
                pq.push({toGoWeg, toGo});
            }
        }

    }

    vector<pair<pair<int, int>, int>> ans;
	   // loop from 2 because parent of 1 is -1 (1 is initial node)
		for(int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]});

    }
    
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges[i] = {{u, v}, weight};
    }

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);

    cout << "Edges in the MST:\n";
    for (const auto &edge : mst)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int weight = edge.second;
        cout << u << " - " << v << ": " << weight << "\n";
    }

    return 0;
}