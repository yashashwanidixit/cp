#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 2000001;
ll b[MAXN];

#define pb push_back
#define all(x) (x).begin(), (x).end()

void precompute() {
    b[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        b[i] = (i * b[i-1]) % MOD;
}

ll power(ll n, ll k) {
    n = n % MOD;
    ll res = 1;
    while (k) {
        if (k % 2) res = res * n % MOD;
        n = n * n % MOD;
        k /= 2;
    }
    return res;
}

ll fact(ll n) {
    return b[n];
}

ll inverse(ll x) {
    return power(x, MOD - 2);
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact(n) * inverse(fact(r)) % MOD * inverse(fact(n-r)) % MOD;
}

char math(ll k) {
    ll start = 1;
    ll count = 9;
    ll digit = 1;
    while(k > digit * count) {
        k -= count*digit ;
        start *=10;
        count*=10;
        digit++;

    }
    ll num = start + (k-1) / digit ;
    ll idx = (k-1) % digit; 
    return to_string(num)[idx] ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q;cin >> q;
    while(q--) {
        ll k ;cin>> k; 
        cout << math(k) - '0'<<endl;
    }

    return 0;
}