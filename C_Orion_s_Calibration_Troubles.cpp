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
    cin >> n;
    string s;
    cin >> s;
    ll q;
    cin >> q;
     int dp[26][1501] = {0} ;
        for(char c='a' ; c <='z'; c++) {
            for(int m = 1 ; m <=  n ; m++) {
                int l = 0;
                int r =0 ;
                int cnt =0 ;
                while(r<n && l < n) {
                    if(s[r]!=c) cnt ++;
                    while(cnt > m) {
                        dp[c-'a'][m] = max(dp[c-'a'][m], r-l );
                        if(s[l]!=c) cnt --;
                        l++ ;
                        
                    
                    }
                    r++ ;
                    
    
                }
          
                dp[c-'a'][m] = max(dp[c-'a'][m], r-l );
                
            }
        }
    while (q--)
    {
        ll m;
        cin >> m;
        char c;
        cin >> c;
        cout << dp[c-'a'][m] << endl;
       
        
        
       
       
    }
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