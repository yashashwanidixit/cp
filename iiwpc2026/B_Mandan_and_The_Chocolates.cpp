#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const int MAXN = 2000001;
ll v[MAXN];

#define pb push_back
#define all(x) (x).begin(), (x).end()

void precompute() {
    v[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        v[i] = (i * v[i-1]) % MOD;
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
    return v[n];
}

ll inverse(ll x) {
    return power(x, MOD - 2);
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact(n) * inverse(fact(r)) % MOD * inverse(fact(n-r)) % MOD;
}

void solve() {
    ll n; ll l;
    cin >>  n >> l;
    vector<ll>a(n) ;
    for(auto &i : a)cin >> i;
    vector<ll>pre(n+1) ;
    pre[0] = 0;
    pre[1] = 0;
    ll sum =0 ;
    ll idx = 2 ;
    for(auto i: a) {
        sum += i;
        pre[idx] = (sum%n <(n-(sum%n))) ? sum%n : (n-(sum%n));
        idx++; 
    }
    for(auto i : pre) {
        cout <<i << " "; 
    }
    cout << endl;
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve() ;

    return 0;
}

/*

cout << fixed << setprecision(10) << ans << '\n';

*/