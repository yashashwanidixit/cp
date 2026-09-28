+#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const int MAXN = 2000001;
ll v[MAXN];
//Each person/item gives you some number of opportunities, 
//and every opportunity from that person has the same cost. 
//sYou need only a limited number of opportunities.
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
    ll n ;ll p ;
    cin >> n >> p;
    vector<ll>a(n),b(n) ;
    for(auto &i:a)cin >> i;
    for(auto &i:b)cin >>i;
    ll ans = p ;
    vector<vector<ll>>c;
    
    for(ll i=0 ; i  < n ; i++) {
        c.push_back({b[i],a[i]}) ;
    }
    sort(all(c)) ;
    
   
    
    ll rem = n-1;
    for(auto x :c) {
        ans += min(rem , x[1])*min(x[0], p) ;
        rem-= min(rem,x[1]) ;
        if(rem ==0) break;

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

/*

cout << fixed << setprecision(10) << ans << '\n';

*/