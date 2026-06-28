#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
typedef long long ll;


vector<int>v(1000001) ;



void precompute () {
    v[0] = 1;
    for (ll i = 1; i <= 1000000; i++)
        v[i] = v[i-1] * i % m;  
}

ll power(ll n , ll k ) {
    n = n % m;
    ll res = 1;
    while(k) {
        if(k % 2) {
            res = (res * n) % m;
            k --;
        }
        else {
            n = (n * n) % m;
            k = k /2;

        }
    }
    return res ;
}

signed main () {
    ll t ;
    cin >> t;
    precompute() ;
    while(t--) {
        ll a ;ll b;
        cin >> a >> b;
        ll ans = v[a] ;
        ans = ( ans * power(v[b], m-2)) % m;
        ans = ( ans * power(v[a-b], m-2)) % m;
        cout << ans << endl;

    }
}