#include<bits/stdc++.h>
using namespace std ;

/* 
normal sieve wont work fine
Small sieve gives → [2, 3, 5, 7, ...]
                           ↓
For query [m, n]:
Create bool array of size (n-m+1)
                           ↓
For each small prime p:
   Find first multiple of p in [m,n]
   Mark all its multiples as composite
                           ↓
Unmarked positions = PRIMES!


*/

#define p 32000

vector<long long int> a (p+1) ;

void sieve () {
    a[0] = 1;
    a[1] = 1;
    for(long long int i = 2; i*i <=p  ;i++) {
        if(a[i] != 0) continue;
        for(long long int j = i*i ;j <= p ;j+=i) {
            a[j] = 1;

        }
    
    }
}

void segmented_sieve(long long int m ,long long  int n ) {
    vector< long long int >primes(n-m+1) ;
    if(m == 1) primes[0] = 1;

    for(long long int i = 2; i <= p; i++) {
        if(a[i] != 0) continue;
        long long int start = (  (m + i - 1) / i) * i; 
        for(long long int j = start ; j <= n ;j+=i) {
            if( j != i) {
                primes[j-m] = 1;

            }
        }
    }
   for(long long int i = 0; i <= n - m; i++) {
    if(primes[i] == 0) {
        cout << m + i << endl;  
    }
}//"I want to round UP when dividing m by i. 
//So I'll add (i-1) to m before dividing, which nudges me just over the edge."


}

signed main () {
    sieve();
    long long int t ; cin >> t;
    while(t--) {
        long long int m ;long long int n ;
        cin >> m >> n;
        segmented_sieve(m,n) ;
        cout << endl;
    }
}