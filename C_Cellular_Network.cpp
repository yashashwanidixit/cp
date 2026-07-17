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

bool check(ll mid,vector<ll>&a,vector<ll>&v,ll n,ll m) {
    for(auto i: a) {
        ll find1= i+mid;
        auto it = upper_bound(all(v),find1);
        auto it2=lower_bound(all(v),i-mid);
        if(it - it2 <=0) return false;
    
    }
    return true;

}




ll binary_search(vector<ll>&a,vector<ll>&v,ll n,ll m) {
    ll low =0;
    ll high = abs(*max_element(all(a))-*min_element(all(v)));
    ll ans= 0;
    while(low <= high) {
        
        ll mid =( low+high) / 2;
   
        
        if(check(mid,a,v,n,m)) {
              
           
            
            ans= mid;
            high = mid-1;
        }
        else low = mid +1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; ll m;cin >> n >> m;
    vector <ll>a(n);
    vector<ll>v(m);
    for(auto &i:a)cin >> i;
    for(auto &i : v) cin >> i;

    cout << binary_search(a,v,n,m)<<endl;


    return 0;
}