//In this we are two sorted array and we need to merge both of them to a single array and that array should
//also be sorted, for this we will use the fact that both of the arrays were previously sorted.
//Link to question :- https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
//We need to do this in O(n+m), where n and m are the size of the given sorted arrays a and b.
#include<bits/stdc++.h>
using namespace std;
#define int long long

void VivekTiwary_1092()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x : a) { cin >> x;}

    vector<int> b(m);
    for (auto &x : b) { cin >> x;}

    vector<int> c;
    int i= 0; int j = 0;
    while (i<n && j<m)
    {
        if (a[i] <= b[j])
        {
            c.push_back(a[i]);
            i++; 
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }
    while (i<n) {c.push_back(a[i]); i++;} //after the above while loop is finished there might be some elements
    while (j<m) {c.push_back(b[j]); j++;} //still left in a or b to be pushed in c as the left ones would be greater than 
                                          //all the elements in a or b after a certain index.
    for (auto &x : c) {cout << x << " ";}
    
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