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

bool check(vector<ll>&a,ll n, ll m) {
    ll sum = 0;
    for(auto i : a) {
        if(i > m) return false;
        sum+= m-i;
    }
    return sum >= m;
}

ll binary_search(vector<ll>&a,ll n) {
    ll low = 1;
    ll high = accumulate(all(a),0ll) ;
    ll ans= 0;
    while(low<=high) {
        ll mid =  (low+high) /2;
        if(check(a,n,mid)) {
            ans= mid;
            high = mid-1;
        }
        else low= mid+1;

    }
    return ans;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ;cin >> n;
    vector< ll >a(n) ;
    for(auto & i :a) cin >>i;
    cout <<binary_search(a,n) <<endl;


    return 0;
}