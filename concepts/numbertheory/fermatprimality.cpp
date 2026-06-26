#include<bits/stdc++.h>
#include <random>
#include >chrono>
using namespace std; 

/*
fermats primaliy test : 
for several random values of a:
    if a^(p-1) % p != 1:
        return "COMPOSITE"  ← 100% certain

return "PROBABLY PRIME"     ← not 100% certain!
*/

#ifndef fermatsprimalitytest
// Fast modular exponentiation: (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while(exp > 0) {
        if(exp % 2 == 1)        // if exponent is odd
            result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

bool fermat_primality(long long n, int iterations = 5) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i = 0; i < iterations; i++) {
        // pick random a between 2 and n-2
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long a = uniform_int_distribution<long long>(2, n-2)(rng);

        if(power(a, n-1, n) != 1)
            return false;  // definitely composite
    }
    return true;  // probably prime
}












#endif