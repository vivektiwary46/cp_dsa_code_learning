//We need to find smallest length of substring of a given string containing all vowels.
//In this we have used both binary search and sliding window, the check function is written with the help of sliding window
//Eg :- aeixoyujlmn , ouput :- 7
//Solved the same question using 2 pointers technique in 2pointer8.cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second 
#define mp make_pair
#define pb push_back

int check(int mid, string &s)
{
    //check function is based on sliding window technique, in which we check window of length mid
    //and we keep sliding the window of length mid.
    int l = 0, r = 0;
    int n = s.size();
    vector<char> b = {'a', 'e', 'i', 'o', 'u'};
    map<char, int> m;
    for (; r < mid; r++)
    {
        m[s[r]]++; //s string mein 0 to mid tak mein(jo first window bhi hai) jo char's hai
    }              //unka freq store kar rahe hai.
    while (r < n)
    {
        int cnt = 0;
        for (auto &i : b)
        {
            cnt += (m[i] > 0); //it increses the value of cnt by 1 if m[i] > 0 holds as it is a boolean condition and will return 1 if it is true.
        }
        if (cnt == 5) {return true;} //means 5 volwels hai, so return true kar die, if ye statement execute nahi hua toh mid size ka window pura string length pe slid karna hoga to find the smallest string which has all the vowels. 
        r++;
        if (r < n) {m[s[r]]++;}
        m[s[l]]--;  //jaise jaise r++ kar rahe hai, peche ka l pe jo char hai uska freq ghata
        l++;        //rahe hai aur next wale r pe jo char hai uska freq badha rahe hai, aur l++ 
    }               //kar rahe hai, jisse window slid ho jaa raha hai, here freq map bahut kam aa raha hai.
    return false;
}
void VivekTiwary_1092()
{
    string s; cin >> s;
    int n = s.size();
    int lo = 5, hi = n, ans = -1; //lo is initialized to 5 as minimum length of string to have all the vowels is 5.
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, s)) {hi = mid - 1; ans = mid;}
        else {lo = mid + 1;}
    }
    cout << ans;
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