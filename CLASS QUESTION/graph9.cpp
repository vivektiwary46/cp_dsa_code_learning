//You have been given a tree of n nodes with root at 0. Find level of each node using DFS.
//Note jo tree input lenge uska root node 0 ho.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
vector<int> g[N]; //it gives us the adjacency list.
int vis[N];
int level[N];//global array are already intialized to zero.

void dfs(int node)
{
    vis[node]= 1;
    level[0] =0;
    for(auto child: g[node])
    {
        if ( ! vis[child] )
        {
            level[child]=level[node]+1;
            dfs(child);
        }
    }
}

//the dfs function can also be written as
// void dfs(int node, int par)
// {
//     level[0] = 0;
//     for(auto child: g[node])
//     {
//        if (child != par)
//        {
//            level[child]=level[node]+1;
//            dfs(child);
//        }
//     }
// }
//aur main mein dfs(0, -1) call kar denge this code will work and no requirement of visited
//array will be there as in a tree every node has a single parent, hence the if statement
//if (child != par) will just work like a visited array here.


void VivekTiwary_1092()
{
    int n, m; cin >> n >> m; //n is the total number of nodes and m is the total number of
    //edges.
    

    // Reset data structures for each test cases.
    for (int i = 0; i < n; i++) {
        g[i].clear();
        vis[i] = 0;
        level[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int v1, v2; cin >> v1 >> v2;//there is an edge from v1 to v2;
        g[v1].pb(v2);
        g[v2].pb(v1);//this is for an undirected graph, incase if we want to solve
        //for a directed graph then line 23 should be commented.
    }
    // Perform DFS starting from root node (0)
    dfs(0);

    // Output the levels of all nodes
    cout << "Node\tLevel\n";
    for (int i = 0; i < n; i++)
    {
        cout << (i) << "\t" << level[i] << "\n";
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