//We are checking whether ith bit in the given binary form of the number n is 0 or 1.
#include<bits/stdc++.h>
using namespace std;
#define int long long

bool checkIthBit(int n, int i)
{
    int mask = 1 << i; //ye 1 ko i times left shift karega, if i = 3, then 1 << 3 equals 001000, note 0 based indexing hota hai yaha bhi
    int res = n & mask; //take an example and check, note follow 0 based indexing, isse result ya toh 0 ayega ya 1.

    return (res !=0);  //agar res = 1 hua toh return 1, yani true ho jayega, aur res = 0, toh return 0 yani false, bool toh true ya false hi return karta hai na.

}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i;
    cin >> n >> i;
    if (checkIthBit(n,  i))
    {
        cout << "The " << i << " bit is 1" << endl;
    }
    else 
    {
        cout << "The " << i << " bit is 0" << endl;
    }
    return 0;
}