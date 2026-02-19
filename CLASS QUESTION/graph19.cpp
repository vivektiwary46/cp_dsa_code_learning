//In this code we will implement Floyd-Warshall Algorithm.
//Youtube Link :- https://www.youtube.com/watch?v=YbY8cVwWAvw -> watch till 25 mins from
//start.

//It is a all pair shortest path algorithm.

//Given a directed or an undirected weighted graph G with n vertices. The task is to find 
//the length of the shortest path d[i][j]  between each pair of vertices i and j.

//The graph may have negative weight edges, but no negative weight cycles.

//If there is such a negative cycle, you can just traverse this cycle over and over, in 
//each iteration making the cost of the path smaller. So you can make certain paths 
//arbitrarily small, or in other words that shortest path is undefined. That automatically
//means that an undirected graph cannot have any negative weight edges, as such an edge 
//forms already a negative cycle as you can move back and forth along that edge as long as you like.


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

//Time Complexity :- O(n^3).

const int INF = 1e9 + 10;

void floydWarshall(vector<vector<int>>& graph, int n, int src, int dest) 
{
    // Initialize distance matrix
    vector<vector<int>> dist = graph;

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (dist[i][k] == 1e9 || dist[k][j] == 1e9)
                {
                    dist[i][j] = dist[i][j];
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // i to j via k
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < n; i++) 
    {
        if (dist[i][i] < 0) 
        {
            cout << "Negative weight cycle detected.\n";
            return;
        }
    }

    // If no negative weight cycle, print shortest distance from source to destination
    if (dist[src][dest] == INF) 
    {
        cout << "No path exists between " << src << " and " << dest << ".\n";
    } 
    else 
    {
        cout << "The shortest distance from " << src << " to " << dest << " is " << dist[src][dest] << ".\n";
    }
}

void VivekTiwary_1092()
{
    int n, m; //n is total number of nodes and m is total number of edges.
    cin >> n >> m;

    // Initialize adjacency matrix with INF
    vector<vector<int>> graph(n, vector<int>(n, INF));
    //for (int i = 0; i < n; i++)
    //{
    //    graph[i][i] = 0; // Distance from a node to itself is 0, This is wrong assumption
    //node to node distance hai means cycle is there so wo cylce ka kya length i.e. weight
    //ka sum will be the node to node distance and if node to node ke liye ek se jada cycle
    //hua toh the min length will be stored.
    //}

    for (int i = 0; i < m; i++) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // Set the weight for the directed edge
        graph[v][u] = w; //comment this line for a directed graph.
    }

    int src, dest;
    cin >> src >> dest;

    floydWarshall(graph, n, src, dest);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}