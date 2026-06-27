#include <bits/stdc++.h>
using namespace std;


//PRIMALITY CHECK
#ifdef first
int cnt_divisors(int n){
    int div=0;
    for(int i=1;i*i<n;i++){
        if(n%i==0){
            div++;
            if(i!=n/i) div++;

        }
    }
    return div;
}

int main(){
    for(int i=0;i<10;i++){
        cout<<cnt_divisors(i)<<" ";
    }
    cout<<endl;
    return;
    

}
#endif
/*
TIME COMPLEXOTY=NROOTN
INSTEAD OF ITERATING THRU DIVISORS LETS ITERATE THRU THE MULTIPLES<N
WE WILL MAINTAIN A VECTOR TO STORE THE DIVISORS
OPTIMIZED SOLTUION= (n+n/2+n/3+n/4....)< nlogn replace first term with n next 2 terms with n/2 next 
4 terms with n/4...==nlogn'
sieve of eratosthemes =find the number of prime numbers uptil n
REPLACING 2*I WITH I*I IS AN OPTIMIZATION ALL THE MULTIPLES OF I LESS THAN I*i WOULD BE MARKED BY SOME OTHER SMALLER PRIME NUMBER




*/

#ifdef count divisors 

int main(){
    vector<int>div(13);

    for(int i=1;i<=12;i++){
        for(int j=i ;j<=12;j+=i){ //as we have to mark the exact number of divisors we have to iterate through all the i's 
            div[j]++;
        }
    
    }
    for(int i=1;i<=12;i++){
        cout<<div[i]<<endl;

    }
}



//sieve of eratothemes time complexity=o(nlog(log(n)))


int main(){
    int n=100;
    vector<int>primes(n+1);
    //0 means that the number is prime
    primes[1]=1 //1 is not prime
    for(int i=1;i*i<=n;i++){
        //if the number is already marked composite skip it
        if(prime[i]==1) continue;
        for(int j=i*i;j<=n;j+=i){//IMP DONT INCLUDE I ITSELF BECAUSE IT IS PRIME  //we just have to mark it and not count the divisors
            prime[j]=1;
        }
    } 
    int cnt=0;
    for(auto i:primes){
        if (!primes) cnt++;
        
    }
    cout<<cnt<<endl;

}



#endif

//to check primality 
#ifdef third
int main(){
    int n;
    int flag=false
    for(int i=2;i*i<=n;i++){
        
        if(n%i==0){
            cout<<"no"<<endl;
            flag=true;

        }
    }
    if(!flag) cout<<"yes"<<endl;
}



#endif
//======================================================================================================================

//GCD 
/*
COPRIME NUMBERS=GCD(A,B)=1
1.F=GCD(A,B)=GCD(A,B-A)=GCD(A,B%A) EUCLIDEAN ALGORITHM TIME COMPLEXITY O(LOG(MAX(A,B)))
STOP WHEN ONE OF THESE BECOMES ZERO
2.

*/
#ifdef first
int gcd(int a,int b){
    //assuming that b=>a
    if(a==0) return b;
    //the same with b
    return gcd(b%a,a);

}



#endif

//============================================================================================

//MODULO ARITHMETIC
/*
1.THEY ARE ASKING WHETHER ANS%NUMBER IS EVEN OR ODD 
2.(A+b)%M=(A%m+B%M)%M
3.(A*B)%M=((A%M)*(B%m))%M
4.(A-B)%M=((A%m)-(B%M)+M)%m
5.(A^B)%M==========================
to calculate a to the power of b = >
--- if b=0,1
---b even ,(a^b/2)whole squre
------b odd , a*((a^(b-1/2)whole square)
6.for division:
multiplicative inverse of t= an integer x such that(t*x)%m=1
so (6/3) mod m is same as (6*2)mod m as 3 is the inverse of 2 mod m if m ==5 a s(2*3) % m =1 (modular multiplicative inverse  
for gurantee gcd(2,m)=1
==b ^(m-2) whole %M 
logm complexity
here t = 3 and little fermats theorem = inverse exists only if gcd(t,m ) = 1 and m is prime in that case inverse of 3=3 ^(m−2 )mod m t = 3
the actual fermats theorem : 
a^(p-1) ≡ 1 (mod p)        if p is prime


Where 2−12^{-1}
2−1 is the modular inverse of 2, i.e., a number x such that:


(2×x)mod  m=1(2 \times x) \mod m = 1(2×x)modm=1




*/
#ifndef little fermats theorem for calculating mudular inverse of t

#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long m){
    if(b == 0) return 1;
    long long half = power(a, b/2, m);
    half = (half * half) % m;
    if(b % 2 == 0) return half;
    else return (a * half) % m;
}

long long modInverse(long long t, long long m){
    return power(t, m-2, m);     // t^(m-2) % m
}

int main(){
    long long m = 1e9 + 7;       // prime mod
    long long t = 2;

    cout << modInverse(t, m) << endl;  
    // inverse of 2 mod (1e9+7)

    // Verify
    cout << (t * modInverse(t, m)) % m << endl;  
    // should print 1
}


#endif


#ifndef extended euclidean theorem for when little fermats doesn twwork


#include <bits/stdc++.h>
using namespace std;

// returns {gcd, x, y} such that a*x + b*y = gcd
tuple<long long, long long, long long> extGCD(long long a, long long b){
    if(b == 0)
        return {a, 1, 0};       // base case: gcd=a, x=1, y=0
    
    auto [g, x, y] = extGCD(b, a % b);
    return {g, y, x - (a/b)*y};
}

long long modInverse(long long t, long long m){
    auto [g, x, y] = extGCD(t, m);
    
    if(g != 1){
        cout << "Inverse doesn't exist!" << endl;  // gcd != 1
        return -1;
    }
    
    return (x % m + m) % m;    // ensure positive
}

int main(){
    long long t = 3, m = 7;
    cout << modInverse(t, m) << endl;  // 5

    // verify
    cout << (3 * modInverse(3, 7)) % 7 << endl;  // 1 ✅
}





///Think about all possible values of ax + by for any 
///integers x, y. The smallest positive value in that set is always exactly gcd(a, b)



#endif









//recursive code for 5 logb time complexity =BINARY EXPONENTIATION
#ifdef second
int pow(int a,int b,int m){
    if(b==0) return 1;
    if(b%2==0 ) {
        int t=pow(a,b/2 ,m)
        return (1ll* t*t)%m//MULTIPY WITH 1 LONG LONG TO PREVENT OVERFLOW
    }
    else {
        int t=pow(a,(b-1)/2,m)
        t=(11l*t*t)%m;
        return ((1ll*a*t)%m);
        
    }
}



//for 6
int a,b,m;
a=a%m;
int inv_b=pow(b,m-2,m);//fermats little theorem to find multiplicative inverse 
int ans=a*inv_b %m;

#endif

//===============================================================


#ifndef binary exponentiation other method


/*5=101 2^5​=4+1=22+20
So:


a5=a4+1=a4×a1a^5 = a^{4+1} = a^4 \times a^1a5=a4+1=a4×a1




*/

int power(int n, int t) {
    int res = 1;
    while(n) {
    if(n % 2) {
        res *= a;
        n--; 
    }
    else {
        a *= a;
        n =/2;
    }
}
    return res;
}



#endif









