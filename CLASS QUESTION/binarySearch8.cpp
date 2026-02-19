//Question Link :- https://www.spoj.com/problems/PIE/
//This question is kept to understand the importance of the flag variable
//flag isliye use kar rahe hai because aap no of iterations ko limit karna chah rahe hai as, 
//kabhi bhi wo eps jitna precise pahuch nahi payega isliye flag variable use kie, ki bas 100 iteration hi karo, 
//nahi toh wo infinite loop mein fas jayega eps jitna precision pahuchne mein.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define f first
#define s second
#define mp make_pair
#define pb push_back

const ld pi = 2 * acos(0.0);
const ld eps = 1e-6;

bool check(vector<ld> &a, ld m, int f)
{
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += (int)(a[i] / m);
    }
    if (cnt >= f)
    {
        return true;
    }
    return false;
}

void VivekTiwary_1092()
{
    int n, f;
    cin >> n >> f;
    f++;
    vector<ld> a(n);
    ld l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        int x; //x is the radius of the pie.
        cin >> x;
        a[i] = pi * x * x;
        r = max(r, a[i]);
    }
    ld ans = 0;
    int flag = 0;
    while (flag <= 100 && (r - l) > eps)
    {
        ld m = l + (r - l) / 2;
        if (check(a, m, f)) { ans = m; l = m; }
        else { r = m; }
        flag++;
    }
    cout << fixed << setprecision(4) << ans << "\n";
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