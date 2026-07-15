#include<bits/stdc++.h >
using namespace std ;

bool miller_rabin(ll n, ll a) {
    if (n % a == 0) return n == a;//It says: if a divides n, then n is prime only if n equals a itself.
    
    ll d = n - 1;
    int r = 0;
    while (d % 2 == 0) { d /= 2; r++; }  // factor out 2s
    
    ll x = power(a, d, n);                 // x = a^d mod n
    
    if (x == 1 || x == n - 1) return true; // passed immediately
    
    for (int i = 0; i < r - 1; i++) {
        x = mulmod(x, x, n);               // keep squaring
        if (x == n - 1) return true;        // found -1, passed
    }
    
    return false;                           // never found -1, composite
}


//Miller-Rabin's logic assumes a and n are coprime