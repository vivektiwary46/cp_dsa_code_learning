#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int div = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int firstnum = (i);
            int secondnum = (n / i);
            if (firstnum != secondnum)
            {
                div += 2;
            }
            else
            {
                div++;
            }
        }
    }
    if (div == 2)
    {
        cout << n << " is prime"<<endl;
    }
    else
    {
        cout << n << " is not prime"<<endl;
    }
    return 0;
}