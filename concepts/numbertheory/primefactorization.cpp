#include<bits/stdc++.h>

using namespace std ;
#define N 7677382783278273 //any large number
//our goal = to do prime factorization 

void primeFact(int n) {
    for(long long i = 2; i * i <= n; i++) {  // finds all primes ≤ √n
    if(n % i == 0) {
        while(n % i == 0) { cnt++; n /= i; }
        a[i] = cnt;
    }
}
if(n > 1) a[n] = 1;  // the one possible prime > √n
}






signed main () {

}



#include <bits/stdc++.h>
using namespace std;


int count_divisors(int n) {
    int cnt = 0;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0){ 
            cnt++;
            if(i != n/i) cnt++;
        }
    }
return cnt ;
}
    
int main() {
    
    int n ; int q ;
    cin >> n >> q;
    
    while(q--) {
        int t ,k ;
        cin >> t >> k ;
        if(t == 1) {
            int ans = count_divisors(__gcd(n, k)) ;
            cout << ans << endl;
            
        }
        else if(t == 2) {
            if(n % k != 0)  { cout << 0 <<endl;continue ; }
            int ans = count_divisors(n/k);
            cout << ans <<endl; 
            continue;
            
        }
        else {
            if(n % k != 0) {
                cout << count_divisors(n) << endl;
                continue;
            }
            int ans = count_divisors(n) - count_divisors(n/k) ;
            cout << ans <<endl;
            continue ;
        }
        
    }
    
	

}







