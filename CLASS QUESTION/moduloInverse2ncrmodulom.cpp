//We need to find ncr modulo m 
#include<bits/stdc++.h>
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
    int max = 2e5 + 1;
    vector<int> fac(max);
    fac[0] = 1;
    int m = 1e9 + 7;
    for (int i = 1; i<max; i++)
    {
        fac[i] = (fac[i-1] * i) % m;
    }

    // Finding ncr % m

    int n, r;
    cin >> n >> r;
    int x = fac[n];
    int y = fac[r];
    int z = fac[n-r];

    int ans = ((x % m) * (modInverse(y, m)) * (modInverse(z, m))) % m;
    cout << ans;
    
    return 0;
}
// modInverse(y,m) mein y =  (r!%m) hai phir bhi code will work kyuki usse koi dikkat nahi hai
// as we need (y^-1 % m) = (y^(m-2))%m = (y*y*y*y*y......m-2 times)%m =  ((r%m)*(r%m)....m-2times)%m
// hence we are able to compute it.