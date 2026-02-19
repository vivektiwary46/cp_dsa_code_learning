//Youtube Link :- https://www.youtube.com/watch?v=xDrLSOxaFrA&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=101
//In this code we will implement Kruskal's Algorithm in a weighted graph.
//In the algoritm we are supposed to find a minimum spannig tree.

//Spanning Tree :- A spanning tree is a tree containing all nodes of the given graph 
//and is a subgraph of the given graph.

//Minimum Spanning Tree(MST) :- A spanning tree whose sum of edges is minimum.

//Process :- 1) sort all the weight and 2) start joining the edges in increasing order
//of the weight and if you get that if we add some egde then a cycle will form then 
//ignore that edge as tree doesn't contains a cycle, finally you will get your MST.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
int par[N]; 
int rnk[N]; 
void make_set(int n) //n is the node.
{
    par[n] = n;
    rnk[n] = 1;
}

int find_set(int n)// n is the node.
{
    if (n == par[n]) return n;
    return par[n] = find_set(par[n]);
}

void union_set_rank(int a, int b)
{
    int p1 = find_set(a);
    int p2 = find_set(b);
    if (p1 == p2) return;

    if (rnk[p1] > rnk[p2]) 
    {
        par[p2] = p1;
    } 
    else if (rnk[p1] < rnk[p2]) 
    {
        par[p1] = p2;
    } 
    else 
    { // equal rank
        par[p2] = p1;
        rnk[p1]++; // increase rank only here
    }
}

void VivekTiwary_1092()
{
    int n, m; //total number of nodes and edges.
    cin >> n >> m;
    
    vector<pair<int, pair<int, int>>> edges;//it will contain the edges and their weight.
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;//edge u se v ka weight wt hai.
        cin >> u >> v >> wt;
        edges.pb({wt, {u,v}});
    }
    sort(edges.begin(), edges.end());//it will sort according to the weight due to 
    //the way we declared edges.
    for (int i = 1; i <= n; i++)
    {
        make_set(i);//making the individual nodes.
    }

    int total_cost = 0;
    for (auto &edge : edges)
    {
        int wt = edge.f;
        int u = edge.s.f;
        int v = edge.s.s;
        if (find_set(u) == find_set(v)) {continue;}//tree doesn't contains cycle, so it
        //checks if we inclue the current edge u to v then will it create a cycle in our
        //tree.
        union_set_rank(u,v);//if u to v doesn't form a cycle.
        total_cost += wt;
        cout << u << " " << v << "\n";
    }
    cout << total_cost << "\n";

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