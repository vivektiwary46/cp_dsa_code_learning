//Youtube Link :- https://www.youtube.com/watch?v=xvi8PqRrAyU&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=95
//What is a multisource BFS ?
//If there are multiple sources, we will put the all source vertices to the queue at first
//rather than a single vertex which was in case of standard BFS.This way Multisource BFS 
//will first visit all the source vertices. After that it will visit the vertices which 
//are at a distance of 1 from all source vertices, then at a distance of 2 from all 
//source vertices and so on and so forth, due to this if we want to find for a particular
//node, that which source node has minimum distance from it, we can do it as, agar wo s1 se
//2 distance ke duri pe hai aur s2 se wo 1 ditance ke duri pe hai, so wo s2 ka child banega
//aur level 1 mein add hojayega, aur uska visited true hojayega, hence, we will know ki it
//has minimum distance from s2, similarly can be computed for others nodes as well.

//Question Link :- https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/
//Logic :- All the ones with maximum value in the grid will become the source and from 
//each source we can move(assigning max value) in some directions, so these will become
//immediate neighbours and so on..., the cordinate with max level will be our answer, as 
//to reach there max time would be taken, so it is a problem of multsource BFS.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int val[N][N];
int vis[N][N];
int level[N][N];
int n, m;

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = 0;
            level[i][j] = INF;
        }
    }
}

bool isValid(int i, int j)//it will ensure that the cordinates we are dealing with lies in 
{//the n cross m matrix only.
    return (i >= 0 && j >= 0 && i < n && j < m);
}

vector<pair<int, int>> movements = 
{
    {0,1}, {0,-1}, //these are the possible 8 movements, for a node, it will be assigned 
    {1,0}, {-1,0},//maximum value from these possible nodes, or movements.
    {1,1}, {-1,1},
    {1,-1}, {-1,-1}
};

int bfs()
{
    int mx = 0;
    for (int i = 0; i < n; i++) //we are finding the maximum value in the matrix so that
    {//we can get the index of all the places where value is max and all those indexes
        for (int j = 0; j < m; j++)//will be our source.
        {
            mx = max(mx, val[i][j]);
        }
    }
    queue<pair<int, int>> q;//here pair is used as each node has both x and y cordinates.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (val[i][j] == mx)
            {
                q.push({i,j});
                vis[i][j] = 1;
                level[i][j] = 0;
            }
        }
    }
    int ans = 0; //ans mein wo level hoga jispe pahuchne mein max time lagega.
    while(!q.empty())
    {
        auto v = q.front();
        int vX = v.first;
        int vY = v.second;
        q.pop();

        //going to all the movement nodes or say immediate nodes for the current node v.
        for (auto movement : movements)
        {
            int childX = movement.first + vX;//x cordinate of the immediate node
            int childY = movement.first + vY;//y cordinate of the immediate node
            if (!isValid(childX, childY)) {continue;}
            if (vis[childX][childY] == 1) {continue;}
            q.push({childX, childY});//is not visited then we push it in the queue.
            vis[childX][childY] = 1;
            level[childX][childY] = level[vX][vY] + 1;
            ans = max(ans, level[childX][childY]);
        }

    }
    return ans;
}

void VivekTiwary_1092()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> val[i][j];
        }
    }
    cout << bfs() << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        reset();//at every test case the level and visited array should be initailized to 0.
        VivekTiwary_1092();
    }
    return 0;
}
