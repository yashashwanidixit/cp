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


 ll check( ll m) {
    ll digits = 1;
    ll len = 9;
    ll start = 1;
    ll ans = 0;
    while(start * 10 <= m) {
        ans+= len * digits;
        start *= 10;
        len *=10;
        digits ++;
        

    }
    ans += (m- start +1) * digits ;
    return ans;


}

ll binary_search(ll k) {
    ll low = 0 ; 
    ll high = 1e18;
    ll num = 1;
    while(low <= high) {
        ll mid = (low +high) / 2;
        if(check(mid)>=k) {
            num = mid;
            high = mid -1;

        }//the opposite is false because we are counting 
        //the number of digits that occur before that number so if it is less than k 
        //we dont know whether including that number makes it equal to k
        else low = mid+1;

    }
    return num ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q;cin >> q;
    while(q--) {
        ll k ;cin>> k; 
        ll num = binary_search(k) ;
        ll digsbefore = check(num-1) ;
        ll indx = k - digsbefore-1 ;
        string s= to_string(num) ;
        cout << s[indx]- '0' <<endl;

        

    }

    return 0;
}