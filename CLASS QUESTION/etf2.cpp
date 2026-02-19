// euler's toient function in O(nlog(log(n))) i.e. sieve method
#include <bits/stdc++.h>
using namespace std;
#define long long int

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max = 1000001;
    vector<int> phi(max);

    for (int i = 0; i <= max; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i <= sqrt(max); i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= max; j = j + i)
            {
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << phi[n] << endl;
    }
    return 0;
}