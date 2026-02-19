//Before reading this study graph2.cpp
// Why bfs can be used to calculate shortest path?
// In bfs, since before going to the next level, all the nodes at previous level are visited
// once, and the graph is a not weighted(i.e. all the weight are 1), hence it can be used
// to find the shortest path, between the nodes-> just as we did in graph2.cpp using the
// level array or can be said as distance array, actually the level of the node is itself
// the shortest path from any node or source node.
// In this code we will be given a source and destination node and we need to find the
// shortest distance between them and also the path for the same, i.e. we need to trace the
// shortest path between the source and destination node.

//we can apply the above on both directed or undirected graph, acyclic or cyclic, only
//the graph should be unweighted. 

//can also see code here : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
//and can see the video from striver graph playlist g-28.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
vector<int> g[N]; // it gives us the adjacency list.
int vis[N];       // Visited array, initialized to 0 globally.
int level[N];     // To store the shortest distance (levels) from the source node.
int parent[N];    // To store the parent of each node in the BFS tree.
vector<int> path; // To store the path from source to destination.

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    level[s] = 0;
    parent[s] = -1; // Source node has no parent.

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto it : g[t])
        {
            if (!vis[it])
            {
                vis[it] = true; //vis[it] = true has to be done here only and not after 
                //poping it, as it can store longer path for it, can check with a small
                //graph.
                parent[it] = t;
                q.push(it);
                level[it] = level[t] + 1;
            }
        }
    }
}

void trace(int node, int s) //this will trace the path between source and destination.
{
    if (node == s) 
    {
        path.push_back(node); // Add the source node to the path.
        return;
    }
    path.push_back(node);
    trace(parent[node], s);
}

void VivekTiwary_1092()
{
    int n, m;
    cin >> n >> m; // n is the total number of nodes and m is the total number of
    // edges.

    // Reset data structures for each test case.
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        parent[i] = -1;
        level[i] = 0;
        g[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2; // there is an edge from v1 to v2;
        g[v1].pb(v2);
        g[v2].pb(v1); // this is for an undirected graph, incase if we want to solve
        // for a directed graph then line 23 should be commented.
    }

    int s, d; // Source and destination nodes.
    cin >> s >> d;

    bfs(s); // Perform BFS from the source.

    if (!vis[d]) {
        cout << "-1\n"; // Destination not reachable.
        return;
    }

    // Shortest distance.
    cout << level[d] << "\n";

    // Trace and print the path.
    path.clear();
    trace(d, s);
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) 
    {
        cout << path[i] << " ";
    }
    cout << "\n";

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(parent, -1, sizeof(parent)); // initialized parent array with -1.
    int t = 1;
    cin >> t;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}