//dont use sliding window when the target is not fixed and no explicit condition to be followed
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
// concept used--------- 
#define all(x) (x).begin(), (x).end()

/*
Whenever you see "find the min/max of 
some value over a sliding range that 
moves forward" — whether that's raw
 array values (classic sliding window max) or, 
 like here, prefix sums (to get range sums with
  bounded length) —
 a monotonic deque gives you O(n), because:



whenever u have to take care of indices and the order in which values occur 
think of this patter of deque to store indices in order of the value it stores
also do this question0---- https://leetcode.com/problems/sliding-window-maximum/
*/





signed main() {
    ll n ; ll a; ll b; 
    cin >>  n>> a >> b;
    vector<ll>x(n) ;
    for(auto &i : x)cin >> i;
    
    vector<ll>pre(n+1) ;
    for(ll i =0  ;i <n ;i++) {
        pre[i+1] += pre[i] + x[i];
    }
    deque<ll>dq;
    ll best = LLONG_MIN;
    for(ll i = a; i <=n ; i++) {
        ll j = i-a; 
        if(j >=0) {
            while(!dq.empty() && pre[dq.back()] > pre[j] ) {
                dq.pop_back() ;
            }
            dq.push_back(j) ;
        }
        while(!dq.empty() && dq.front() <i-b) dq.pop_front() ;
        if(j >=0 && !dq.empty()) {
            best = max(best, pre[i]-pre[dq.front()]) ;
        }
    }
    cout << best << endl;
   

}