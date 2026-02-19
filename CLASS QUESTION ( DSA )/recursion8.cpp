//Here we are discussion multiple recursion calls where in a function more than one function
//will be called.
//The code for fibonacci numbers is one such example.
//0 1 1 2 3 5 8 13 are the fibonacci numbers.
//Here f(n) retuns the nth fibonacci numbers, like 0th fibonacci number is 0 and so on.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//this is an example of multiple recursion call as inside of f(n), two functional call
//happens f(n-1) and f(n-2).

//TC :- O(2^n) -> exponential time complexity.
int f(int n)
{
    if (n <= 1) {return n;}
    return f(n-1) + f(n-2);
}
void VivekTiwary_1092()
{
    int n; cin >> n;
    cout << f(n);
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