//Given a tree, you need to find the gcd of all the values of nodes in subtree of 
//every node. 0 is root node
//consider a tree, the edges are given as 1 -> 2, 1 -> 5, 2 -> 3, 2 -> 4, 5 -> 6, yaha
//root node 1 le lie hai, here we are just doing as an example, so har node pe koi value
//stored hoga jiska gcd nikalna hai, so in this tree ans[2] = gcd(val[2], val[3], val[4]).

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
vector<int> g[N]; //it gives us the adjacency list.
int ans[N];
int val[N];

void dfs(int node, int parent)
{
    ans[node]= val[node];
    for(auto child : g[node])
    {
        if (child != parent)
        {
           dfs(child, node);//Pass the current node as parent
           ans[node] = __gcd(ans[node], ans[child]); //yaha in gcd fuction ans[node]
           //mein val[node] hai, aur wo recursively ek subtree ke liye gcd nikal dega.
        }
    }

}

void VivekTiwary_1092()
{
    int n, m; cin >> n >> m; //n is the total number of nodes and m is the total number of
    //edges.

    //Reset data structures for each test cases.
    for (int i = 0; i < n; i++)
    {
        val[i] = 0;
        ans[i] = 0;
        g[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        int v1, v2; cin >> v1 >> v2;//there is an edge from v1 to v2;
        g[v1].pb(v2);
        g[v2].pb(v1);//this is for an undirected graph, incase if we want to solve
        //for a directed graph then line 23 should be commented.
    } 

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

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