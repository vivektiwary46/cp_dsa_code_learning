// Question : We are given n elements each having a weight and some value / profit. You
// can take some fraction of this weight subsequently you will also get the same fraction
// of value. What is the maximum value we can get if the maximum total weight you can
// take is X?
// Let the constraints be :
// N<= 1𝑒5 , 𝑊𝑖 <= 1𝑒5 , 𝑋 <= 1𝑒5 𝑉𝑖 <= 1𝑒5;

// Approach : Well we can't use dp now because of the large constraints. But, it's easy to
// think of an intuitive way to solve it.
// There is a greedy algo which can be used.
// It is - s𝑜𝑟𝑡 𝑡ℎ𝑒 𝑜𝑏𝑗𝑒𝑐𝑡𝑠 𝑎𝑐𝑐𝑜𝑟𝑑𝑖𝑛𝑔 𝑡𝑜 𝑣𝑎𝑙𝑢𝑒 / 𝑤𝑒𝑖𝑔ℎ𝑡 𝑖𝑛 𝑑𝑒𝑐𝑟𝑒𝑎𝑠𝑖𝑛𝑔 𝑜𝑟𝑑𝑒𝑟. 𝑇ℎ𝑒𝑛 𝑠𝑒𝑙𝑒𝑐𝑡 𝑡ℎ𝑒
// 𝑒𝑙𝑒𝑚𝑒𝑛𝑡𝑠 𝑖𝑛 𝑡ℎ𝑖𝑠 𝑜𝑟𝑑𝑒𝑟.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    //Let the maximum weight you can take is w.
    int n; double w; cin >> n >> w; 
    vector<array<double, 3>> obj(n);
    for (auto &x : obj)
    {
        cin >> x[1] >> x[2];
        x[0] = x[1] / x[2]; // value by weight
    }
    sort(obj.rbegin(), obj.rend());
    double ans = 0; // Maximum value
    double weightUsed = 0; // Current weight used
    for (auto &x : obj)
    {
        if (weightUsed + x[2] <= w) 
        {
            ans += x[1]; // Take the full value of this object
            weightUsed += x[2]; // Add the full weight of this object
        }
        else
        {
            // Take the fraction of the last object
            double remainingWeight = w - weightUsed;
            ans += x[0] * remainingWeight; // Add fractional value
            break;
        }
    }
    cout << fixed << setprecision(6) << ans << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}
