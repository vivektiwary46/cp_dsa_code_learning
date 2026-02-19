// Q.) How to calculate the number of setbits(1) in the given number,where n is => 0<=n<=2^63-1
// Setbits is the number of 1's present in the binary representation of the number.

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i < 64; i++)
    {
        if (n & (1LL << i))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}