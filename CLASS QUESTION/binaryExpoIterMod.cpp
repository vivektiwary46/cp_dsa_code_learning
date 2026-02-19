// We want to find x power n mod m in log(n) time complexity using iterative method.

#include <bits/stdc++.h>
using namespace std;
#define int long long

int power(int x, int n, int m)
{
    int result = 1;
    while (n != 0)
    {
        if (n % 2 == 1) // n%2 means n is odd
        {
            result = ((result % m) * (x % m)) % m;
            n--;
        }
        else
        {
            x = ((x % m) * (x % m)) % m;
            n = n / 2;
        }
    }
    return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << power(3, 9, 11);
    // WRITE CODE HERE.
    return 0;
}