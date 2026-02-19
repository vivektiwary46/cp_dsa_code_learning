//isme backtracking ka use kie hai, that is print(i-1) wala statement phele likhe hai, usse 
//jab tak base condition met na ho jaye tab tak function recursively apne app ko call kar raha hai,
//jab base condition met ho jaa raha hai tab function backtrack kar raha to the parent function,
//aur piche se cout << i << endl; wala line execute kar raha hai har bar, jiski wajah se pehle 1 print ho
//ja raha hai and so on.
#include<bits/stdc++.h>
using namespace std;
#define int long long

void print(int i)
{
    if (i < 1)
    {
        return ;
    }

    print(i-1);
    cout << i << " "; 
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    print (n);

    return 0;
}