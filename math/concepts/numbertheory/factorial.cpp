#include<bits/stdc++.h>
using namespace std ;
vector<long long int > a(1000001) ;
/*
(ans * i) % m = (ans % m * i % m) % m
Now at every step in the loop, we already do:
cppans = (ans * i) % m
So ans is always < m after each step, meaning:
ans % m = ans   ✅
*/

long long int fact(long long int n , long long int p) {
    long long int pro = 1;
    for(long long int i = 2 ;i <= n; i ++) {
        pro = (pro * i) % p;
    }
    return pro ;
}

void create_array (long long int p) {
    a[0] = 1;a[1] = 1;
    for(int i = 2 ; i<= 1000000 ;i++) {
        a[i] = fact(i,p ) ;
    }
}

long long int power(long long int n ,long long int k ,long long int p) {
    n = n % p;
    long long int res = 1;
    while(k) {
        if(k % 2) {
            res = ((__int128)res * n) % p;
            k --; 
        }
        else {
            n = ((__int128)n * n) % p;
            k = k/2;
        }
    } 
    return res;   
}
long long int inv_pow(long long int k ,long long int p) {
    return (__int128)power(k,p-2,p);}







signed main () {
    
    long long int q ,p; cin >> q >> p;
    create_array(p);
    while( q-- ) {
        long long int n , k ;
        cin >> n >> k;
        long long int ans = a[n] ;
        long long int x = inv_pow(a[k] ,p);
        long long int y = inv_pow(a[n-k] ,p) ;
        ans = ((__int128)ans * x) %p;
        ans = ((__int128)ans * y) %p;
        cout << ans << endl;
        

    }
}