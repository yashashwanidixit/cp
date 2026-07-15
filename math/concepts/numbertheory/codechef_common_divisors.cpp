//count of common divisors of (n, k)  =  count of divisors of gcd(n, k)


#ifndef brute_force 

#include <bits/stdc++.h>
using namespace std;
vector<int>divisors;
void arr(int n) {
    
    for(int i = 1 ;i * i <= n ;i ++) {
        if(n % i == 0 ) {divisors.push_back(i) ;
        if( i != n/i) divisors.push_back(n/i) ;}
    }
    
}
    




int main() {
    
    int n ; int q ;
    cin >> n >> q;
    arr(n) ;
    while(q--) {
        int t ,k ;
        cin >> t >> k ;
        if(t == 1) {
            int cnt = 0;
            for(auto i : divisors) {
                if( k % i == 0) cnt ++; 
                
            }
            cout << cnt << endl;
            continue;
            
        }
        else if( t == 2) {
            int cnt = 0;
            for(auto i : divisors) {
                if(i % k == 0) cnt++;
                
            }
            cout << cnt <<endl;
            continue;
        }
        else  {
            int cnt = 0;
            for(auto i : divisors) {
                if( i % k != 0) cnt++ ;  
            }
            cout << cnt <<endl;
            continue;
         }
    }
    
	

}





#endif


