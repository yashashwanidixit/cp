#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll ;

struct Node {
    char type ;
    long long val ;
    char op ;
    ll left ; ll right ;
};
ll n;

vector<Node> t;

long long eval(ll cur) {
    if(t[cur].type == 'V') return t[cur].val;
    ll l = eval(t[cur].left);
    ll r = eval(t[cur].right) ;
    char o = t[cur].op ;
    if(o == '+') return l+r;
    else if(o == '-') return l-r;
    else if(o == '*') return l*r;
    else return l/r;
     
    
    
}


int main() {
    
    cin >> n;
    t.resize(n+1) ;
    for(ll i = 1 ; i <=n ;i ++) {
        char c; 
        cin >> c;
        t[i].type = c;
        if(c == 'V') {
            cin >> t[i].val;
        }
        else if(c=='O') {
            cin >> t[i].op >> t[i].left >> t[i].right ;
        }
        
    }
    ll ans = eval(1) ;
    cout << ans << endl;
    return 0;
}
