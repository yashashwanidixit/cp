#include <bits/stdc++.h>
using namespace std;
//A VERY IMPORTANT THING TO UNDERSTAND THAT THE FINAL H CAN BE LESS THAN THE MIN
//PRESENT HEIGHT (IF SMTG LIKE - U1= 4 D1= 2 U2=2 D2=19 X = 1)
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

bool check(ll mid , ll x,vector<pair<ll,ll>>&a) {
    ll prev_l = 0;
    ll prev_r = mid ;
    for(ll i = 0 ; i < a.size() ; i++) {
        ll u = a[i].first;
        ll d = a[i].second;

        ll cur_l = max(ll(0),mid-d) ;
        ll cur_r = min(u,mid);
       

        ll new_l = max(cur_l,prev_l-x) ;
        ll new_r = min(cur_r,prev_r+x);
        

        if(new_l> new_r) {
            return false;
        }
        prev_l = new_l;
        prev_r= new_r;
    }
    return true;
}



ll binary_search(vector<pair<ll,ll>>&a,ll x,ll sum ) {
    ll low = 0;
    ll high = sum;
    ll ans = 0;
    while(low <= high) {
        ll mid= (low+high) /2;

      
        if(check(mid,x,a)){
           
            
            ans = mid ;
            low = mid +1;
        }
        else high = mid - 1;
    }
    return ans;
    
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; ll x;
    cin >> n >> x;
    vector<pair<ll,ll>>a(n);
    for(ll i = 0 ; i <n ; i++) {
        cin >> a[i].first;
        cin >>a[i].second;

    }
    ll sum = INT_MAX;
    for(ll i = 0 ; i< a.size() ; i++) {
        sum =min(sum ,a[i].first+a[i].second) ;
    }
    ll h = binary_search(a,x,sum) ;
    
    ll ans = 0;
    for(ll i  = 0 ; i< a.size();i++) {
        ll u = a[i].first;
        ll d = a[i].second;
        ans+=abs(h - (u+d)) ;

    }
    cout << ans <<endl;

    

    return 0;
}