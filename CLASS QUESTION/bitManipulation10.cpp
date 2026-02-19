//Given 2 equations on a & b. Given values of n & m. Find values of a & b that satisfy it:
// [ Linkedin coding round 2020 ]
// a + b = m
// a ^ b = n
//1 <= a, b, n, m <=109 and a <= b
//Question Link :- https://codeism.contest.codeforces.com/group/qXv2tukHZE/contest/309847/problem/A
//Logic for the problem :-
//a + b = a^b + ((a&b) << 1) -> Remember this form of addition.
//(a + b) - ( a^b) =  ((a&b) * 2) 
//a & b = floor ( ((a + b) - ( a^b)) / 2 )
//Let k = a & b = floor ( (m- n) / 2 )
//now we have the value of a&b which is k and the value of a ^ b which is n, so we need to
//iterate through all the bits of n and k and the value of a and b for which the function FindAandB is written.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

pair<long long, long long> findAandB(long long k, long long n) {
    long long a = 0, b = 0;
    for (int i = 0; i < 64; ++i) { // Assuming 64-bit integers
        long long bitAND = (k >> i) & 1; // i-th bit of m 
        long long bitXOR = (n >> i) & 1; // i-th bit of n 

        if (bitAND && bitXOR) {
            // Contradiction: AND=1 and XOR=1 can't happen
            return {-1, -1};
        } else if (bitAND) {
            // AND = 1, so both a and b must have this bit set
            a |= (1LL << i);
            b |= (1LL << i);
        } else if (bitXOR) {
            // XOR = 1 and AND = 0, so one of a or b has this bit set
            // Set one arbitrarily; a gets the bit here, b does not
            a |= (1LL << i);
        }
    }

    // Verify the results
    if ((a & b) == k && (a ^ b) == n) {
        return {a, b};
    } else {
        return {-1, -1};
    }
}

void VivekTiwary_1092()
{
    int m, n; cin >> m >> n;
    int k = floor((m-n)/2);
    pair<long long, long long> result = findAandB(k, n);
    if (result.first == -1) 
    {
        cout << "-1\n";
    } 
    else 
    {
        cout << result.second << " " << result.first << "\n";
    }

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