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
bool check(long double mid, vector<pair<long double, long double >>&a,ll n) {
    long double low = -1e9 ;
    long double high = 1e9;
    for(ll i = 0 ;i < n ;i ++) {
        long double x = a[i].first;
        long double y = a[i].second;

        low = max(low ,x - mid * y ) ;
        high = min (high , x+ mid*y) ;
        if(low >high) return false;
    }
    return low <= high ;
 }



long double binary_search(vector<pair<long double, long double >>&a,ll n) {
    long double low = 0.0;
    long double high = 1e14;
    while(high - low > 1e-6) {
        long double mid = (low+high) /2;
        if(check(mid,a,n)) {
            high = mid; 
        }
        else low = mid;
    }
    return high; 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ;cin >>n;
    vector<pair<long double, long double >>a(n);
    for(ll i = 0 ;  i < n  ;i ++) {
        cin >>a[i].first;
        cin >>a[i].second;
    }
    cout << fixed << setprecision(10) <<binary_search(a,n)<<endl;


   

    return 0;
}