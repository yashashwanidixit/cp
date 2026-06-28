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


ll binary_search(vector<ll > &a , ll target) {
    ll ans = 0;
    ll low = 0 ;
    ll high = a.size() - 1;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(a[mid] >= target) {
            ans = mid + 1;
            high = mid -1 ;

        }
        else low = mid + 1;

    }
    return ans ;
}





signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; ll k ;
    cin >> n >>  k;
    vector<ll >a(n) ;
    for(auto &i :a) cin >> i ;
    
    

    while (k--) {
        ll x; cin >> x;
        if(a[n-1] < x ) {
            cout << n + 1 << endl;
            continue ;
        }
        cout << binary_search(a,x) << '\n' ;
    }

    return 0;
}