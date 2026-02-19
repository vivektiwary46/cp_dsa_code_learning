//In this code we are implementing the algorithm for topological sort, you can read about
//from pdf 26, 27.
//Topological sort is only carried for a directed acyclic graph (DAG).
//you can also see the code here : https://csacademy.com/code/gI2Mmiuf/
//can also watch the algorithm at g-22 of striver graph playlist
//this code of topo sort implemented with the help of bfs is known as khan's algorithm.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
vector<int> g[N]; //it gives us the adjacency list.
int in_degree[N];//global array are already intialized to zero.

void VivekTiwary_1092()
{
    int n, m; cin >> n >> m; //n is the total number of nodes and m is the total number of
    //edges.

    // Reset data structures for each test case
    for (int i = 1; i <= n; i++) 
    {
        g[i].clear();
        in_degree[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int v1, v2; cin >> v1 >> v2;//there is an edge from v1 to v2;
        g[v1].pb(v2);
        in_degree[v2]++;//as v1 se v2 ke taraf edge hai so v2 ka indegree increase hoga.        
    }

    queue<int> q;
    for(int i=0; i<n; i++)
    {
    	if(in_degree[i] == 0)
        {
    		q.push(i);
    	}
    }

    vector<int> topo_sort;
    while(!q.empty())
    {
    	int x  = q.front(); //x ka indree 0 hoga, isliye wo queue mein pushed hai.
    	q.pop();
    	topo_sort.push_back(x);

    	for(int i=0; i < g[x].size(); i++)
        {
    		int y = g[x][i];
    		in_degree[y]--;
    		if(in_degree[y] == 0)
            {
    			q.push(y);
    		}
    	}
    }
    for (int i = 1; i < topo_sort.size(); i++)
    {
        cout << topo_sort[i] << " ";
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