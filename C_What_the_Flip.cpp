#include<bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<long long int> a(1000001);

    long long int s = 1;
    long long int b = 1; // 'b' represents 'T'
    long long int tt = 0;
    long long int MOD = 1000000007;

    // Base case
    a[1] = 2;

    for(int i = 2; i <= 1000000; i++) {
     
        long long int next_s = b;
        long long int next_b = (s + b - tt) % MOD;
        long long int next_tt = (b - tt) % MOD;


        if (next_b < 0) next_b += MOD;
        if (next_tt < 0) next_tt += MOD;

 
        s = next_s;
        b = next_b;
        tt = next_tt;
        
        a[i] = (s + b) % MOD;
    }
    
    while(t--) {
        int k;
        cin >> k;
        cout << a[k] << "\n";
    }
    
    return 0;
}