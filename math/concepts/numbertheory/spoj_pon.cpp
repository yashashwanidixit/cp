#include<bits/stdc++.h>
using namespace std;
#include<random>
#include<chrono>

long long int power(long long int n ,long long int k, long long int p) {
    long long int res = 1;
    n = n % p ;
    while(k) {
        if( k % 2) {
            res = ((__int128)res * n) %p;
            k --;
        }
        else {
            n = ((__int128)n * n) % p;
            k = k/2;

        }
    }
    return res;


}

bool is_prime(long long int n,int it ) {
    if(n < 2) return false;
    if( n == 2) return true;
    if( n % 2 == 0 ) return false;

    for(long long int i = 1 ;i <= it; i++) {
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        long long a = uniform_int_distribution<long long>(2, n-2)(rng);
        if(power(a, n-1 ,n) != 1) return false;
    }
    return true ;

}


signed main () {
    long long int t ;
    cin >> t;
    while(t--) {
        long long int n ; cin >> n ;
        if(is_prime(n,5)) {
            cout << "YES"<< endl;
            continue ;
        }
        cout << "NO" << endl;
    }
}

