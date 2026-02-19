// Given array a of N integers . Given Q queries and in each query given a number x, print the
// count of that number in array.
// 1 <= N <= 1e5;
// 1 <= a[i] <= 1e7;
// 1 <= Q <= 1e5;
// can use this link :- https://www.youtube.com/watch?v=efET3lxYCkM&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=18&t=2s
//Hashing :- It is used to store freq of elements in an array, which helps in efficient calculations 
//Link :- https://www.youtube.com/watch?v=zwlCeWUGlE0&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=23&t=1024s
//Above link is for a question including both hash array and prefix sum, 2d hash array is created must watch.
//Link for codeforces question using above youtube video concept : - https://codeforces.com/contest/1996/problem/C
//For its solution see hashing2.cpp file.
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 10;
int hashArray[N]; // isse sare elemet 0 intialized ho jayenge. aur hash variable mat use karna as it is a standard variable.

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hashArray[arr[i]]++;   //n max N ho sakta hai so O(N).
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;  //O(q)
        cout << hashArray[x] << '\n'; // O(1) mein cal hoga as hash array already calculate kar dia hai.
    }
    return 0;
    // Time complexity : O(N) + O(q) = O(N) as N = q, hence time complexity kam kar die.
    // nahi toh agar while loop ke andar bar bar x ka freq cal karte in arr so time complexity
    // O(q*N) ho jata.
}