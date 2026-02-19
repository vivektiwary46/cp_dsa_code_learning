//Before going through this study graph6.cpp
//Here also we will perform graph traversal using dfs but here we will calculate visiting
//time and finishing time for each node.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
vector<int> g[N]; //it gives us the adjacency list.
int vis[N];//global array is already intialized to zero.
int visTime[N];
int finishTime[N];
int timerCode = 1; 

void dfs(int node)
{
    vis[node] = 1;// Mark the node as visited
    visTime[node]=timerCode;// Record visiting time
    timerCode++;

    for(auto child: g[node])
    {
        if ( ! vis[child] )
        {
            dfs(child);
        }
    }

    finishTime[node] = timerCode;// Record finishing time
    timerCode++;
}

void VivekTiwary_1092()
{
    int n, m; cin >> n >> m; //n is the total number of nodes and m is the total number of
    //edges.

    // Reset data structures for each test case
    for (int i = 1; i <= n; i++) 
    {
        g[i].clear();
        vis[i] = 0;
        visTime[i] = 0;
        finishTime[i] = 0;
    }
    timerCode = 1;

    for (int i = 0; i < m; i++)
    {
        int v1, v2; cin >> v1 >> v2;//there is an edge from v1 to v2;
        g[v1].pb(v2);
        g[v2].pb(v1);//this is for an undirected graph, incase if we want to solve
        //for a directed graph then line 23 should be commented.
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])//this is the standard way to call the dfs, here we will start with
        {//dfs(1) and whole part of the graph which has 1 as source will be traversed
            dfs(i);//but if there is any disconnected graph then, that section will
        }//be also taken care off, due to this way of calling dfs, agar sirf dfs(1) call 
    }//kar die hote toh disconnected wale part traverse nahi hote.

    // Print visiting and finishing times for all nodes
    cout << "Node\tVisiting Time\tFinishing Time\n";
    for (int i = 1; i <= n; i++) 
    {
        cout << i << "\t" << visTime[i] << "\t\t" << finishTime[i] << "\n";
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