//Q.) How to set the ith bit to 0 for the given input number n;	
//eg - 6 is 110, after setting 1st bit (0-based indexing) to 0 , the binary is 100 which is 4.
//For that we need to do this n & (~(1<<i)), where i is the index set ot 0, n is the original number.  
#include<bits/stdc++.h>
using namespace std;
#define int long long

int setIthBitToZero(int n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;

    return n;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, i;
    cin >> n >> i;

    cout << "The number after setting the " << i << "th bit to 0 is " << setIthBitToZero(n, i) << endl;
    return 0;
}