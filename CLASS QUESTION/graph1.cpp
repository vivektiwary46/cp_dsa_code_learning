//Here we are writing the code for a graph traversal method, i.e. breadth for search(bfs).
//In bfs we travel layer by layer and print all the node only once, to ensure that all the 
//nodes are printed exactly once, we create a visited array, which tells that have we went 
//to that node or not, we need to go to each node exactly once.
//In this method, we require a queue and a adjacency list, in order to print all the layers systamatically.
//https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/ - can watch the video
//at last to underestand the code from 0 to 11 mins.
//The code is written for a undirected graph and unweighted graph.
//See at last after main written what to do in case of a multisource bfs.
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

// BFS from given source s
void bfs(vector<vector<int>> &adj, int s)
{
    // Create a queue for BFS
    queue<int> q;
    // Initially mark all the vertices as not visited
    // When we push a node into the q, we mark it as 
    // visited
    vector<bool> visited(adj.size(), 0);
    // Mark the source node as visited and 
    // enqueue it
    visited[s] = 1;
    q.push(s);
    // Iterate over the queue
    while (!q.empty())
    {
        // Dequeue a vertex from queue and print it
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        // Get all adjacent nodes of the dequeued 
        // node i.e. curr and If an adjacent node has not been 
        // visited, mark it visited and enqueue it
        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v); //here as we are considering a undirected graph.
    adj[v].push_back(u); //here u, v represent ki u aur v ke bech mein ek edge hai.
}

void VivekTiwary_1092()
{
    int n = 8; //n is the number of nodes in the graph.
    vector<vector<int>> adj(n); // Adjacency list representation of the graph.
    //Just we need to add all the edges in the graph and the adjacency list will 
    //be created.
    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 2, 7);
    addEdge(adj, 3, 7);
    
    // Perform BFS traversal starting from vertex 0
    cout << "BFS starting from 0 : \n";
    bfs(adj, 0);
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
//Multisource BFS
//If there are multiple sources, we will put the all source vertices to the queue at 
//first rather than a single vertex which was in case of standard BFS.This way Multisource 
//BFS will first visit all the source vertices. After that it will visit the vertices which 
//are at a distance of 1 from all source vertices, then at a distance of 2 from all source 
//vertices and so on and so forth. Rotten oranges on leetcode can be solved
//and g-10 of striver is rotten oranges.