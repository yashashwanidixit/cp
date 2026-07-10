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

//thought- indexes are always sorted


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; ll q;
    cin >> n >>q;
    vector<ll>a(n) ;
    for(auto & i:a) cin >> i;
    unordered_map<ll,vector<ll>>map;
    for(ll i = 0 ; i < n ; i ++) {
        map[a[i]].push_back(i) ;
    }
    while(q--) {
        ll l,r,x;
        cin >> l >>r >>x;
        vector<ll>&ar = map[x];//use by pointer wherever possible to reduce runtime
        ll left = lower_bound(all(ar),l) - ar.begin();
        ll right = lower_bound(all(ar),r) - ar.begin() ;
        cout << right - left <<endl;
    }
    
    return 0;
}