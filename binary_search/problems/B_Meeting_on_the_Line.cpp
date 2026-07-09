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
bool check(long double m,vector<long double>&a, vector <long double>&t,ll n) {
    long double left = 0;
    long double right = 1e8;
    for(ll i = 0 ; i < n ; i++) {
        if(m < t[i]) return false;
        left = max(left,a[i] -m+t[i]);
        right = min(right,a[i]+ m - t[i]);
    }
    return left<=right ;
}




long double binary_search(vector<long double>&a, vector <long double>&t, ll n) {
// we are binary searching on time
     long double  low = 0.0;
     long double high = 2e14;
     while(high-low >= 1e-6) {
        long double  mid =(low+high) /2;
        if(check(mid,a,t,n)) {
            high = mid;
        }
        else low = mid;
     }
     return high ;

}




void solve() {
    ll n ;cin >> n;
    vector<long double >a(n),t(n) ;
    for(auto & i:a) cin >> i;
    for(auto &i :t)cin >> i;
    long double time = binary_search(a,t,n) ;
    long double low = 1e-18;
    long double high = 1e18;
    for(ll i = 0; i < n ; i ++) {
        low = max(low, a[i] - time+t[i]);
        high= min(high,a[i]+ time -t[i]) ;

    }
    cout <<fixed<<setprecision(10) <<(low+high)/2 <<'\n' ;

    
    
    
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t ;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}