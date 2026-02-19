//1)Code to detect cycle in a undirected graph using dfs.
//2)Code to detect cycle in a undirected graph using bfs : https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-bfs/
//3)Code to detect a cycle in a directed graph using dfs : https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/
//4)Code to detect a cycle in a directed graph using bfs i.e. the khan's algorithm(which
//is used to find topo sort using bfs) : https://csacademy.com/code/26TiI0rx/
//and g-19 of striver graph playlist can be watched for 3 and g-23 for 4.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

vector<vector<int>> adj;
vector<int> vis;

bool dfs(int vertex, int parent)
{
    vis[vertex] = 1;
    for (auto ch : adj[parent])
    {
        if (vis[ch] == 1 && ch != parent) //har node ka ek child uska parent hoga aur wo visited
        //hai then it is okay, but that child is visited and is not a parent then there is a
        //problem and hence there will be a cycle.
        {
            return true;
        }
        else
        {
            bool flag = dfs(ch, vertex);
            if (flag == true) {return true;}
        }
    }
    return false;
}
void VivekTiwary_1092()
{
    int v, e; cin >> v >> e;
    adj.resize(v); vis.resize(v);
    for (int i = 0; i < e; i++)
    {
        int x, y; cin >> x >> y;  
        adj[x].pb(y);
        adj[y].pb(x);
    } 

    bool cf = false; //cf -> cycle found.
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            bool flag = dfs(i, 0);
            if (flag == true) 
            {
                cout << "Cycle Exists\n";
                cf = true;
                break;
            }
            
        }
    }
    if (!cf)
    {
        cout << "Cycle Doesn't Exists\n";
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