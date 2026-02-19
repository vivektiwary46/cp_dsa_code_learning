// Here we are finding maxima of unimodal function concave downward...
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

// Example unimodal concave downward function (quadratic function) 
int f(int x) 
{ 
    return -x * x + 10 * x + 20; 
    //yaha integer output hoga, although continous graph hai...
}

//Ternary Search Function
int ternary_search(int lo, int hi)
{
    while (hi - lo >= 3) //(hi - lo) >= 3 is important as for mid1 and mid2 to exist
    //atleast there should be gap of 3 between the hi and lo...
    {
        //The code in the while loop written based on the graph analysis done for
        //concave downward graph, page kept in the file.
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;
        int f1 = f(mid1);
        int f2 = f(mid2);
        if (f1 > f2)
        {
            hi = mid2;
        }
        else if (f1 < f2)
        {
            lo = mid1;
        }
        else
        {
            // Note: this case doesn’t need to be explicitly handled
            lo = mid1;
            hi = mid2;
        }
    }
    int ans = INT_MIN;
    // Iterate from lo to hi, since hi-lo < 3 hogaya hai ab so maximum value toh , lo to hi
    //ke beech hi hoga so we can iterate from lo to hi to get the maximum value...
    for (int i = lo; i <= hi; i++)
    {
        ans = max(ans, f(i));
    }    
    return ans;
}

void VivekTiwary_1092()
{
    int lo, hi;
    cin >> lo >> hi;
    int result = ternary_search(lo, hi);
    cout << result << "\n";
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