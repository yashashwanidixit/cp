#include<bits/stdc++.h>

using namespace std ;
#define N 7677382783278273 //any large number
//our goal = to do prime factorization 

void primeFact(int n) {
    for(int i = 2;i < n ;i++ ) {
        if(n % i == 0) {
            int cnt = 0;
            while(n % i == 0) {
                cnt++;n = n/i;
            }
            cout<<i<<"^"<<cnt<<endl;
        }
    }
    if( n > 1) cout<<n<<"^" <<1<<endl;
}






signed main () {

}