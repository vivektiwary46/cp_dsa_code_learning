//In this code we will find tree diameter.
//Tree diameter :- it is the maximum number of edges present between two nodes in a tree.
//More than one diameter can exist in the tree, diameter are not always unique.

//Procedure :- har node pe jayenge aur uske jitne bhi children hai, un sab mese do greatest
//depth wale children ko select karenge aur uss node ke liye un dono depth ka sum us node
//ke ans array mein uss node ke liye store kar denge, similarly sare nodes ke liye karenge aur
//uss ans array ka max will be our diameter.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

//Time complexity :- O(n);

const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];
int ans[N];
int depth[N];

void dfs(int s, int par) //dry run the dfs function for a test case for better understanding.
{
    int m1 = -1, m2 = -1;
    // Store top 2 max depths among the children
    for (int ch : g[s]) 
    {
        if (ch != par) 
        {
            dfs(ch, s);
            if (depth[ch] >= m1) 
            {
                m2 = m1;
                m1 = depth[ch];
            } 
            else if (depth[ch] > m2) 
            {
                m2 = depth[ch];
            }
        }
    }
    // m1, m2 -> max values stored
    // m1 >= m2
    depth[s] = m1 + 1;
    ans[s] = m1 + m2 + 2; // m1 + 1 + m2 + 1 - 2
}

void VivekTiwary_1092()
{
    int n, m; // n is the total number of nodes and m is the total number of edges.
    cin >> n >> m;

    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v; // there is an edge between u and v
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, -1); // Starting DFS from node 1, considering root node as 1.

    // Find the diameter
    int res = -1;
    for (int i = 1; i <= n; i++) 
    {
        res = max(res, ans[i]);
    }
    cout << "The diameter of the tree is " << res << endl;
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
