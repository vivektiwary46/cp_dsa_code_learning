//Youtube Link :- https://www.youtube.com/watch?v=SQOQ99stCas&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=94
//What is a 0-1 bfs?
//Normally bfs is not weighted i.e. all the edges has same weight i.e. 1 or any value,
//but here the edges can have the weight as 0 or 1, but still we can implement bfs here 
//i.e. we can still find levels i.e. distance between each level, for this we will take 
//the advantage of the fact that the value of each edge is zero or one.
//firstly we enqueue the source node in the queue and when we will go to the next level
//we will see whose edge value is 1 and whose is 0, the one with 0, will be just and one
//level before than the one's with the value 1, so they will be pushed at the start of 
//the queue as they should be daelt first, and one with edge value 1 will be pushed at
//the back, as they should be dealt after the one's whose edge value is zero, similarly 
//it should be done with the consecutive nodes in order to get the distance between each
//node.

//Jaha bhi you find that weight of edges in the graph is 0 or 1, we can apply the above
//algorithm. 

//see the youtube video from 8:11 to 12:11 mins to understand the question and logic since 
//question is added to some other section of codechef so it is not visible.
//in this question we want the shortest path between 1 and n, and the weight of the 
//egdes are 0 or 1 and so 0-1 BFS can be applied here to find the minimum distance between
//1 and n here.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];//incase of weighted graph we store both the node and its 
//weight so pair is used.
vector<int> level(N, INF);
int n, m;

int bfs()
{
    deque<int> q;
    q.pb(1);
    level[1] = 0;

    while(!q.empty())
    {
        int cn = q.front(); //cn -> current node.
        q.pop_front();
        for (auto child : g[cn]) 
        {
            int chn = child.f; //chn -> child of node(current node).
            int wt = child.s;
            if (level[cn] + wt < level[chn])
            {
                level[chn] = level[cn] + wt;
                if (wt == 1) {q.pb(chn);}
                else {q.push_front(chn);}
            }
        }
    }
    return level[n] == INF ? -1 : level[n];
}

void VivekTiwary_1092()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y; //from node x to y there is a edge with weight 0;
        cin >> x >> y;
        if (x == y) {continue;}
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});//we created a reverse edge from y to x kepping its weight 1.    
    }
    cout << bfs() << endl;
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