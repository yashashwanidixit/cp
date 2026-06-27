#include<bits/stdc++.h>

using namespace std;
vector<int>arr(1000001,-1) ;
//goal == for all int in arr we want to store the smallest prime factor of that number


void sieve () {
    int max = 1000000 ;
    arr[1] = 1;
    for(int i = 2 ; i <= max ;i ++) {//iterate as the prime numbers more than root n have to be marked by themselves
        if(arr[i] == -1) {
            for(int j = i; j <= max ; j++0) {
                if(arr[j] == -1 ) {
                    arr[j] = i;
                }
                
            }


        }

        
    }

}

//final optimized solution:

#include<bits/stdc++.h>
using namespace std;
#define N 1000000
vector<int>divisors (N+1) ;//0 means the number is prime
vector<int> p(N+1) ;



void sieve() {
	divisors[0] = 1;
	divisors[1] = 1;
	for(int i = 2; i*i <= N; i++) {
		if(divisors[i] != 0) continue;
		for(int j = i*i ; j <=N ; j+=i) {
			divisors [j] = 1;
		}

		
	}

}



int main(){
	sieve();
	int prime_cnt = 0 ; int pp_count = 0;
	p[0] = 0; p[1] = 0 ;
	for(int i = 2; i<= N ;i++ ) {
		if(divisors[i] == 0) prime_cnt++ ;
		if(divisors[prime_cnt] == 0) pp_count++ ;
		p[i] =  pp_count;
	}
	int t;cin >> t;
	while(t--) {
		int l , r;
		cin >> l >> r;
		int ans = p[r] - p[l-1] ;
		cout << ans << endl ;
		

	}
	
}
