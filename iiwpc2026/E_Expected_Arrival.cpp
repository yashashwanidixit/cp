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
ll make_it(ll n)
{
    ll ans = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
    if (n > 1)
        ans = ans / n * (n - 1);

    return ans;
}
bool is_prime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    ll ans = 1;
    ll m = n;
    for (ll i = 2; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            ll cur = 1;
            ll cnt = 0;
            while (m % i == 0)
            {

                m = m / i;

                cnt++;
            }
            

            for (ll j = 1; j <= cnt; j++)
            {
                
                cur = (cur + (power(i, j) *  (power(i,j) - power(i,j-1))% MOD) % MOD) % MOD;
            }

            ans = ans % MOD;
            ans = (ans * cur) % MOD;
        }
    }
    ll p = m%MOD;
    if (p> 1)
    {
        
        ll cur= (1+ (p*((p-1) %MOD) %MOD))%MOD;
        ans =(ans * (cur%MOD) )%MOD ;
    }

    ll den = inverse(n);
    cout << (ans * den) % MOD << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

/*

cout << fixed << setprecision(10) << ans << '\n';

*/