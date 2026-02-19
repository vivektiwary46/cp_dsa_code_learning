//Youtube Link :- https://www.youtube.com/watch?v=zEAmQqOpfzM&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=99
//Here we will modify the make_set(), find_set(), union_set() functions in oreder to reduce
//the time complexity of find_set() and union_set() to O(1).
//To do so we use path compression in find_set() and union by rank in union_set().

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;
int par[N]; //parent array.
int rnk[N]; //rank is a reserved word so using rnk.
int size[N];

void make_set(int n) //n is the node.
{
    par[n] = n;
    rnk[n] = 1;
    size[n] = 1;
}

int find_set(int n)// n is the node.
{
    if (n == par[n]) return n;
    //now here by recurssion we have done the path compression, if we would have only 
    //written return find_set(par[n]) in line 36 the find_set would have just given the representative
    //element of node n, and it would have taken O(log(N)) time but we need to do the path
    //compression and we did it by returing par[n] = find_set(par[n]), so har node in between
    //which we got from node n till getting the representative element, raste mein sare
    //node ke par to representative element ke equal kar die, so now it take O(alpha(N))
    //which is approximately equal to O(1).
    //take a linear graph and make a recursion tree we would get it.
    return par[n] = find_set(par[n]);
}

//union by rank.
//In this we utilize the rnk array made to make the smaller set as child of larger set.
//This way reduces the time complexity to O(1) but it is heuristic that is there is 
//no mathematical proof for it but it works.
void union_set_rank(int a, int b)
{
    int p1 = find_set(a);
    int p2 = find_set(b);
    if (p1 == p2) return;

    if (rnk[p1] > rnk[p2]) 
    {
        par[p2] = p1;
    } 
    else if (rnk[p1] < rnk[p2]) 
    {
        par[p1] = p2;
    } 
    else 
    { // equal rank
        par[p2] = p1;
        rnk[p1]++; // increase rank only here
    }
    //union by rank mein path compression ho raha hai jisse we are not getting
    //the actual number of nodes present in the tree at each step after the union
    //because of the nature of the rank array and how we are increasing it but union
    //by size mein bhi path compression ho raha hai but still at each step after union
    //tree mein kitne nodes hai we know because of the nature of the size array and 
    //how we are increasing it in the code.
}

void union_set_size(int a, int b)
{
    int p1 = find_set(a);
    int p2 = find_set(b);
    if (p1 == p2) return;

    if (size[p1] > size[p2]) 
    {
        par[p2] = p1;
        size[p1] += size[p2]; // update size
    } 
    else 
    {
        par[p1] = p2;
        size[p2] += size[p1]; //isme equal to aur size[p1] < size[p2] dono case cater hoga.
    }
}

//The time complexity of find_set() and union_set() (both of union by rank and union by size)
// when you use both path compression and union by rank is O(alpha(N)). alpha(N) = 
//Inverse ackermann function which is approximately equal to O(1).

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