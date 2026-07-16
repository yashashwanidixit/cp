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
    ll n;cin>> n;
    vector<ll>a(n);
    for(auto &i:a)cin >> i;
    vector<ll>v;
    for(auto i:a) {
        if(v.empty() || i!= v.back()) v.push_back(i);
    }
    ll cnt= v.size() ;
    ll ans =power(2,n-cnt);
    

    if(count(all(v),-1) ==0) {
        cout<<ans<<endl;
        return;
    }
    ll c =0;
    for(ll i =0 ; i < cnt-1; i++) {
        if(v[i+1]-v[i]==1)c++;
    }

  
    ans = ans *(c+1) % MOD;//THE MOD WAS THE PROBLEM
    cout<<ans<<endl;


    
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