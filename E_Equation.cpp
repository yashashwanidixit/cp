#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 2000001;
ll a[MAXN];

#define pb push_back
#define all(x) (x).begin(), (x).end()

void precompute() {
    a[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        a[i] = (i * a[i-1]) % MOD;
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
    return a[n];
}

ll inverse(ll x) {
    return power(x, MOD - 2);
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact(n) * inverse(fact(r)) % MOD * inverse(fact(n-r)) % MOD;
}
bool check(long double mid , long double c ) {
    long double ans = (mid * mid) ;
    ans += sqrt(mid) ;
    if (ans >= c) return true;
    else return false;
}



long double binary_search(long double c) {
    
    long double low = 0.0;
    long double high = sqrt(c);
    while(high - low > 1e-6){
        long double mid = (low +high) / 2;
        if(check(mid,c)){
            
            high = mid;
        }
        else low = mid;
    }
    return low;
}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long double c ;
    cin >> c;
    cout <<fixed<<setprecision(6) << binary_search(c) <<'\n';
    return 0;
}



