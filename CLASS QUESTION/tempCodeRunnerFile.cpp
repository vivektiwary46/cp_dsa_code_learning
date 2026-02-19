// Why bfs can be used to calculate shortest path?
// In bfs, since before going to the next level, all the nodes at previous level are visited
// once, and the graph is a not weighted(i.e. all the weight are 1), hence it can be used
// to find the shortest path, between the nodes-> just as we did in graph2.cpp using the
// level array or can be said as distance array, actually the level of the node is itself
// the shortest path from any node or source node.
// In this code we will be given a source and destination node and we need to find the
// shortest distance between them and also the path for the same, i.e. we need to trace the
// shortest path between the source and destination node.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
vector<int> g[N]; // it gives us the adjacency list.
int vis[N];       // global array are already intialized to zero.
int level[N];
int parent[N];
vector<int> path;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    level[s] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto it : g[t])
        {
            if (!vis[it])
            {
                vis[it] = true;
                parent[it] = t;
                q.push(it);
                level[it] = level[t] + 1;
            }
        }
    }
}

void trace(int node)
{
    if (parent[node] == -1) {return;}
    path.push_back(parent[node]);
    trace(parent[node]);
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

    int s, d; cin >> s >> d;//here s is the source and d is the destination
    bfs(s);
    cout << level[d] << "\n";
    path.push_back(d);
    trace(d);
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