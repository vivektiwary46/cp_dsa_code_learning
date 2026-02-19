//Youtube Link :- https://www.youtube.com/watch?v=oib-XsjFa-M

//In this code we are implementing binary lifting i.e. we are given a tree and a node s
//and we need to find the kth parent of s.
//one easier way to do it is by simple for loop like this for (int i = 0; i < k; i++)
//{s = par[s]; return s;} but this will take O(n) time per query but we want to do it in
//log(n) time per query.

//n se logn time complexity jane ke liye ya toh 2 se divide karte jao as incase of binary
//search or 2 ke power ka use karke kam karo, as here in binary lifting.

//any number n can be represented in terms of binary number and there are in total 
//log2(n) + 1 bits in the number and it is evident that the number n can be resented as
//sum of powers of 2 due to binary representation so instead of jumping k times to the 
//ancestor we will jump to ancestors in powers of 2 manner as k can be represented in 
//powers of 2, so in worst case if all the bits are set we need to jump log2(n) + 1 times
//basically log2(n) times so we can compute the kth ancestor in O(log2(n)) per query.
//below is the way to compute the 1, 2, 4, 8, 16.... i.e. power of 2 ancestors of s :-
 
//par[v][0] = par[v]; -> 1st parent of v i.e. 2^0 parent of v.
//par[v][1] = par[ par[v][0] ][0]; -> this represents the 0th parent of parent of v, which
//is 2^1 parent of v.
//par[v][2] = par[ par[v][1] ][1]; -> this is 2^2 parent of v.
//par[v][3] = par[ par[v][2] ][2]; -> this is 2^3 parent of v.
//par[v][4] = par[ par[v][3] ][3]; -> this is 2^4 parent of v.
//so in general par[v][j] -> 2^jth parent of v which is equal to par[ par[v][j-1] ][j-1].


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

void VivekTiwary_1092()
{
    cin >> n; //the number of nodes.
    x = log2(n) + 1;
    g.resize(n + 1);
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
        int node, k; // Node and k-th ancestor to find
        cin >> node >> k;
        cout << find_kth(node, k) << "\n";
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
