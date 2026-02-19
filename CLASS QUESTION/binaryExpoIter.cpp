// We want to find x power n in log(n) time complexity using iterative method.
// After seeing this code see for x power n mod m using recursion.
// Note :- Binary Exponentiation Usnig Iteration is more faster than Recursion. 
#include <bits/stdc++.h>
using namespace std;
#define int long long

//This process if done using bit manipulation.
int power(int x, int n)
{
    int result = 1;
    while (n != 0)
    {
        if (n & 1) // n&1 is true means n is odd.
        {
            result = result * x;
            n--;
            //here if n is odd means to get final ans we need to multiply one x to res
            //if x = 2, n = 5 then final ans = 2 * 2^5 and then we did n-- so that
            //n becomes even and we keep squaring it to get final output.
        }

        else
        {
            x = x * x;
            n = n >> 1;
        }
    }
    return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << power(2,5);
    return 0;
}