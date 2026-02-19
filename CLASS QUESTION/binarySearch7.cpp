// Question Link :- https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
//yaha pe mr function calculate kar raha hai ki max r (mr) kitna ho sakta hai jisme sara
//rectangles accomodate ho jaye, as it is obvious ki 1e18 mein sare ho jayega, but usse kam
//r jisme ho jaye wo nikalna chah rahe hai, as if w = 1 = h, so cnt mein toh 1e18 * 1e18 ho
//jayega if x is 1e18, which can be the maximum r, so cnt overflow kar jayega isliye wo min
//r nikalna chah rahe hai jisme sara n rectangles can be fit, aur phir us r ke liye, l to r 
//pe binary search laga rahe hai.
//matlab r ko 1e18 set na karke wo r nikal liye for a particluar n, jisme sara n rectangles
//can be fit, aur phir wo r ke liye binary search lagaye, isse jab cnt nikalenge toh wo overflow
//nahi karega as r hamesha 1e18 se kam hoga.
bool mr(int w, int h, int n, int x)
{
    //in this function x is the minimum r for which all n rectangles can be fit.
    int cnt = 0;
    int n1 = (x / w);
    int n2 = (x / h);
    cnt += n1 * n2;
    return cnt >= n;
}
void VivekTiwary_1092()
{
    int w, h, n;
    cin >> w >> h >> n;
    int l = 0, r = 1;
    while (mr(w, h, n, r) == false)
    {    
        r = r * 2;
    }
    int ans = 0;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if ( mr(w, h, n, m) ) {ans = m; r = m - 1; }
        else { l = m + 1; }
    }
    cout << ans;
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