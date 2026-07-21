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
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin >> n;
    vector<ll>a(2*n);
    for(auto &i:a) cin >> i;
    sort(all(a));
    ll cnt =0 ;
    ll maxx= INT_MIN;
    for(ll i = 2*n -1; i>=0 ;i-=2) {
        if(a[i]-a[i-1] > maxx) maxx= a[i]-a[i-1] ;
     
        cnt += a[i] - a[i -1] ;
        

        
    }
    cnt -= maxx;
    cout << cnt << endl;

    return 0;
}