#include<bits/stdc++.h>
using namespace std; 
signed main () {
    int t ; cin >> t;
    int n ; int q;
    cin >> n >> q;
    vector< int > a(n) ;
    for( auto & i: a) cin >> i;
    vector<int>pref(n+1) ;
    pref[0] = a[0] ;
    vector<int>suf(n+1) ;
    suf[n-1] = a[n-1] ;
    for(int i = 1 ;i < n ;i ++) {
        pref[i] = __gcd(pref[i-1] , a[i]) ;
        
    }
    for(int i = n-2 ;i >= 0 ;i --) {
        suf[i] = __gcd(suf[i+1] , a[i]) ;
        
    }
    for(int i = 0 ;i < q; i++) {
        int l ; int r;
        cin >> l >> r ;
        int g ;
        if(l == 1 ) g = suf[r] ;
        else if (r == n) {
            g = pref[l-2] ;

        }
        else g = __gcd(pref[l-2] , suf[r]) ;
        cout << g <<endl;
         
    }

}