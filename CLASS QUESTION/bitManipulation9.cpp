//How to convert decimal to binary.
#include<bits/stdc++.h>
using namespace std;
#define int long long
//Explanation of line 11 :-
//'0' is the ASCII value of the character '0' (which is 48 in decimal).
//Adding num % 2 (either 0 or 1) to '0' gives the ASCII value of the character 
//representation of the binary digit. For example:
//If num % 2 is 0, it results in '0' (48 + 0).
//If num % 2 is 1, it results in '1' (48 + 1).
string decToBin(int num) {
   if(num == 0) return "0";
   string ans;
   while(num) 
   {
       ans += (char)('0' + num % 2); //basically typecasting ho raha hai.
       num /= 2;                     // '0' ko concatenate kar  rahe hai with num%2 which 
       //is a integer number so '0' ka ascii value use hua i.e. 48 and phir bahar wala 
       //char typecast karke phir se usko in char convert kar dega.
   }
   reverse(ans.begin(), ans.end());
   return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    cout << decToBin(n);
    return 0;
}