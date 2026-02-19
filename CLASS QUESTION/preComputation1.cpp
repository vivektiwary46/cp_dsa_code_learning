//Given a number t, number of test cases and in each test case a number n, we need to find 
//the number n modulo M , where M equals 1e9 + 7; 
// 1 <= T <= 1e5  & 1 <= n <= 1e5
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;
const int N = 1e5 + 10;
int fact[N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = fact[1] = 1;
    for (int i = 2; i<=N; i++)
    {
        fact[i] = (fact[i-1] * i) % M;  //precomputed factorials modulo m and stored it in fact
                                        //array , done in O(N);  
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << fact[n] << '\n';  //O(T);
    }
    //Total time complexity = O(T) + O(N) = O(N) as both N and T are of same range.
    //yaha pe agar while loop ke andar calculate kie hote factorial ka array toh 
    //time complexity O(T*N) ho jata jo ek second mein nahi chalta, hence precomputing factorial array
    //is very helpful.
    return 0;
}