//In this we will implement the kosaraju's algorithm
//Youtube Link :- https://www.youtube.com/watch?v=R6uoSjZ2imo -> watch it from 0 to 15:45 mins.

//This algoritm is only for a directed graph and we will find the number of scc's in
//the graph and the nodes present in the each scc.

//Procedure of the algorithm to find scc :- 
//1)Run dfs on given graph G and find the nodes in decreasing order of finish time 
//(Topological Sorting) and push it in a stack.
//2)Create a new graph GT, which has all the edges reversed from the original graph. 
//3)Start DFS in this new graph GT, in the topological order of G. Each node visited by 
//dfs() call of a node, belong to the same SCC component.

//Here we are only printing the scc's but we can also further convert the original graph into
//a scc-condensed graph or a DAG, to see that the following submission can be seen :-
//Solution :- https://www.codechef.com/viewsolution/40482695

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

vector<bool> vis;         //visited vector.
vector<vector<int>> g;    //adjacency list for the original graph.
vector<vector<int>> gr;   //adjacency list for the reversed graph.
stack<int> st;
vector<int> component;    //each scc ke sare nodes ko store karne ke liye.
vector<vector<int>> sccs; //sare scc ke nodes ko store karne ke liye.

void dfs1(int node) //dfs1 is run to do the topological sort.
{
    vis[node]=true;
    for(auto it: g[node])
    {
       if(!vis[it])
       {
          dfs1(it);
       }
    }
   st.push(node); //stack mein decreasing order of finishing time mein nodes store ho 
   //jayega and then dfs2 isi stack pe call karenge in the same order in which nodes
   //would be present in the stack i.e. decreasing order of finishing time mein.
}

void dfs2(int node)// it is called on the stack prepared while running dfs1.
{
    vis[node]=true;
    for(auto it: gr[node])
    {
        if(!vis[it])
       {
           dfs2(it);
       }
    }
    component.push_back(node); //ek bar dfs call khatam hoga, toh ek scc ke sare components
    //component mein push back ho chuka hoga, aur dfs2 will be called exactly the same number
    //of time as the number of scc in the graph.
}


void VivekTiwary_1092()
{
    int n, m;//total number of nodes and the edges.
    cin >> n >> m;
    g.resize(n + 1);
    gr.resize(n + 1);
    for(int i = 1; i <= m; i++)
    {
       int u, v; //there is a directed edge between u and v.
       cin >> u >> v;
       g[u].push_back(v);  //for the original graph.
       gr[v].push_back(u); //for the revesred graph. 
    }
    vis.assign(n + 1,false);
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
           dfs1(i); //calling dfs1 taki stack prepare ho jaye.
        }
    }
    vis.assign(n + 1,false); //again making the visited vector false before i call dfs2
    //to get the scc's.
    while(!st.empty())
    {
        int t = st.top();
        st.pop();
        if(!vis[t]) 
        {
            component.clear();
            dfs2(t); //running dfs2 to get the scc's in the reverse graph in topological order
            //of original graph.
            sccs.push_back(component);
        } 
    }

    cout << "The number of scc's in the graph is/are : " << sccs.size() << "\n";
    cout << "The component in each scc's are : " << "\n";
    for (auto component : sccs)
    {
        for (auto node : component)
        {
            cout << node << " ";
        }
        cout << "\n";
    } 

    // Clear vectors for reuse in multiple test cases
    g.clear();
    gr.clear();
    sccs.clear();
    vis.clear();
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
