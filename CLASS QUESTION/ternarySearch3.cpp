// Here we are finding maxima of unimodal function concave downward...
//but here we are doing it for a decimal search i.e. for a continous graph...
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

// Example of unimodal concave downward function (quadratic function) 
double f(double x) 
{ 
    return -x * x + 10 * x + 20; 
}

//NOTE:
// Instead of the criterion hi - lo > eps,we can select a constant number of
// iterations as a stopping criterion. The number of iterations should be
// chosen to ensure the required accuracy.Typically, in most programming
// challenges the error limit is 1e-6 and thus 200-300 iterations are sufficient.
// Also, the number of iterations doesn't depend on the values of lo and hi ,so
// the number of iterations corresponds to the required relative error

//Ternary Search Function
int ternary_search(double lo, double hi)
{
    double eps = 1e-6;
    while (hi - lo > eps) 
    {
        //The code in the while loop written based on the graph analysis done for
        //concave downward graph, page kept in the file.
        double mid1 = lo + (hi - lo) / 3;
        double mid2 = hi - (hi - lo) / 3;
        double f1 = f(mid1);
        double f2 = f(mid2);
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
    return f(lo); //yaha f(hi) bhi return kar sakte the as when eps ka accuracy mil gaya
    //hai toh f(lo) ya f(hi) return karo doesn't matter.
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