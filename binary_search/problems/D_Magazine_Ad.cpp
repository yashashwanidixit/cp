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



bool check(ll m,vector<ll>&a,ll n,ll k) {
    if( m < *max_element(all(a))) return false;
    ll cnt= 1;
    ll sum = 0;
    for(auto i:a) {
        if(cnt > k) return false;
        if(sum + i> m) {
            cnt ++;
            if(cnt > k) return false;
            sum =0;}

        sum +=i ;

    }
    return true;
    
}

ll binary_search(vector<ll>&a,ll n,ll k){
    
    ll low = 0;
    ll high = n;
    ll ans =0 ;

    while(low <= high) {
        ll mid =(low+high) / 2;
   
        if(check(mid,a,n,k)){
           

            
            ans = mid;
            high = mid-1;

        }
         else low = mid+1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k;cin >> k;
    cin.ignore() ;
    string s;//cin skips whitespace
    getline(cin,s);
   

    vector<ll>a;
    ll cnt= 0;
    for(auto c : s) {
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) cnt++;
        else {
     
            
            a.push_back(cnt+1) ;
            cnt =0;
        }
    }
     a.push_back(cnt) ;
  
    ll n= s.size() ;
  
 

    cout << binary_search(a,n,k) <<endl;


    return 0;
}