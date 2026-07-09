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

bool check(vector<ll>&a,vector<ll>&t,ld m, ll n) {
    ld l = 0 ;
    ld h = 1e14;
    for(ll i = 0 ; i < n ; i ++) {
        ld l_n = a[i] - t[i]*m;
        ld r_n = a[i] + t[i]*m;
        l = max(l,l_n);
        h = min(h,r_n) ;
        if(l > h) return false;
    }
    return l<=h;
}


ld binary_search(vector<ll>&a,vector<ll>&t,ll n) {
    ld low = 0;
    ld high = 1e14;
    while(high- low > 1e-6) {
        ld mid = (high+low) /2 ;
        if (check(a,t,mid,n)) {
            high = mid;
        }
        else low = mid;
    }
    return high; 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>> n;
    vector<ll>a(n),t(n);
    for(auto & i:a )cin>>i;
    for(auto & i:t )cin>>i;
    cout << fixed <<setprecision(10) << binary_search(a,t,n) <<endl;


    return 0;
}