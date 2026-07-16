#include <bits/stdc++.h>
using namespace std;


/*
meet in the middle concept is used






*/

















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





signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; ll m;
    cin >> n >> m;
    vector<ll >a(n);
    for(auto &i:a ) cin >> i;
    vector<ll>x,y;
    for(ll i = 0; i <n ;i ++) {
        if(i >=(n+1)/2){
            y.push_back(a[i]);
        }
        else x.push_back(a[i]);
    }
    vector<ll>s1,s2;
    for(ll b = 0 ;b< (1<<((n+1)/2) );b++){
        ll sum = 0;
        for(ll i=0 ; i <(n+1)/2;i++){
            if(b&(1<<i)) sum+=x[i];
        }
        s1.push_back(sum%m);
    }
    for(ll b = 0 ;b< (1<<((n)/2) );b++){
        ll sum = 0;
        for(ll i=0 ; i <(n)/2;i++){
            if(b&(1<<i)) sum+=y[i];
        }
        s2.push_back(sum%m);
    }
    //now x <m and y< m since we have done %m
   
    sort(all(s1));
    sort(all(s2));
    ll ans = INT_MIN;
    for(auto i:s1) {
        //x+y<m means find max y <= m-1-i;
        //auto potent= *lower_bound(all(s2),m-1-i);
        //the reason we should use upper_bound and not loweR_bound is coz
        //we want either that value or the smaller value
        auto potent = upper_bound(all(s2),m-1-i);
        if(potent!=s2.begin()){
            ans = max(ans,*prev(potent) + i);
        }
        
        ans= max(ans,(s2.back()+i)%m);
        
    }
    //x+y>m means maximize x+y-m 
    // x+y >m but <2m wrap around so for fixed x choose max value of y
    

    
    cout<<ans<<endl;


    return 0;
}
