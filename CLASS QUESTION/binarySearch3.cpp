//Here we are trying to find sqrt(x) without using sqrt function and with a minimum prescision of eps;
#include<bits/stdc++.h>
using namespace std;
#define int long long
const double eps = 1e-6;
//let x = 2 so mid = 1 and 1^2 < 2 so now l = 1 and r = 2, again mid = 1.5 and 1.5^2 > 2 so now
//l = 1 and r = 1.5 and so on......, until diff between l and r is less than eps.
void VivekTiwary_1092()
{
    double x;
    cin >> x;
    double l = 0;
    double r = x;
    while ((r - l) > eps)
    {
        double mid = l + (r - l) / 2;
        if (mid * mid < x) { l = mid;}
        else {r = mid;}
    }
    cout  << fixed << setprecision(7) <<  l + (r-l) / 2;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}