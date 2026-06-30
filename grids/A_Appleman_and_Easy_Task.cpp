#include <bits/stdc++.h>
using namespace std;

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
    //GENERAL TEMPLATE FOR GRID PROBLEMS
    int n;
    cin >> n;
    vector<vector<char>>grid(n) ;
    for(int i =0 ;i <n ;i ++) {
        string s;
        cin >> s;
        for(char c : s) {
            grid[i].push_back(c) ;
        }
    }
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    bool is =true;
    for(int i = 0 ;i < n; i++){
        if(!is) break;
        for(int j = 0; j <n ; j++) {
            if(!is) break;
            int cnt = 0;
            for(int d  =0 ;d < 4; d++) {
                int ni = i + dx[d] ;
                int nj = j + dy[d] ;
                if(ni >= 0 && ni< n && nj >= 0 && nj < n) {
                    if(grid[ni][nj] == 'o') cnt ++;
                }

            }
            if(cnt % 2 != 0){
                is = false;
                break;
            }
        }
        
        
    }
    if(is) {
        cout << "YES" <<endl;
        
    }
    else {
        cout << "NO" <<endl;
        
    }

    

   

    return 0;
}