/*
approach = total possible moves = m -1 + n-1
paths choosing from them with duplicates 
(m+n-2) ! / (n-1) ! (m-1) ! =
cut (m-1) ! from top and bottom

*/

#ifndef overflow method
class Solution {
public:
    __int128 fact(long long int n) {
        __int128 ans = 1;
        for(long long int i = 2; i <= n ;i ++) {
            ans =  ans * i;
        }
        return ans ;
    }
    int uniquePaths(long long int m,long long int n) {
        __int128 nume = fact(n + m -2) ;
        __int128 denom = (__int128)fact (n-1) * fact (m-1) ;
        return (int)nume / denom ;

        
    }
};





#endif


#ifndef better solution

class Solution {
public:
    
    int uniquePaths(long long int m,long long int n) {
        __int128 ans = 1 ;
        __int128 r = n - 1;
        __int128 total = m + n -2 ;
        for(long long int i = 0 ;i < r ;i ++ ) {
            ans = ans * (total - i)/ (i+1);

        }
        return (int)ans ;
      

        
    }
};

#endif


