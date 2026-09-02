#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const int MAXN = 2000001;
ll v[MAXN];

#define pb push_back
#define all(x) (x).begin(), (x).end()

void precompute()
{
    v[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        v[i] = (i * v[i - 1]) % MOD;
}

ll power(ll n, ll k)
{
    n = n % MOD;
    ll res = 1;
    while (k)
    {
        if (k % 2)
            res = res * n % MOD;
        n = n * n % MOD;
        k /= 2;
    }
    return res;
}

ll fact(ll n)
{
    return v[n];
}

ll inverse(ll x)
{
    return power(x, MOD - 2);
}

ll nCr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    return fact(n) * inverse(fact(r)) % MOD * inverse(fact(n - r)) % MOD;
}

void solve()
{
    ll n;
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<ll>a(26,-1) , b(26,-1) ;
    for(ll i =0 ; i <n ; i++) {
        ll c = s[i] -'A' ;
        if(a[c]==-1) {
            a[c] = i ;
        }
        b[c] = i;
    }
    ll cnt = 0;
    for(ll i = 0; i <n ;i++) {
        ll c = s[i] -'A' ;
        if(a[c] == i) cnt ++;
        
        if(cnt >k ) {
            cout <<"YES" <<endl;
            return;
        }
        if(b[c] == i) {
            cnt-- ;
        }
    }
    cout <<"NO" <<endl;
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

/*

cout << fixed << setprecision(10) << ans << '\n';

*/