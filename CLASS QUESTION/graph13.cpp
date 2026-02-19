//Here also we will do same as graph12.cpp i.e. implememt topological sort, but here we will
//take help of the dfs and stack to do so, we will use the advantage of the simple
//observation that topological sort is order of nodes in decreasing order of finishing 
//times i.e. jis node ka finish time last hoga wo linear odering mein phele ayega.
//can also see the code at : https://www.geeksforgeeks.org/problems/topological-sort/1
//and the explanation video from g-21 of striver graph playlist.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
vector<int> g[N]; //it gives us the adjacency list.
int vis[N];//global array are already intialized to zero.
stack<int> st;

void dfs(int node)
{
    vis[node]=true;
    for(auto child: g[node])
    {
        if ( ! vis[child] )
        {
            dfs(child);
        }
    }
    st.push(node);// push to stack when finished  
}


void VivekTiwary_1092()
{
    int n, m; cin >> n >> m; //n is the total number of nodes and m is the total number of
    //edges.

    // Reset data structures for each test case
    for (int i = 0; i < n; i++) 
    {
        g[i].clear();
        vis[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int v1, v2; cin >> v1 >> v2;//there is an edge from v1 to v2;
        g[v1].pb(v2);//since topological sort is only for directed acyclic graph.                
    }

    dfs(1);

    while(!st.empty())
    { 
        cout << st.top() << " ";
        st.pop();
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
