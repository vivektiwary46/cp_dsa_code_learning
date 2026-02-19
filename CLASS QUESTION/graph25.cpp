//In this code we will find lowest common ancestor in a tree, we will use binary lifting
//to do so, read the flow of doing it from pdf 31.
//In this mentioning the root node is important as depth of root node should be intialized
//to 0, here taken root node as 1.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

//Time complexity : O(q*log2(n));

const int N = 1e5 + 10;
vector<vector<int>> g;
vector<vector<int>> par;
vector<int> depth; //created depth array to store levels of nodes.
int n, x;

void dfs(int s, int p) 
{
    par[s][0] = p; // Store the immediate parent of s i.e. 2^0th parent of s.
    for (int j = 1; j < x; j++) 
    {
        if (par[s][j - 1] != -1) 
        {
            par[s][j] = par[ par[s][j - 1] ][j - 1];
        }
    }
    for (auto ch : g[s]) 
    {
        if (ch != p) 
        {
            depth[ch] = depth[s] + 1;
            dfs(ch, s); // normal dfs.
        }
    }
}

// Function to find the k-th ancestor of a node
int find_kth(int s, int k) 
{
    for (int j = x - 1; j >= 0; j--) 
    {
        if ((1LL << j) & k) // Check if the j-th bit in k is set
        { 
            s = par[s][j];  // Move to the 2^j-th parent
            if (s == -1) break; // If no ancestor exists
        }
    }
    return s;
}

//Function to find the lowest common ancestor between the node a and b.
int lca (int a, int b)
{
    //i am assuming that always depth of node b is higher than depth of node a
    //so if depth[a] <= depth[b], i will swap a and b, that is what has been done below.
    if (depth[a] > depth[b])
    {
        int temp = a; 
        a = b;
        b = temp;
    }
    //changing the level of b to level of a
    int d = depth[b] - depth[a];
    b = find_kth(b, d); //now a and b are at same level.
    //after changing the level if a and b becomes equal, it means a was the lca, which is
    //the corner case.
    if (a == b) {return a;} //corner case dealt.
    for (int j = x; j >= 0; j--)
    {
        if (par[a][j] != par[b][j])//first time when this happnes our goal is met and 
        //par[a][0] becomes the lca.
        {
            a = par[a][j];
            b = par[b][j];
        }
    }
    return par[a][0];
}


void VivekTiwary_1092()
{
    cin >> n; //the number of nodes.
    x = log2(n) + 1;
    g.resize(n + 1);
    depth.resize(n + 1);
    depth[1] = 0;//depth of the root node should be intialized to 0.
    par.assign(n + 1, vector<int>(x, -1)); // Parent table
    //yaha vector<int>(x, -1) isliye banaya as 0 pe 2^0 wala parent hoga v ka
    //1 pe 2^1th parent hoga v ka, similarly x pe 2^(x-1)th parent hoga v ka, so itne 
    //mein sabse highest ware ancestor bhi mil jayega v ka aur aise n vertex hai so  
    //(n + 1, vector<int>(x, -1)).

    // Adjacency list representation of the tree
    for (int i = 1; i < n; i++) 
    {
        int u, v; // Input edges
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, -1); //calling dfs.
    int q; // Number of queries
    cin >> q;
    while (q--) 
    {
        int a, b; // we need to find lca between a and b.
        cin >> a >> b;
        cout << lca(a, b) << "\n";
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
