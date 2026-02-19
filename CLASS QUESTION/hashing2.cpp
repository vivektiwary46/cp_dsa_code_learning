//yaha string of length n dia hua hai, ham n * 26 ka grid bana rahe hai (26 coloumns from a to z), ham string mein iterate kar rahe hai
//c ka coloumn mein  char c ka counter dalte jaa rahe hai string pe iterate kar ke , if 2nd index pe agar char c mila toh counter ++, similarly 
//pura string pe phir us coloumn ka prefix array le rahe hai, ye kam sare coloumn from a to z ke liye kar rahe hai
//isse kya milega if we are given index from l to r in the string , it will help us to know ki l to r mein kisi bhi cahracter
//(a to z) ka kya freq hai, above computation ke wajah se hamko bas itna hi pata cahlega, kyuki agar l to r mein agar wo char
//hoga toh above computation exactly wahi index pe jake us cahracter ka counter ++ kia hoga.  

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10; 


void VivekTiwary_1092()
{
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> hash_A (n+1, vector<int> (26, 0));
    vector<vector<int>> hash_B (n+1, vector<int> (26, 0));
    for (int i = 0; i <n; i++)
    {
        hash_A[i+1][a[i] - 'a']++;
        hash_B[i+1][b[i] - 'a']++;
        for (int j = 0; j<26; j++)
        {
            hash_A[i+1][j] += hash_A[i][j];
            hash_B[i+1][j] += hash_B[i][j]; 
        }
    }
    
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i=0; i<26; i++)
        {
            int freq1 = hash_A[r][i] - hash_A[l-1][i];
            int freq2 = hash_B[r][i] - hash_B[l-1][i];
            ans += abs(freq1 - freq2); 
        }
        cout << ans / 2 << '\n';
    }
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        VivekTiwary_1092();
    }

    return 0;
}