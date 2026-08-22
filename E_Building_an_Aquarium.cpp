#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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

void solve() {
    ll n ; ll k;
    cin >> n >> k;
    ll blocks = n - k;
    if(blocks == 1) {
        cout << -1 << endl;
        return;
    }
    ll zeroes = ceil(n/2.0) ;
    ll ones = n/2.0;
    string ans(n) ;
 
    for(ll i = 0; i <zeroes; i ++) {
        ans[i] = '0' ;
    }
    for(ll j = zeroes ; j < ones+zeroes; j++) {
        ans[j] = '1'; 


    }
    ll odd = 0;
    for(ll k = ones+zeroes; k < n ; k ++) {
        if(!odd) {
            ans[k] = '0';
            odd=1;
        }
        else {
            ans[k] = '1';
            odd= 0;
        }
    }
    cout << ans << endl;
    
    

    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}