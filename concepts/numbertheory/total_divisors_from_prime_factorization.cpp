#include<bits/stdc++.h>
using namespace std; 
//important concept used ==
/*
N = A^P1 * B^P2 * C^P3
THEN NUMBER OF DIVISORS OF N IS (P1+1)(P2+1)(P3+1)

*/
#define m 1000000007








signed main () {
    int n ; cin >> n ;
    int q ;int p;
    cin >> q >> p; 
    long long ans = (p+1 ) % m;
    n--;

    while(n-- ) { 

        int x ; int y;
        cin >> x >> y;
        ans = (ans * (y+1)) % m;

    }
    cout << ans <<endl;


}