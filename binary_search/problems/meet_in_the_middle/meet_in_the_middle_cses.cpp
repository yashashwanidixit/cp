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

vector<ll>subset_sum(vector<ll>&a) {
    ll n = a.size() ;
    vector<ll>sum;
    
    for(ll b = 0; b <(1<<n) ;b++) {
         ll s=0;
        vector<ll>subset;
        for(ll i = 0 ; i <n ; i++) {
           
            if(b&(1<<i)) {
                s+=a[i];
                
                subset.push_back(a[i]);}

        }
        sum.push_back(s);
        
     
    }
    return sum;

}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; ll x;
    cin >> n >> x;
    vector<ll>a((n+1)/2),v(n/2);
    for(ll i = 0 ; i <(n+1)/2 ; i++ ) {
        cin >> a[i] ;
    }
    for(ll i = 0 ; i <(n)/2 ; i++ ) {
        cin >> v[i] ;
    }
    
   
    vector<ll>s1=subset_sum(a);
    vector<ll>s2=subset_sum(v);
  

    sort(all(s1));
    //sorting keeps the time complexuty same but 
    //as searching for consecutive /nearer i's the memory is in cache so it 
    //becomes faster!!
    sort(all(s2));
    ll cnt =0;
    for(auto i : s1) {

        auto range= equal_range(all(s2),x-i);
        //equal range outputs the range from lower_bound to upper_bound like 2,2,2,5
       cnt+= range.second- range.first;
    }
    cout << cnt << endl;
    
    


    return 0;
}