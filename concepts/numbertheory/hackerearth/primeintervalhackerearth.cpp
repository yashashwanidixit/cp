#include<bits/stdc++.h>
using namespace std;


void find_and_print_primes(int l ,int r) {
    vector<int>divisors(r+1); 
    divisors[0] = 1;
    divisors[1] = 1;
    for(int i = 2  ;i * i <= r ;i ++ ) {
        for(int j = i*i ; j<=r ; j+=i) {
            divisors[j] ++;
            continue;
        }
    }
    int cnt = 0;
    for(int i = l ; i<= r ; i++) {
        if(divisors[i] == 0) {
            cout<<i <<" ";
            cnt++; 

        }

    }
    cout<<endl;
    cout<<cnt<<endl;
    cout<<endl;
      
}







signed main() {
    int l = 2;
    int r = 5;
    find_and_print_primes(l,r) ;
    return 0;
}