//We want to find x power n modulo m in log(n) time complexity using recursive method.

#include<bits/stdc++.h>
using namespace std;
#define int long long

int power(int a, int b, int m)
{
    if (b == 0)
    {
        return 1;
    }
    int x = power(a, b / 2 , m);
    if (b % 2 == 0)
    {
        return ((x % m) * (x % m)) % m;
    }
    else
    {
        return ((x % m) * (x % m) * (a % m)) % m;
    }
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << power(2, 5, 2);
    return 0;
}