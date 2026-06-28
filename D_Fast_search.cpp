#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 2000001;
ll a[MAXN];

#define pb push_back
#define all(x) (x).begin(), (x).end()

void precompute() {
    a[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        a[i] = (i * a[i-1]) % MOD;
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
    return a[n];
}

ll inverse(ll x) {
    return power(x, MOD - 2);
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact(n) * inverse(fact(r)) % MOD * inverse(fact(n-r)) % MOD;
}

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ;cin >> n ;
    vector<ll > a(n) ;
    for(auto & i : a) cin >> i;
    sort(all(a) ) ;
    ll k; cin >> k;
    while(k--) {
        ll l;cin >> l;
        ll r ; cin >> r;
        auto it1 = lower_bound(all(a) , l) ;
        auto it2 = upper_bound(all(a) , r) ;
        cout << distance(it1,it2) << " ";
        

    }
    cout << '\n' ;
    

    return 0;
}