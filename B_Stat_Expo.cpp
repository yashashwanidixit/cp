#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2000001;
const ll MOD = 1000000007;
ll b[MAXN];
void precompute() {
    b[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        b[i] = (i * b[i-1]) % MOD;
}

ll fact(ll n) {
    return b[n];
}
ll power(ll n, ll k) {
    ll res =1;
    while(k) {
        if(k%2)  res = res*n ;
        n = n*n ;
        k /= 2;

    }
    return res; 
}
ll inverse(ll x) {
    return power(x, MOD - 2);
}
long long fun(int n, int m) {
    if(m==0) return 1;
    
    if(n < 2*m) return 0;
    else return fun(n-1,m) + fun(n,m-1) ;
}
ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact(n) * inverse(fact(r)) % MOD * inverse(fact(n-r)) % MOD;
}

 


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ;
    long long ans = fun(8,4) ;

    cout << 10 << endl;
}
