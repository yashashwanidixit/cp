#include<bits/stdc++.h>
using namespace std ;

#ifndef iterative

int binary_search(vector<int> & a,int target) {
    int low = 0 ;
    int ans ;
    int high = a.size() - 1;
    while(low <= high) {
        int mid = (low+high) / 2;
        if(a[mid] == target) {
            ans = mid;
            break;
        }
        else if(a[mid] > target) {
            high = mid -1 ;

        }
        else {
            low = mid + 1;
        }
    }
    return ans ;
}

#endif


#ifndef recursive

int binary_search(vector<int>&a, int low ,int high,int target) {
    if(low > high) return -1;//element not found
    int mid = (low + high) /2 ;
    if(a[mid] == target) return mid;
    else if( a[mid] > target) {
        return binary_search(a,low, mid-1 ,target) ;
    }
    else {
        return binary_search(a,mid+1,high,target ) ;
    }
}









#endif