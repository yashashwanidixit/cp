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
    string s;
    cin >> s;
    ll one = 0 ;
    ll zero =0 ;
    for(auto i : s) {
        if(i == '0' ) zero++;
        else one ++;
    }
    ll zeroes = 0;
    ll ones = 0;
    for(auto i : s) {
        ll x = i - '0' ;
        
        if(x == 0) zeroes++;
        else ones ++ ;
        if(zeroes > one) {
            cout << zeroes << endl;
            return;
        }
        else if(ones > zero) {
            cout << ones << endl;
            return ;
        }
    }
    cout << s.size() - 2*min(one,zero) << endl;
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