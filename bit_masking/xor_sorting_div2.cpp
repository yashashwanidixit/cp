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

bool check(ll mid , vector<ll>&a,ll n) {
    ll i= 0 ;ll j = i + (1ll <<(mid+1));
    if(j > n) return true;
    j = min(j,n) ;
    ll prevmax = *max_element(a.begin() + i, a.begin() +j) ;
    ll prevmin = *min_element(a.begin() +i ,a.begin() +j);

    i = j ; j = j + (1ll <<(mid+1));
    j = min(j ,n) ;
    while(i < n) {
        ll minn = *min_element(a.begin() + i,a.begin() + j);
        ll maxx = *max_element(a.begin() + i, a.begin() + j) ;
        if(minn < prevmax) return false;
        else if( maxx < prevmin)  return false;
        prevmax= maxx;
        prevmin = minn;
        i =j;
        j = j +(1ll <<(mid+1));
        j= min(j,n);



    }
    return true;
}

ll binary_search(vector<ll>&a,ll n ) {
    ll low = 0;
    ll high = ceil(log2(n)) ;
    ll ans =0 ;
    while(low <= high) {
        ll mid = (low+high) / 2;
        if(check(mid, a, n)) {
          
    
            ans = mid;
            high = mid-1;
        }
        else low = mid +1;
    }
    return ans;
}

void solve() {
    ll n ; ll q;
    cin >> n >> q;
    vector<ll >a (n) ;
    for(auto & i:a )cin >> i;
    vector<ll>b=a;
    sort(all(b)) ;
    if(a==b) {
        cout << 0 << endl;
        return;
    }
    cout << power(2,binary_search(a,n)) << endl;
    
     

   
}
/**
 if we are saying that k lenght is guessed then lgk2 is the highest set bit so 
 then we will just see if all blocks "agree"
ok so since we need to like decrease the lenght to something smaller lenghts and what i care is the maximum power odf 2 i can generate  <= k
 thats why we are taking the highest set bit
*/
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}