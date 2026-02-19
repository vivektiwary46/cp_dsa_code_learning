//Q.) How to generate all possible non empty(imp, so just a space is not a subsequences) subsequences of the given string.
//Difference between subsequence and substring should be clear.
//Subsequence -> delete some elements from anywhere in the string and concatenate the remaining.
//Eg abcdefgh -> del -> c,f,h -> abdeg -> this is a subsequence.
//Substring -> delete some elements from the beginning and some from the end.
//Eg abcdefgh -> del -> a,b from begin and g,h from end -> cdef -> this is a substring.
//Logic Used :- Assume that length of string is n.
//Represent any subsequence of this string as a binary number of length n.
//Eg abc -> binary number of length 3
//If binary digit is 1 -> then that char is present in this sequence.
//Else it is deleted.
//eg abc, note n should iterate from 1 to 2^n - 1, so in this case as n = 3, i is from 1 t0 7.
//001, 010, 011, 100, 101, 110, 111
//c,    b ,  bc,  a,   ac,  ab, abc
//

#include<bits/stdc++.h>
using namespace std;
#define int long long
//This technique is also called power set technique.
//TC :- O(2^N * N);
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> seq;
    string s;
    cin >> s;
    int n = s.length();

    for (int i = 1; i < (1<<n); i++) // i is iterating from 1 to (2^n - 1). 
    {
        string temp = ""; 
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))    // if jth bit in (i = 1 to 7) is set.
            {
                temp = temp + s[j]; 
            }
        }

        seq.push_back(temp);

    }

    for (int i = 0; i < seq.size(); i++)
    {
        cout << seq[i] << " " ;
    }

    return 0;
}