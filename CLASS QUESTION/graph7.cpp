//Code for DFS when you need to calculate colour of each node at every instant
//Color codes in DFS :-
//White: Unvisited node
//Gray: Visited but not finished node
//(Visited but all its neighbours are not visited)
//Black: Finished node
//(Visited and all its neighbours are also visited)
//Talking in reference to the standard dfs code.
//jis node ka color black ho gaya means uska for loop over ho gaya hai, aur backtrack hoke
//uske parent node ke for loop pe control chala jayega, jo abhi grey hoga and once iska
//bhi for loop khatam ho jayega(means all neighbours are visited) toh wo black 
//ho jayega and so on..... but intially sare ndoe white honge.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
vector<int> g[N]; //it gives us the adjacency list.
int color[N];//global array 0 se hi initalize hota hai.
//in the color array 0 -> signifies white color , 1 -> signifies grey and 2 -> signifies 
//black color.

void print_colors(int n) {//This function is written to output the color of each nodes 
    cout << "Colors of nodes: ";//at a every instant.
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {cout << "White" << " ";}
        if (color[i] == 1) {cout << "Grey" << " ";}
        if (color[i] == 2) {cout << "Black" << " ";} 
    }
    cout << "\n";
}

void dfs(int vertex, int n) {
    color[vertex] = 1; // Mark as Grey
    cout << "Visiting node " << vertex << " (Grey)\n";
    print_colors(n); // Output color state 

    for (auto child : g[vertex]) 
    {
        if (color[child] == 0) // If the child is White
        { 
            dfs(child, n);
        }
    }

    color[vertex] = 2; // Mark as Black
    cout << "Finished node " << vertex << " (Black)\n";
    print_colors(n); // Output color state
}

void VivekTiwary_1092()
{
    int n, m; cin >> n >> m; //n is the total number of nodes and m is the total number of
    //edges.

    for (int i = 1; i <= n; i++) 
    {
        g[i].clear(); // Clear adjacency list for multiple test cases
        color[i] = 0; // Reset colors to White
    }

    for (int i = 0; i < m; i++)
    {
        int v1, v2; cin >> v1 >> v2;//there is an edge from v1 to v2;
        g[v1].pb(v2);
        g[v2].pb(v1);//this is for an undirected graph, incase if we want to solve
        //for a directed graph then line 23 should be commented.
    }

    // Start DFS from node 1
    cout << "Starting DFS from node 1\n";
    dfs(1, n);
    
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