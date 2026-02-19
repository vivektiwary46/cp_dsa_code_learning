//Q.) How to swap two numbers using the XOR operator.
//Logic Used :- We know (x^y)^x = y and (x^y)^y = x
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    cin >> x >> y;
    cout << "x before swapping is " << x << endl;
    cout << "y before swapping is " << y << endl;
    x = x^y;
    y = x^y;
    x = x^y;
    cout << "x after swapping is " << x << endl;
    cout << "y after swapping is " << y << endl;
    return 0;
}