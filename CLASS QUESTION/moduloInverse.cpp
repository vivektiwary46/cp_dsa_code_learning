// We want to find (a^-1)%m and we know (a^-1)%m = (a^(m-2))%m.

#include <bits/stdc++.h>
using namespace std;
#define int long long

int modInverse(int a, int m)
{
    // (a^-1)%m = (a^(m-2))%m
    // so i am using binary exponentiation using iteration to find a power m-2.
    m = m-2;
    int x = m+2;
    int result = 1;
    while(m!=0)
    {
        if (m % 2) //means m is odd
        {
            result = ((result % (x)) * (a % (x))) % (x);
            m --;
        }

        else
        {
            a = ((a % (x)) * (a % (x))) % (x);
            m = m / 2;
        }
    }
    
    
    return result;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << modInverse(3,11);
    return 0;
}