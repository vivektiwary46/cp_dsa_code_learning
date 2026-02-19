//In this code using dfs we want to print how many connected graphs are there in the forest
//and a vector of vector in which for each connected graph we need to print all it's node.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
vector<int> g[N]; //it gives us the adjacency list.
int vis[N];//global array are already intialized to zero.
vector<vector<int>> cc; //connected components nodes in the forest.
vector<int> curr_cc;//current graph connected components.

void dfs(int vertex)
{
    vis[vertex] = 1;
    curr_cc.push_back(vertex);//curr_cc mein sara node dalne ke liye for a graph.
    for (auto child : g[vertex])
    {
        if (vis[child]) {continue;}
        dfs(child);
    }
}

void VivekTiwary_1092()
{
    int n, m; cin >> n >> m; //n is the total number of nodes and m is the total number of
    //edges.
    for (int i = 0; i < m; i++)
    {
        int v1, v2; cin >> v1 >> v2;//there is an edge from v1 to v2;
        g[v1].pb(v2);
        g[v2].pb(v1);//this is for an undirected graph, incase if we want to solve
        //for a directed graph then line 23 should be commented.
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1) {continue;}
        else
        {
            curr_cc.clear(); //dfs chale se phele curr_cc clear hona chahiye.
            dfs(i);
            cc.push_back(curr_cc);//after dfs is run on a node us graph ka sare nodes
            //curr_cc mein aagaya hoga, so we push it in cc.
        }
    }
    
    cout << cc.size() << "\n";
    for (auto component : cc)
    {
        for (int node : component)
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
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}