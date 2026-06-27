#include<bits/stdc++.h>
using namespace std ;



int fact(int n) {
    int ans = 1;
    for(int i = 2  ;i <= n ;i++) {
        ans *= i;
    }
    return ans ;
}

signed main () {
    string s;
    cin >> s;
    int n = s.size() ;
    int nume = fact(n) ;
    unordered_map<char, int>a;
    for(auto ch : s ) {
        a[ch] ++;
    }
    for(const auto [key,value] : a) {
        nume = nume / (fact(value));
    }
    cout << nume << endl;
    sort(s.begin(),s.end()) ;
    do{
        cout << s << endl;
    } while (next_permutation(s.begin() ,s.end()));
    


}