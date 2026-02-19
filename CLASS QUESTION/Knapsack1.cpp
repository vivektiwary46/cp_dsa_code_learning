// Suppose you are given n objects the ith object has weight Wi. You have to tell whether it
// is possible to achieve the target weight X by taking a subset of objects?
// Let the constraints be   N <= 20 , 𝑊 <= 1𝑒9 𝑋 <= 1𝑒9
// The above problem can be solved using recursion and bitmasking
// The template code for recursion can be seen from the PDF 36
// Here we will implement the solution using bitmasking
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
// Time complexity : O(n * 2^n ) , We have 2^n subsets and we require one loop through
// the array to generate the mask.

// Auxiliary space complexity for both the approaches : We require no extra space for
// solving the problem so O(1).

// NOTE : now if the constaints are such N <= 1𝑒2 , 𝑊𝑖 <= 1𝑒5 , 𝑋 <= 1𝑒5, this way of brute
// forcing will not work as time complexity of (n*2^n) will now won't work, hence we will
// need to use dynamic programming in this case, hence the same problem is solved using
// dp in dp7.cpp

bool is_possible(int num_obj, vector<int> &weights, int reqsum)
{
    for (int mask = 0; mask < (1 << num_obj); mask++)
    { // iterate through all the masks
        int currsum = 0;
        for (int i = 0; i < num_obj; i++)
        {
            if (i & (1 << mask))
            {
                currsum += weights[i]; // add weight if bit is set
            }
        }
        if (currsum == reqsum)
        {
            return 1;
        }
    }
    return 0; // if out of loop none of the subsets have the req sum.
}

void VivekTiwary_1092()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (is_possible(n, a, x)) {cout << "YES\n";}
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

// code if we want to generate all the subsets using recursion and hence see whether required
// sum x is possible or not :-
// Recursion :

// base condition ensures that if after processing all objects if we have obtained
// required sum we return 1;
////else we try both cases 1. where we take object 2. where we don't take the
// object
////if we can make the required sum using any of those we can return 1

//Code :
// bool is_possible (int num_obj, vector<int> & weights, int reqsum, int currsum,
// int index)
// {
// if (index >= num_obj) return reqsum == currsum; // base condition
// bool taken = is_possible (num_obj, weights, reqsum, currsum + weights[index],
// index + 1);
// bool not_taken = is_possible (num_obj, weights, reqsum, currsum, index + 1);
// return taken | not_taken;
// }
