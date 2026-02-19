//In this code we will implement dijsktra's algorithm 
//Youtube Link :- https://www.youtube.com/watch?v=F3PNsWE6_hM&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=96
//Watch the above video from 7:01 mins to 14:27 mins to understand how to implement it.
//While implementing it we use a priority queue and this can be used to find shortest distace
//as well as path from a source to destination for any weighted graph(may be cyclic, 
//acyclic, directed, undirected) with egdes weight being non-negative.
//Here also we find shortest path only and problem related to these are also known as
//single-source shortest paths problem.

//see code here also : https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

//Dijkstra algorithm fails to detect negative cycles and gives tle if the graph contains
//a negative cycle.

//Dijkstra algorithm mein single source ka input dete hai aur source aur destination ke
//beech ka pura graph traverse karna padta hai to get the shortest path and shortest 
//distance.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>

//Time Complexity = O(nlog(n) + mlog(n)).
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];    // Adjacency list with weights.
int vis[N], dist[N], parent[N]; // Arrays for visited, distances, and parents.

void dijkstra(int s) // s is the source.
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    
    while (!pq.empty())
    {
        int u = pq.top().second;
        //The top element of the priority queue in Dijkstra's algorithm always has the 
        //node with the smallest distance from the source node that hasn't been processed
        //yet. This is ensured by using a priority queue with greater<pii>.
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto p : g[u])
        {
            int v = p.first; //contains node number
            int w = p.second;//contains the edge value.
            if (!vis[v] && dist[u] + w < dist[v]) 
            {
                dist[v] = dist[u] + w;//relaxation operation.
                parent[v] = u;//agar node 2nd time bhi relax hua hai toh jo parent node
                //usko relax kia hoga wahi parent array mein store hoga.
                pq.push({dist[v], v});//yaha push kar die but pq.top().second mein
                //hamesha minimum wala hi hoga due to greater<pii>.
            }
        }
    }
}

vector<int> tracePath(int d) // Trace path from source to destination.
{
    vector<int> path;
    while (d != -1) 
    {
        //jo bhi source hai wo, koi beech ka bhi node ho sakta hai, uska parent toh -1
        //hi hoga, dijkstra algorithm mein jo source dia hai, waha se pura graph traverse
        //karna padta hai to get the shortest path.
        path.pb(d);
        d = parent[d];
    }
    reverse(path.begin(), path.end());
    return path;
}

void VivekTiwary_1092()
{
    int n, m; //n is total number of nodes and m is total number of edges.
    cin >> n >> m;

    // Reset data structures for each test case.
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
        vis[i] = 0;
        dist[i] = INF; // Initialize distances to infinity.
        parent[i] = -1;      // Initialize parent to -1.
    }

    // Input edges with weights.
    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;//there is an edge from v1 to v2 and w is the
        //weight of the edge between v1 and v2.
        g[v1].pb({v2, w});
        g[v2].pb({v1, w}); //comment this line for a directed graph. 
    }

    int s, d; // Source and destination nodes.
    cin >> s >> d;

    dijkstra(s);

    if (dist[d] == INF) 
    {
        cout << "No path from " << s << " to " << d << "\n";
    } 
    else 
    {
        cout << "Shortest distance: " << dist[d] << "\n";
        vector<int> path = tracePath(d);
        cout << "Path: ";
        for (int node : path) 
        {
            cout << node << " ";
        }
        cout << "\n";
    }
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