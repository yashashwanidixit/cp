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
bool check(ll mid , ll n, int x, int y ) {
    if(mid < min(x,y)) return false;
    ll actual = mid - min(x,y) ;
    ll cnt = 0;
    cnt += actual / x;
    cnt += actual /y ;
    if(cnt >= n-1 ) return true;
    else return false;
}




ll binary_search(ll n, int x ,int y) {
    ll ans = 0;
    ll low = 1;
    ll high = n * max(x,y);
    while( low <= high) {
        ll mid = (low + high) / 2;
        if(check(mid, n, x, y)) {
            ans = mid;
            high = mid -1 ;

        }
        else low = mid + 1;
    }
    return ans;
}





signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ;cin >> n;
    int x ,y ;
    cin >> x >> y;
    cout << binary_search(n,x,y) << endl;

    
    

    return 0;
}