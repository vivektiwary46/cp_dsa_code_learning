// finding summation of gcd(i,N) using brute force approach , where number N is input.
// time complexity would be q*O(nlog(n)) if there are q queries.
// __gcd has log(n) time complexity.
// in etf4 we have computed the same in q*O(sqrt(n)).

#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while(q--)
    {

    int n;
    cin >> n;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = result + __gcd(i,n);
    }
    cout << result << endl;

    }
    return 0;
}