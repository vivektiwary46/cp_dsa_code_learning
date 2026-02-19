//Here we want to find a cycle in an undirected graph with the help of dsu.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
int par[N]; //parent array.
int rnk[N]; //rank is a reserved word so using rnk.
//rnk is the size array, individual node ka size one hoga, agar koi tree mein 3 element 
//hai toh uske representative element ka size 3 hoga.

void make_set(int n) //n is the node.
{
    par[n] = n;
    rnk[n] = 1;//individual node ka size 1 hoga.
}

int find_set(int n)// n is the node.
{
    if (n == par[n]) return n;
    //path compression -> see how is the path compression actually working recursively
    //by the youtube link from 17 mins to 21 mins.
    return par[n] = find_set(par[n]);
}

//union by rank.
//In this we utilize the rnk array made to make the smaller set as child of larger set.
//This way reduces the time complexity to O(1) but it is heuristic that is there is 
//no mathematical proof for it but it works.
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

    vector<pair<int, int >> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.pb({u,v});
    }
    for (int i = 1; i <= n; i++) { make_set(i); }//individual nodes created.
    for (auto &edge : edges)
    {
        int u = edge.f;
        int v = edge.s;
        if (find_set(u) == find_set(v))//if u and v are connected and have same parent 
        //then if forms a cycle.
        {
            cout << "Cycle Found" << "\n";
            return;
        }
        union_set_rank(u,v);//edge u and v connected.
    }
    cout << "No Cycle Found" << "\n";
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