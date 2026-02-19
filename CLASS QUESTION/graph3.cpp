//Youtube Link :- https://www.youtube.com/watch?v=WOV3LYhPews&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=93
//Why bfs can be used to calculate shortest path?
//In bfs, since before going to the next level, all the nodes at previous level are visited
//once, and the graph is a not weighted(i.e. all the weight are 1), hence it can be used 
//to find the shortest path, between the nodes-> just as we did in graph2.cpp using the 
//level array or can be said as distance array, here we will be using bfs to calculate
//shortest path in a question whose link is given below :-
//https://www.spoj.com/problems/NAKANJ/

//Logic :- if the knight is at a current position, then i can move to 8 other positions,
//we will consider those 8 positions as level 1 node, now it will move to any one of the
//node from those 8 nodes, and from there it can go to next 8 nodes, which will become 
//level 2 nodes and so on, it will become a bfs, and given intial and final destination
//we can find the shortest path or minimum distance between the two.

//This question is important implementation wise as here also we are finding the level in 
//one sense just as we did in graph2.cpp

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int INF = 1e9 + 10;
int vis[8][8];
int level[8][8];

int getX(string s)//to get x cordinate.
{
    return s[0] - 'a';
}

int getY(string s)//to get the y cordinate.
{
    return s[1] - '1';
}

void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            vis[i][j] = 0;
            level[i][j] = INF;
        }
    }
}

bool isValid(int x, int y)//it will ensure that the cordinates we are dealing with lies in 
{//the chessboard only.
    return (x >= 0 && y >= 0 && x < 8 && y < 8);
}

vector<pair<int, int>> movements = 
{
    {1,2}, {-1, 2}, //these are the possible 8 movements, cordinates wise if the knight
    {1,-2}, {-1, -2},//is at a current position in the chess board.
    {2,1}, {2, -1},//pair are in the form of x and y coordinates.
    {-2,1}, {-2, -1}
};

int bfs(string source, string dest)
{
    int sourceX = getX(source);//got x and y cordiantes of the source and destintion string.
    int sourceY = getY(source);
    int destX = getX(dest);
    int destY = getY(dest);

    queue<pair<int, int>> q;//here pair is used as each node has both x and y cordinates.
    q.push({sourceX, sourceY});
    vis[sourceX][sourceY] = 1;
    level[sourceX][sourceY] = 0;

    while(!q.empty())
    {
        pair<int, int> v = q.front();
        int x = v.first; int y = v.second;
        q.pop();

        //going to all the movement nodes or say immediate nodes for the current node v.
        for (auto movement : movements)
        {
            int childX = movement.first + x; //x cordinate of the immediate node
            int childY = movement.second + y;//y cordinate of the immediate node
            if (!isValid(childX, childY)) {continue;}
            if (!vis[childX][childY])//is this immediate node is not visited then we do the following
            {
                q.push({childX, childY});
                vis[childX][childY] = 1;
                level[childX][childY] = level[x][y] + 1;
            }
        }
        if (level[destX][destY] != INF) //this is just a optimization.
        {
            break;
        }
    }
    return level[destX][destY];//this will always give minimum distance between source and
    //destination as this bfs algoritm is meant to give the shortest path, between two levels.
}
void VivekTiwary_1092()
{
    string s1, s2; cin >> s1 >> s2;//s1 and s2 are source and destination.
    cout << bfs(s1, s2) << "\n";
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