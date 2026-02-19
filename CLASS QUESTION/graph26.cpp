//Prim's Algorithm.
//Problem Statement: Given a weighted, undirected, and connected graph of V vertices and E 
//edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
//(Sometimes it may be asked to find the MST as well, where in the MST the edge-informations 
//will be stored in the form {u, v}(u = starting node, v = ending node).)

//Here we are using the Prim's Algorithm to solve the above problem statement.
//Youtube Link :- https://www.youtube.com/watch?v=mJcZjjKzeqk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=45

//It is for a undirected graph and it can have cycles but when the graph is run through
//the algorithm then the graph will be a mst which is a tree.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//TC :- so in total ElogE + ElogE which is Elog(E).
int sum = 0; //will store the mst sum.
vector<int> vis;
vector<pair<int,int>> mst; //will store the mst information.
vector<vector<pair<int, int>>> adj;

int prims_Algorithm(int source)
{
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {source, -1}});
    while(!pq.empty()) //at max E entry hoga
    {
        auto it = pq.top(); //as at max E entry so, logE for top() operation
        pq.pop();
        int node = it.s.f;
        int wt = it.f;
        int parent = it.s.s;

        if (vis[node] == 1) {continue;}

        vis[node] = 1;
        sum += wt;

        if (parent != -1)
        {
            mst.pb({parent, node});
        }

        for (auto it : adj[node])//here also E
        {
            int adjNode = it.f;
            int edjwt = it.s;
            if (!vis[adjNode]) 
            {
                pq.push({edjwt, {adjNode, node}});//logE
            }
        }
    }
    return sum;
}

void VivekTiwary_1092()
{
    int v, e; cin >> v >> e;
    adj.resize(v);  vis.resize(v);
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].pb({v, wt});
        adj[v].pb({u, wt});
    }

    cout << "Sum of weights of edges of mst is " << prims_Algorithm(0) << endl;
    cout << "The mst is :-\n";
    for (auto it : mst) 
    {
        cout << it.f << " - " << it.s <<endl;
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