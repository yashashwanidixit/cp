#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
//concept used -------
vector<ll> make_it(string s)
{
    ll n = s.size();
    vector<ll> a(n);
    vector<ll> ans(26);
    for (auto &i : ans)
    {
        i = -1;
    }

    for (ll i = 0; i < n; i++)
    {
        ll cur = s[i] - 'a';
        if (ans[cur] == -1)
        {
            ans[cur] = i;
        }
        a[i] = ans[cur];
    }
    return a;
}

void solve()
{
    ll n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<ll> a(n), b(n);

    a = make_it(s1);
    b = make_it(s2);

    ll m;
    cin >> m;
    while (m--)
    {
        string s;
        cin >> s;
        vector<ll> c = make_it(s);
        if (c != a && c != b)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}

signed main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}