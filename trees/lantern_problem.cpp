#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long int n;
vector<vector<int>>t;
long long ans =0 ;


long long dfs(int cu , int par) {
    long long s = 1;
    for(int c : t[cu]) {
        if(c == par) continue;
        long long fin = dfs(c,cu ) ;
        ans += fin * (n-fin) ;
        s += fin ;
        
    }
    return s ;
}




int main() {
    
    cin >> n ;
    t.resize(n+1) ;
    
    for(int i = 0 ; i < n-1; i++) {
        int u; int v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u) ;
    }
    dfs(1,0) ;
    cout << ans << endl;
    
    
    return 0;
}
