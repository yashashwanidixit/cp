#include <bits/stdc++.h>
using namespace std;
 //MAIN IDEA IS THAT THE WE NEED TO FIND AI+BI<=X OR BI<=X-AI;
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

bool check(ll mid,vector<ll>&a,vector<ll>&v,ll n,ll k){
    ll cnt  = 0;
    for(auto i : a) {
        auto it = upper_bound(all(v),(mid-i));
        ll c = distance(v.begin(),it) ;
        cnt+=c;
        if(cnt >= k) return true;


    }
    return cnt >=k ;
}





ll binary_search(vector<ll>&a,vector<ll>&v,ll n ,ll k) {
    
    ll low= 0; 
    ll high = accumulate(all(a),0ll) +  accumulate(all(v),0ll) ;
    ll ans  = 0;

    while(low <=high) {
        ll mid= (low+high)/2;
        if(check(mid,a,v,n,k)){
            ans = mid;
            high = mid-1;//more than k-1


        }
        else low= mid+1;
    }
    return ans;

}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;ll k;
    cin >> n >> k;
    vector<ll >a(n),v(n);
    for(auto &i:a)cin >>i;
    for(auto &i:v)cin >>i;
    sort(all(a));
    sort(all(v));
    cout << binary_search(a,v,n,k)<<endl;

    
   
 
 
    return 0;
}