//This code give the level of each node, for this we needed to make just a simple change in 
//the bfs algorithm, created a level array and use the syntax level[x] = level[curr] + 1; in the
//line number 31.
//This level array can also be said as distance array, which gives us distance from the 
//source node.
//This is for a unweighted graph or say for a graph in which the weight of each edge is 1.
//for this first read graph1.cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
const int n = 8; //n is the number of nodes in the graph.
int level[n];

void bfs(vector<vector<int>> &adj, int s)
{
    queue<int> q;
    vector<bool> visited(adj.size(), 0);//visited ka size bhi number of nodes ke equal hoga.
    visited[s] = 1;
    q.push(s);
    level[s] = 0; //intialized the level of the source as 0.
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                q.push(x);
                level[x] = level[curr] + 1;
            }
        }
    }
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v); //here as we are considering a undirected graph.
    adj[v].push_back(u); //here u, v represent ki u aur v ke bech mein ek edge hai.
}

void VivekTiwary_1092()
{
    vector<vector<int>> adj(n); // Adjacency list representation of the graph.
    //Just we need to add all the edges in the graph and the adjacency list will 
    //be created.
    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 2, 7);
    addEdge(adj, 3, 7);
    
    // Perform BFS traversal starting from vertex 0
    cout << "BFS starting from 0 : \n";
    bfs(adj, 0);
    cout << "\n";
    cout << "Level of each node is : \n";
    for (int x : level) {cout << x << " ";}
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}