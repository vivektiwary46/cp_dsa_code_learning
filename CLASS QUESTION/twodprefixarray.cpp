//Given a 2d array of size N*N, and there are t test cases and for each test case we are given 
//a, b, c, d and we need to print the sum represented by square as point (a,b) as top left point 
//and (c,d) as bottom right point;
//Make a grid and then try to evaluate, else can use this link https://www.youtube.com/watch?v=nZe7P674xZo
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4;
int arr[N][N]; //when an array is globally declared all the values in it are intialized to zero.
int pf[N][N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) //here we did 1 based indexing as for 0th index all values will 
                                 //will automatically be zero as arr is globally declared.
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = 0;
        sum += pf[c][d] - pf[c][b-1] - pf[a-1][d] + pf[a-1][b-1];
        cout << sum << '\n';
        
    }
    
    return 0;
}