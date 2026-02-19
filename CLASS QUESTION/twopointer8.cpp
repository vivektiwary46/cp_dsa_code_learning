//We need to find smallest length of substring of a given string containing all vowels.
//In this we are using two pointers approach to solve the problem.
//Eg :- aeixoyujlmn , ouput :- 7
//TC :- O(n);
//Solved the same question using sliding window technique in slidingWindow.cpp.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

bool sat(vector<int> &f)
{
    int cnt = 0;
    for (int i = 1; i <= 5; i++) {cnt += (f[i] > 0);} //i = 1 se start kie hai as 0 index pe sare consonant char ka count hoga.
    return (cnt == 5);
}
void VivekTiwary_1092()
{
    string s; cin >> s; 
    int n = s.size();
    int l = 0, ans = n + 1;
    map<char, int> m;
    m['a'] = 1; m['e'] = 2; m['i'] = 3; m['o'] = 4; m['u'] = 5;
    vector<int> f(6,0);
    for (int r = 0; r < n; r++)
    {
        f[m[s[r]]]++; //m mein value key pair sirf a,e,i,o,u ka hi hai, so sare consonants ka 0 index of f pe plus hoga bas.
        while(l <= r && sat(f)) //jab phela string milega where both condition of while is satified so wo ek sol hoga, aur phir l aur r ko badhate gaye taki usse bhi chota string mil paye.
        {
            ans = min(ans, r-l+1);
            f[m[s[l]]]--; //even if we get one substring where condition of while is satisfied
            l++;          //but still we are increamenting l and r to get an even smaller substring length.
        }
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