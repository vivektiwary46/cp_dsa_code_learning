//In this code we will implement shortest path in DAG for a weighted graph
//Read pdf 28 to know the flow of operation we will do.
//see code from here : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define pb push_back

const int N = 1e5 + 10;
vector<pair<int, int>> g[N];    // Adjacency list with weights.
int vis[N], dist[N], parent[N]; // Arrays for visited, distances, and parents.
stack<int> st;//this will have the linear order of the nodes which we pushed in the
//toppo_sort to get the topological order of the nodes.
vector<int> toppo_sort;         // To store topological order.
vector<int> path;               // To store the shortest path.

void dfs(int node)
{
    vis[node] = 1;
    for (auto child : g[node])
    {
        if (!vis[child.f])
        {
            dfs(child.f);
        }
    }
    st.push(node);// push to stack when finished  
}

void trace(int source, int destination)
{
    if (dist[destination] == LLONG_MAX)
    {
        cout << "No path exists from " << source << " to " << destination << "\n";
        return;
    }
    path.clear();
    int current = destination;
    while (current != -1)
    {
        //dry run karke dekhna last mein parent[source] jarur -1 hoga.
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    cout << "Shortest Path: ";
    for (int node : path)
    {
        cout << node << " ";
    }
    cout << "\n";
}

void VivekTiwary_1092()
{
    int n, m;//n is total number of nodes and m is total number of edges.
    cin >> n >> m;

    // Reset data structures for each test case.
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
        vis[i] = 0;
        dist[i] = LLONG_MAX; // Initialize distances to infinity.
        parent[i] = -1;      // Initialize parent to -1.
    }
    while (!st.empty()) {st.pop();}
    toppo_sort.clear();

    // Input edges with weights.
    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;//there is an edge from v1 to v2 and w is the
        //weight of the edge between v1 and v2.
        g[v1].pb({v2, w});//since topological sort is only for directed acyclic graph.
    }

    int source, destination;
    cin >> source >> destination;

    // Perform DFS to get topological order.
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    // Extract topological sort from the stack.
    while (!st.empty())
    {
        toppo_sort.pb(st.top());
        st.pop();
    }

    // Initialize the source distance to 0.
    dist[source] = 0; //yaha source kisi bhi beech ka node bhi ho sakta hai, so neche wala
    //loop wahi se start hoga aur us source aur uske aage ke nodes ka parent update karega
    //bakio ka still parent -1 rahega, hence trace function mein current != -1 se kam 
    //ho ja raha hai.

    // Relax edges in topological order.
    for (int u : toppo_sort)
    {
        if (dist[u] != LLONG_MAX)
        { // Only process reachable nodes.
            for (auto child : g[u])
            {
                int v = child.f, w = child.s;
                if (dist[u] + w < dist[v]) //Relaxation operation.
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u; // Update parent for path reconstruction.
                }
            }
        }
    }

    // Output the shortest distance.
    if (dist[destination] == LLONG_MAX)
    {
        cout << "No path exists from " << source << " to " << destination << "\n";
    }
    else
    {
        cout << "Shortest Distance: " << dist[destination] << "\n";
    }

    // Trace and output the shortest path.
    trace(source, destination);
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
