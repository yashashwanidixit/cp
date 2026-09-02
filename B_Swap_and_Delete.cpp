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
    string s;
    cin >> s;
    ll zeroes = 0;
    ll ones =0 ;
    for(auto i :s) {
        if(s=='1') ones++;
        else zeroes++;
    }
    if(ones==zeroes) {
        cout << 0 << endl;
        return;
    }
    ll c1 =0;
    ll c2 =0 ;
    for(ll i = 0 ; i <s.length() ; i++) {
        if(s[i] == '0' ) c1++;
        else if(s[i] =='1') c2 ++;
        if(i == ceil(s.length()/2.0)) {
            if(c1 > )
        }
    }

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

/*

cout << fixed << setprecision(10) << ans << '\n';

*/