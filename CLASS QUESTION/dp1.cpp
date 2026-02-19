//int fib(int x)
//{
//    //N = 1, 2, 3, 4, 5, 6....
////fib(N)= 0, 1, 1, 2, 3, 5....
//    if (x == 1) {return 0;}
//    if (x == 2) {return 1;}
//    else return fib(x-1) + fib(x-1);
//}
//Above is the code of fibonacci series and its TC is O(2^N) but we want to reduce it to O(N)
//for this we use dp array.  
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
//NOTE :- This is a recursive dp, in dp2.cpp, same code is written but with iteration.
//This is an example of top down approach.
const int MAX = 1e4 + 1;
int dp[MAX];

int fib(int n)
{
    if (n == 1) {return 0;}
    if (n == 2) {return 1;}
    if (dp[n] != -1) {return dp[n];}    //Line 27 and 28 are together called memoization
    return dp[n] = fib(n-1) + fib(n-2); //i.e. using the value stored in dp array to reduce function calls.
    //dp[n] = fib(n-1) + fib(n-2) => it is the recurrence relation, in dp it is always very important
    //to find the reurrence relation, as after that we only need to code and to find this 
    //relation we need to break the problem in subproblems as yaha fib(n) chahiye toh uske liye
    //phele fib(n-1) & fib(n-2) chahiye hoga which is the subproblem, jiske help we can 
    //create the relation.
}
//TC = O(N);
//Generally dp array ka jo size hota hai multiplied by dimension of base case (here 2 i.e. n == 1 & n == 2)
//is the time complexity ,it is a very general statement, so here it becomes O(2n) which is same as O(n).
//when we see the recursive tree visualizer there are acually 8 operations for n == 5, which is like 2n-1 operations
//so TC = O(n) only.
void VivekTiwary_1092()
{
    int n;
    cin >> n;
    cout << fib(n);
}
//NOTE :- jab ham recursive function likhte hai toh usme number of base cases is equal to jo 
//function ham banaye hai uska number of dependencies, like here fib(n), ka 2 subproblem hai,
//ki fib(n) find karne ke liye fib(n-1) & fib(n-2) find karna hoga, hence 2 dependencies,
//so number of base cases also equal to 2.
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp)); //we intialized the values in the dp array as -1.
    int t = 1;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}
//When to apply dp :-
//1)when we need to find min or max of something i.e. to do optimization.
//2)when we need to find the number of ways of something i.e. combinatronics and probability.
//3)when we need to find that something is possible or not i.e. yes or no problems.