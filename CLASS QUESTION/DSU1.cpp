//Youtube Link :- https://www.youtube.com/watch?v=zEAmQqOpfzM&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=99
//In this code we will se the use of make_set(), find_set() and union_set() in a dsu.
//The implementaiton shown below are naive implementation and are computed in O(n)
//which is slow.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
int parent[N];

void make_set(int n) //n is a node.
{
    parent[n] = n; //here we have created a individual disjoint set, so here n
    //is the representative of itself, similarly we can make many individual disjoint
    //set and unite them into a set using the union_set() function.
}

int find_set(int n)//n is the node.
{
    if (parent[n] == n) return n;
    return find_set(parent[n]);//recursively calling the find_set() function until we
    //get the representative node.
    //This takes O(N) in worst case but by path compression we can do it in O(1).
}

void union_set(int a, int b)
{
    int p1 = find_set(a);//represetative of set a.
    int p2 = find_set(b);//represetative of set b.
    if (p1 != p2)//if p1 == p2 means both a and b belongs to the same set.
    {
        parent[p2] = p1;
        //parent[p1] = p2; bhi kar sakte hai.
    }
}


void VivekTiwary_1092()
{
    
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