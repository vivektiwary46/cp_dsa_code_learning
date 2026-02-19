//This is the standard code for DFS.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

//Time Complexity :- O(n + c*m), c is some constant hence overall time complexity will
//be of the order of O(n + m) as sare node pe jayega aur har node ka jitna degree hai
//utna us particular node ke liye bhi jayega so like in udirected graph overall O(n + 2*e)
//hoga as usme total degree 2*e hota hai.

const int N = 1e5 + 10;
vector<int> g[N]; //it gives us the adjacency list.
int vis[N];//global array are already intialized to zero.

void dfs(int vertex)
{
    cout << vertex << "\n";
    vis[vertex] = 1;
    for (auto child : g[vertex])
    {
        cout << "par " << vertex << ", child " << child << "\n";
        if (vis[child]) {continue;}//if the child is already visited we will go to the next
        //child due to the for loop.
        dfs(child);//here we are recursively calling dfs again on the child which is not
        //visited, so now its child will be dealt and in this manner whole of the depth for 
        //all the nodes are visited.
        //if you don't understand how backtracking is done in this code due to recursion
        //copy all the code and ask chaptgpt about it, although explained below.

        //Imagine you're exploring a tree or a maze. You start from a node and explore 
        //all its paths (children).

        //When you reach a "dead end" (a node with no unvisited children), you go back to 
        //the node you came from and continue exploring other unvisited paths from there.

        //In the code, this happens automatically because after the recursive call to 
        //dfs(child) finishes, the control goes back to the for loop of the parent node's 
        //DFS function. The loop then continues to check for other children.

        //Every time a new dfs call is made, the current state (node and its children) 
        //is saved on the call stack.

        //When a dfs call finishes, the saved state is "popped" off the stack, and the 
        //function resumes from where it left off in the parent node.

        //overall ek node is said to be complete, i.e. all its neighbours are visited
        //when its for loop is complete.
    }
}

void VivekTiwary_1092()
{
    int n, m; cin >> n >> m; //n is the total number of nodes and m is the total number of
    //edges.
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