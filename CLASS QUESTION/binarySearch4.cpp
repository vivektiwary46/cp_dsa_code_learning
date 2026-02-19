//Link :- https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
//This question can be considered as a combination of 2nd and 3rd question of step1, binary search edu section.
//edge case ko handle karne ke liye, lower aur upper function mein pos ka intialization is very important.
//Alternate solution of this question is given binarySearch5.cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

int lower(vector<int>& v, int x) //lower should return first index such that number is greater than equal to x
{                                //ab agar array ke sare numbers x se chote hue toh lower ko array ka size return karna chahiye
    int l = 0; int r = v.size()-1;//as lower me agar sare numbers x se chote hue toh array size return karna is like saying ki array ke numbers se bara hona hoga
    int pos = v.size();           //isse sare edge case handle ho jata hai.
    while (r >= l)                //baki samajh na aye toh dry run karke dekhna koi case ke liye.
    {
        int m = l + (r-l)/2;
        if (v[m] >= x) {pos = m; r = m -1;}
        else {l = m + 1;}
    }
    return pos;
}

int upper(vector<int>& v, int x)
{
    int l = 0; int r = v.size()-1; //upper should return the last index where number is less than or equal to x
    int pos = -1;                  //ab agar array ke sare numbers x se bare hai, to upper -1 return karna chahiye
    while (r >= l)                 //dekh logical hai agar sare numbers x se bare hai toh -1 is like bolna ki array ke numbers se chota jana hoga
    {                              //isse sara edge case handle ho jata hai.
        int m = l + (r-l)/2;
        if (v[m] <= x) {pos = m; l = m + 1 ;}
        else {r = m - 1;}
    }
    return pos;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {cin >> x;}
    sort(v.begin(), v.end());
    int q;
    cin >> q;
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        int a = lower(v, l);
        int b = upper(v, r);
        cout << b - a + 1 << " ";
        
    }
    return 0;
}