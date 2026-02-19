#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b)
{
    int gcd = __gcd(a, b);  //lcm * gcd = a * b;
    return (a / gcd) * b; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << lcm(5, 6);
    return 0;
}