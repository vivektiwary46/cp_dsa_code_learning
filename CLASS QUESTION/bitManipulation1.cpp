//Q.) You are given an array of N numbers in which all the numbers are repeated twice
//except one number which is present exactly once then find out that number?
//e.g-> {2,3,4,4,2} so Answer=3;
//logic used :- If we use xor of all the numbers present in the array i.e 2^3^4^4^2 = 3


#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];

    }
    int ans = 0;
    for (int i=0; i<n; i++)
    {
        ans = ans ^ arr[i];
    }
    cout << ans << endl;
    return 0;
}