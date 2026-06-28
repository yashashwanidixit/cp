#include <bits/stdc++.h>
using namespace std;
/// catalan number system 
//ck = 2k fact / k+1 fact times k fact;
// 2kck - 2kck-1 = ballot problme formula 
//visualize grid bad paths the reflection of n, n = n+1 ,n-1

/*
How to recognize Catalan number problems
The pattern always involves two opposing choices with a balance constraint:


Out of all (2kk)\binom{2k}{k}
(k2k​) arrangements, exactly 1k+1\frac{1}{k+1}
k+11​ of them are valid. This comes from a technique called the cycle lemma — among all rotations of an invalid sequence, exactly one is valid.


(k2k​)=all possible arrangements
But this includes invalid ones where ) appears before enough (.- constraint


*/

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
    precompute();

    int t;
    cin >> t;
    if (t % 2 != 0) {
    cout << 0 << endl;
    return 0;
}
    ll k = t / 2;
    cout << nCr(2*k, k) * inverse(k + 1) % MOD << endl;



    return 0;
}