#include<bits/stdc++.h>
using namespace std;
/*

You always have:

mm
m stars
n−1n-1
n−1 bars (to create nn
n groups)

Total objects = m+n−1m + n - 1
m+n−1
You just need to choose positions for either the stars or bars:
(m+n−1m)=(m+n−1n−1)\binom{m + n - 1}{m} = \binom{m+n-1}{n-1}(mm+n−1​)=(n−1m+n−1​)





*/
#define int long long 

#define x 1000000007
vector< int > a(2000001);


void precompute() {
    a[0] = 1;
    for(int i = 1 ;i <= 2000000; i++) {
        a[i] = (i * a[i-1]) % x;
    }

}
 
int power(int n , int k) {
    n = n % x;
    int res = 1;
    while(k) {
        if(k % 2) {
            res = (res * n) % x;
            k --;
        }
        else {
            n =(n * n) % x;
            k = k/2;

        }
    }
    return res ;
}


signed main () {
    precompute() ;
    int n; int m ;
    cin >> n >> m;
    int ans = a[n+m-1] % x;
    ans = (ans * power(a[m],x-2)) % x;
    ans = (ans * power(a[n-1],x-2))%x;
    
    cout << ans << endl;

}

