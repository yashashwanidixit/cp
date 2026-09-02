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

void solve() {
    ll s;
    ll q;
    cin >> s >> q;
    vector<ll>div ;
    for(ll i =1 ; i *i <=s ;i++) {
        if(s%i == 0) {div.push_back(i) ;
        if(i!=s/i) div.push_back(s/i) ;}
    }
    sort(all(div)) ;
    vector<ll>pre(div.size() +1) ;
    pre[0] = 0;
    ll prev = 0; 
    for(ll i = 0 ; i <div.size() ;i++) {
        ll add = (div[i] - prev) * (s/div[i]) ;
        pre[i+1] = pre[i] + add ;
        prev = div[i] ;
    }
   


    while(q--) {
        ll x ; ll y;
        cin >> x >> y; 
        ll x_up = lower_bound(all(div) , x) - div.begin() ;
        
        if(x_up != div.size()  && y <= s/div[x_up]) {
            cout << x*y << endl;
            continue;
        }
        ll ans ;
        if(x_up !=div.size()) {
            ans = pre[x_up+1] ;

            ans -= (div[x_up] - x)*(s/div[x_up]) ;
          

        }
        else {
            ans = pre.back() ;
        }
       
        ll y_up= lower_bound(all(div) , y) - div.begin() ;
        if(y_up != div.size()) {
            ll lad = pre.back()- pre[y_up+1] ;
            ans -= lad ;
            ans -= (div[y_up] - y) * (s/div[y_up]) ;

        }
        cout << ans << endl;
        

    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
problem-https://codeforces.com/contest/2257/problem/D