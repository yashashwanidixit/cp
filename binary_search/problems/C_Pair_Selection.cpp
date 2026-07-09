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

bool check(vector<pair<ll,ll>>&a,ll k ,ll n,ld mid ) {
    vector<ld>d(n);
    for(ll i = 0; i < n; i ++) {
        d[i] = (ld)a[i+1].first - mid * (ld)a[i+1].second;

    }
    sort(all(d),greater<ld>()) ;
    ld sum = 0;
    for(ll i = 0; i <= k-1 ; i++) {
        sum += d[i] ;
    }
    if(sum >=0) return true;
    else return false;


}


ld binary_search(vector<pair<ll,ll>>&a,ll k ,ll n) {
    
    ld low = 0.0;
    ld high = 1e14;
    while(high- low >= 1e-6) {
        ld mid = (high +low) /2 ;
        if(check(a,k,n,mid)) {
            low = mid;
        }
        else high = mid;
    }
    return low;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll  n ; ll k;
    cin >> n >>k;
    vector<pair<ll, ll>>a(n+1);
    for(ll i = 1 ; i < n+1 ; i++) {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    cout << fixed<<setprecision(10) << binary_search(a,k,n) <<endl;


   

    return 0;
}