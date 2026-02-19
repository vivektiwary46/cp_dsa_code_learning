//How to convert binary to decimal
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

int binToDec(const string &str) 
{
   int ans = 0;
   for(int i=0; i<str.size(); i++) 
   {
       ans *= 2;
       ans += (str[i] - '0');
   }
   return ans;
}   
/*
lets say the binary is 100001100 so while convert it to decimal we are doing the following:-
1 -> 10 -> 100 -> 1000 -> 10000 -> 100001 -> 1000010 -> 1000011
multipying by 2 is actually left shift by 1 place and then if str[i] == '1' then we also
add 1 as (str[i] - '0') will give 1 if str[i] == '1'.
*/
void VivekTiwary_1092()
{
    string s; cin >> s;
    cout << binToDec(s);
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