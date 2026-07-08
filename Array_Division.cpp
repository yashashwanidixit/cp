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
bool check(ll m , vector<ll>&a,ll k, ll n) {
    ll cnt= 1;
    ll s = 0 ;
   
    for( ll i  = 0 ; i< n ; i++) {
        if(s+a[i]>m) {
            s =a[i] ;
            cnt++;
        
            if(cnt > k) return false;

            continue;

        }
        s+=a[i] ;
       
        if(cnt > k) return false;
    }
    return true;

}

ll binary_search(vector<ll>&a,ll n ,ll k,ll sum) {
    ll low= *max_element(all(a));
    ll high = sum;
    ll ans = 0;
    while(low <=high) {
        
        ll mid= (low+high) /2 ;
       
        
        if(check(mid,a,k,n)) {
            
            ans = mid;
            high=  mid -1;

        }
        else low = mid+1;
    }
    return ans;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; ll k;
    cin >> n >> k;
    vector<ll>a(n) ;
    ll sum = 0;
    for(auto & i: a) {
        cin >> i;
        
    }
    for(auto i :a )sum +=i;
    cout << binary_search(a,n,k,sum) <<endl;

    
    


    

    return 0;
}