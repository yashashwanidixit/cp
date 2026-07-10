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
bool check(vector<ld>&a,ld m , ll n ,ll d,ll &l , ll &r ) {
    //vector<ld >p= a; this cant happen as a is ll 
    vector<ld>p(n+1,0.0) ;
    for(ll i = 1 ; i < n+1 ; i ++) {
        p[i] = p[i-1] + a[i] - m;
    }
   
    vector<ld >q = p;
    
    ld minn=q[0] ;
    for(ll i =1 ; i <n+1  ; i++) {
        if(q[i] < minn) {
            minn = q[i] ;
        }
        q[i] = minn;
    }
    for(ll i = d ; i <n+1 ; i ++) {
        if(p[i] >= q[i-d]) {
            for(ll j= 0 ; j <= i-d;j++) {
                if(p[i] - p[j] >= 0) {
                    l = j + 1;
                    r = i;
                }
            }
        return true;
        }
    }
    return false;
}
pair<ll,ll> binary_search(vector<ld>&a,ll n,ll d) {
    pair<ll,ll>v;
    v.first= 1;
    v.second= n;//when array consists entirely of zeroes it would be an issue
    
    ld low = 0.0 ;
    ld high = 100; 
    
    for(ll i = 0 ; i < 100; i ++) {
        ld mid = (high+low) / 2;
        ll l = -1;ll r= -1;
        
        if(check(a,mid,n,d,l,r)){
            v.first= l;
            v.second = r;
            low = mid;

        }
        else high= mid;
    }
    return v;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ;ll d;
    cin >> n  >> d;
    vector< ld>a(n+1);
    a[0]= 0;
    for(ll i = 1 ; i<n+1; i ++) {
        cin >> a[i] ;

    }
    pair<ll,ll>v;
    v= binary_search(a,n,d);
    cout << v.first << " " << v.second << endl;
    return 0;
}