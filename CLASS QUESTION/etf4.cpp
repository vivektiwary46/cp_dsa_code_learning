// finding summation of gcd(i,N) in q*O(sqrt(n)) , where number N is input.
// we are telling that we will calculate it in q*O(sqrt(n)) so getCount Function must be calculated in O(1) timecomplexity and this is where Euler's toitent function helps us.
// actually getcount is the number of times a divisor of n comes out as output after calculating gcd of any number from 1 to n with n .
// and that getcount is actually equal to phi[n/d].
// time complexity is actully O(nlog(log(n))) + q*O(sqrt(n)).


#include <bits/stdc++.h>
using namespace std;
#define int long long

int getCount(int d, int n)
{
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

    return phi[n / d];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        int result = 0;
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                int d1 = i;
                int d2 = n / i;

                result = result + d1 * getCount(d1, n);

                if (d1 != d2)
                {
                    result = result + d2 * getCount(d2, n);
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}