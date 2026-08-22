#include<bits/stdc++.h>
using namespace std;

typedef long long ll ;

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ;
    ll p = 2*(2024);
    ll q = 2025*2025;
    ll gcd = __gcd(p,q) ;
    
    p = p /gcd;
    q = q/gcd ;
    cout << p+q << endl;
}