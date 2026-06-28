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

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute() ;

    int t;
    cin >> t;

    string s ;cin >> s;

    ll o = 0 ;ll c = 0;
    bool invalid = false ;
    for(auto ch : s) {
        if(ch == '(') o++;
        else c++;
        if(c > o) {invalid= true ; break;}
    }
   



    if (invalid || t % 2 != 0) {
    cout << 0 << endl;
    return 0;
}
   t= t/2;
    
    
    



 
cout << (nCr(2*t - o-c, t-o) - nCr(2*t - o-c, t-1-o) + MOD) % MOD<< endl;
//This is because MOD "resets" large numbers independently — a bigger number can wrap around to a smaller residue than a smaller number.


    return 0;
}