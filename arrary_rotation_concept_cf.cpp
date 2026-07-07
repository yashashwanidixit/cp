/*
problem ----> decidophobia



in leetcode array rotation we had to move in one direction so the array req was 2*n but here we need 3*n as we need to move
in two directions.






*/



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

void solve() {
    ll n, d;
    cin >> n>>d;
    vector<ll>a(3*n) ;
    for(ll i =  0; i < n; i ++) {
        cin >> a[i] ;
    }
    for(ll i = 0 ;i < n; i ++) {
        a[n +i] = a[i] ;
        a[2*n+i] = a[i] ;
    }
    vector<ll >c =a;
    for(ll i = 1 ;i < 3*n ; i++) {
        c[i] +=c[i-1] ;
    }
    ll ans = 0;

    for(ll i = 0 ;i < n; i ++) {
        ll idx = i + n;
     
        ll x = c[idx + d] - c[idx-d-1] - a[idx] ;
        ll r = 2*d * a[i] ;
        
        if( r > x) {
           
            ans += r-x;
            
        }
    }
    cout << ans <<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}