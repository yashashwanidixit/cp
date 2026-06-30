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
bool check (double mid , vector<ll>&a, ll k) {
    ll pieces = 0;
    for(auto len : a) {
        pieces += (ll) (len / mid) ;
        if(pieces >= k) return true;
    }
    return false;

}
double binary_search(vector<ll> & a,ll n , ll k ){
    double low = 0.0;
    double high = *max_element(all(a));
    double ans = 0;
    for(int i = 0; i< 100 ;i ++) {//low <= high wont work as then smtms low will get stuck to mid
        double mid = (low + high) /2;
        if(check(mid,a,k)) {
            ans = mid;
            low = mid;
        }
        else high = mid;
    }
    return ans ;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ;ll k;
    cin >> n >> k;
    vector<ll>a(n) ;
    for(auto & i : a) cin >> i;
    
    
    cout << fixed << setprecision(10) << binary_search(a, n, k) << '\n';
    return 0;
}



//ONLY 1 MISTAKE SETTING PRECISION HERE!!!

/*
Problem saysUse setprecisionerror ≤ 10^-66, 7, 8, or 9

*/