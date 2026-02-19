// Question Link :- https://www.hackerrank.com/challenges/balanced-brackets/problem
// This is a standard question which can be asked in the interviews.
// Time Complexity :- O(n)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    string s;
    cin >> s;
    stack<char> st;
    bool balanced = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
            continue;
        }
        if (!st.empty())
        {
            char c = st.top();
            st.pop();
            if ((s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') || (s[i] == ']' && c == '['))
            {
                balanced = true;
            }
            else {balanced = false; break;} 
        }
        else  // ][ this type of test case, when stack is empty and you have discovered an closing bracket
        {
            balanced = false;
            break;
        }

    }
    if (!st.empty()) {balanced = false;}
    if (balanced) {cout << "YES\n";}
    else {cout << "NO\n";}
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}