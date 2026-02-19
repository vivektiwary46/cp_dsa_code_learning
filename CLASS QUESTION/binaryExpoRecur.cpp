// in this we are just finding x power n in log n time complexity using recursive method.
#include <bits/stdc++.h>
using namespace std;
//TC : O(log(N))
//Approach : this is a simple divide and conquer solution, solved using recursion
//if we need to find 2 power 8, naive approach is 2*2*...*2 which is 7 multiplication
//but if we know 2 power 4 then 2^8 = 2^4 * 2^4 which is 1 mul.

//The Recursive Step (Dividing)
//The line int x = power(a, b / 2); is the "Divide" part. The function stops trying 
//to solve the big power and asks for the value of the power cut in half.

//Combining (The Logic)
//Once the function gets the "half-power" result ($x$), it combines it based on 
//whether the original exponent b was even or odd: If Even (b% 2 == 0):
//a^b = (a^{b/2}) times (a^{b/2}) Example: 2^4 = 2^2 times 2^2 = 4 times 4 = 16.
//If Odd (b % 2 != 0): a^b = (a^{b/2}) times (a^{b/2}) times a Example: 2^5 = (2^2 times 2^2) times 2 = (4 times 4) times 2 = 32 .
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int x = power(a, b / 2);
    if (b % 2 == 0)
    {
        return x * x;
    }
    else
    {
        return x * x * a;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << power(2, 5);
    return 0;
}