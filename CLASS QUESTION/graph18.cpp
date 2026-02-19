//In this code we will implement the bellman ford algorithm, it is very similar to what we
//do in the dijkstra algorithm, only that here we will apply relaxation operation on
//each edges exactly n-1 times as if we do it for the n time then the graph must contain
//some negative cycle, hence it is able to detect the negative cycles, also it works fine
//even if the edges have negative weight
//Youtube Link :- https://www.youtube.com/watch?v=0vVofAhAYjc -> watch it from start till
//23 mins.

//In this algorithm also we need to traverse the whole graph inorder to get shortest 
//distance and path from source to node.

//We can also see the code here : https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

//Time Complexity :- O(n*m).

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<array<int, 3>> edges; // List of edges (u, v, weight).
int dist[N], parent[N]; // Arrays for distances and parents.


bool Bellman_Ford(int s, int n) // s is the source node, n is the number of nodes.
{
    dist[s] = 0; // Distance to the source is 0.

    // Relax all edges n-1 times.
    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) 
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != INF && dist[u] + wt < dist[v]) 
            {
                dist[v] = dist[u] + wt;
                parent[v] = u;
            }
        }
    }

    // Doing the nth iteration to check for negative weight cycles.
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (dist[u] != INF && dist[u] + wt < dist[v]) 
        {
            return true; // Negative weight cycle detected.
        }
    }

    return false; // No negative weight cycle.
}

vector<int> tracePath(int d) // Trace path from source to destination.
{
    vector<int> path;
    while (d != -1) 
    {
        //dry run karkr dekhna isme parent[source] jarur -1 hoga.
        path.pb(d);
        d = parent[d];
    }
    reverse(path.begin(), path.end());
    return path;
}

void VivekTiwary_1092()
{
    int n, m; // n is total number of nodes and m is total number of edges.
    cin >> n >> m;

    // Reset data structures for each test case.
    edges.clear();
    for (int i = 0; i <= n; i++) 
    {
        dist[i] = INF; // Initialize distances to infinity.
        parent[i] = -1; // Initialize parent to -1.
    }

    // Input edges with weights.
    for (int i = 0; i < m; i++) 
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w; // There is an edge from v1 to v2 with weight w.
        edges.pb({v1, v2, w});
        edges.pb({v2, v1, w});//comment this line if the graph is a directed graph. 
    }

    int s, d; // Source and destination nodes.
    cin >> s >> d;

    if (Bellman_Ford(s, n)) //calling to see if there is a negative cycle in the graph.
    {
        cout << "Negative weight cycle detected.\n";
    } 
    else 
    {
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