//Given two integers a and b, return the sum of the two integers without using the operators + and -.
//Solution link :- https://www.youtube.com/watch?v=N3dtzMKJMn8
//Actually jab tak carry zero na ho jaye tab tak a and b ka xor le rahe hai, aur b ko carry
//carry ke equal dal de rahe hai, take a = 5 and b = 1 and dry run.
//Time Complexity = O(maximumbitsof(a,b)) or if integer is given O(32);
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

int sum(int a, int b)
{
    int carry = b, sum = a^b;
    while(carry != 0)
    {
        sum = a^b;
        carry = (a&b)<<1;
        a = sum;
        b = carry;
    }
    return sum;
}
void VivekTiwary_1092()
{
    int a, b; cin >> a >> b;
    cout << sum(a, b);
    //a simple basic solutin to this problem is using the increment operator.
    //for(int i = 1; i <= b; i++) {a++;} cout << a; 
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