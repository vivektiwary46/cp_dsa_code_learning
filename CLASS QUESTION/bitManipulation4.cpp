//Q.) How to set the ith bit to 1 for the given input number n;	
//eg - 4 is 100, after setting 1st bit (0-based indexing) to 1 , the binary is 110 which is 6.
//For that we need to do this n | (1<<i), where i is the index set ot 1, n is the original number.  
#include<bits/stdc++.h>
using namespace std;
#define int long long

int setIthBitToOne(int n, int i)
{
    int mask = 1 << i;
    n = n |mask;

    return n;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, i;
    cin >> n >> i;

    cout << "The number after setting the " << i << "th bit to 1 is " << setIthBitToOne(n, i) << endl;
    return 0;
}