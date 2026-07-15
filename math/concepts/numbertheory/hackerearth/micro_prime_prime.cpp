#ifndef brute force

#include<bits/stdc++.h>
using namespace std;
#define N 1000000
vector<int>divisors (N+1) ;
vector<int>maxsuf (N+1); //0 means the number is prime
void sieve() {
	divisors[0] = 1;
	divisors[1] = 1;
	for(int i = 2; i*i <=N; i++) {
		if(divisors[i] != 0)  continue;
		for(int j = i*i ; j<= N; j+=i) {
			divisors[j] = 1;
		}
 	}
 
}
bool is_prime(int n) {
	if(n == 0 || n == 1) return false;
	for(int i =  2; i * i<=n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int prime_prime(int l ,int r) {
	int cnt = 0; 
	for(int i = l ;i <=r; i++) {
		
		if(is_prime(maxsuf[i])) cnt++; 
	}
	return cnt ;
	

}

int main(){
	int t;cin >> t;
	sieve() ;
	maxsuf[0] = 0;
	maxsuf[1] = 0;
	int cnt = 0;
	for(int i = 2 ;i <=N; i++) {
		if(divisors[i] == 0) cnt++;
		maxsuf[i] = cnt ;
	}
	while(t--) {
		int l , r;
		cin >> l >> r;
		int ans = prime_prime(l,r) ;
		cout << ans << endl ;
		

	}
	
}













#endif