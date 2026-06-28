/*
problem = 
sorted binary arrray (containing 0 and 1) 
find the first occurence of 1
search for a[mid] {
if == 1 search within 0 to mid -1 otherwise
search within mid+ 1 to end


}




*/


#include<bits/stdc++.h>

using namespace std;

int binary_search(vector <int> &a, int low ,int high) {
    if(low > high ) return -1;
    int mid = (low+high ) / 2;
    
    if(a[mid] == 1) {
        if(high == low) return mid;
        else return binary_search(a,0,mid-1) ;
    }
    else if ( a[mid] == 0) {
        return binary_search(a, mid+1 , high) ;
    }
}


signed main () {
    vector<int> a = {0,0,0,1,1,1,1,1,1,1} ;
    cout << binary_search(a , 0 , a.size() - 1) ;

}