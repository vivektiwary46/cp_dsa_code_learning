//Q.) You have to check whether the given number is odd or even but you are not allowed 
//to use % operator then how do you do that?
//Logic Used :- any number ( binary form ) & with 1 is 1 if that number is odd and 0 if that number is even.
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if ( n & 1 == 1 )
    {
        cout << "The number " << n << " is odd" << endl;
    }

    else 
    {
        cout << "The number " << n << " is even" << endl;
    }
    return 0;
}