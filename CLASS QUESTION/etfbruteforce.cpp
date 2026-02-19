#include <bits/stdc++.h>
using namespace std;
#define int long long
// calculating phi(euler totient function) in naive approach(brute force).
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (__gcd(i, n) == 1)
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}