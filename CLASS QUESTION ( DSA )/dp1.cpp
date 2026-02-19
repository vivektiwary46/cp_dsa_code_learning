//code to print fibonacci numbers using dynamic programming.
//considered 0 based indexing i.e. fib(0) = 0;
//This code can also be read from dp1.cpp of class question.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//TC :- O(N)
//SC :- O(N) (for stack space) + O(N) for storing in dp array.
int fib(int n, vector<int> &dp)
{
    if (n <= 1) {return n;}
    
    if (dp[n] != -1) {return dp[n];}  

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);  //memoization with recursion.
}
void VivekTiwary_1092()
{
    int n; 
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << fib(n, dp);
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