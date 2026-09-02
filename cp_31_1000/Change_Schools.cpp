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
    ll n; ll k;
    cin >> n >> k;
    vector<ll>a(n);
    for(auto &i : a)cin >> i;
    map<ll,ll>mp;
    for(auto i :a){
        if(mp.contains(i)) mp[i] ++;
        else mp[i] =1;
    }
    vector<ll>v;
    for(auto &[k,i] : mp){
        v.push_back(i) ;
    }
    sort(all(v)) ;
    
    ll maxx = *max_element(all(v)) ;
    ll sm = maxx-1;
    ll ans = 0;
    for(auto i : v){
        if(i == maxx || i== sm) ans ++;
    }
    cout << ans << endl;
   
    
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve() ;

    return 0;
}