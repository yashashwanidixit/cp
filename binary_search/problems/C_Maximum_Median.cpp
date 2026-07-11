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

bool check(vector<ll>&a,ll m , ll k,ll n) {
    ll cost= 0;
    ll i = n-1;
    while(i >= n/2) {
        if(a[i] > m) {
            i--;continue;
        }
        cost += m - a[i] ;
        if(cost > k) return false;
        i--;



    }
    return true;

}



//notice that this thing would fail for n even 
//for more check leetcode median of 2 sorted arrays

ll binary_search(vector<ll>&a,ll n , ll k) {
    ll low = *min_element(all(a));
    ll high = *max_element(all(a)) +k ;
    ll ans = 0;
    while(low <=high) {
        ll mid = (low+high) /2 ;
        
        if(check(a,mid,k,n)) {
          
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; ll k ;
    cin >> n >> k;
    vector<ll>a(n) ;
    for(auto & i:a) cin >> i;
    sort(all(a)) ;
    cout <<binary_search(a,n,k)<<endl;


    


    return 0;
}