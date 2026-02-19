//Question Link :- https://www.geeksforgeeks.org/maximum-sum-path-in-a-matrix-from-top-left-to-bottom-right/?ref=rp
//Given a matrix mat[][] of dimensions N * M, the task is to find the path from the 
//top-left cell (0, 0) to the bottom-right cell (N – 1, M – 1) of the given matrix 
//such that sum of the elements in the path is maximum. The only moves allowed from 
//any cell (i, j) of the matrix are (i + 1, j) or (i, j + 1).
//Input: a n*m matrix = 1st row = 3 7 , 2nd row = 9 8.
//Output: 20
//Explanation:
//Path with maximum sum is 3 => 9 => 8 as 20.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
//This is the iterative version of the code.
//Write the reccursive version of the code in dp4.cpp
void VivekTiwary_1092()
{
    int n, m; cin >> n >> m;
    int a[n+1][m+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 1 && j == 1) 
            {
                dp[i][j] = a[i][j];
            } else if (i == 1) 
            {
                dp[i][j] = dp[i][j - 1] + a[i][j]; 
            } else if (j == 1) 
            {
                dp[i][j] = dp[i - 1][j] + a[i][j];
            }
            else 
            {
              dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];  
            }    
            
        }
    }
    cout << dp[n][m];
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
