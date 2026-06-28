#include <bits/stdc++.h>
using namespace std;

bool check (int mid,int k,vector<int> & a) {
    int cnt = 1 ;
    int sum = 0;
    if(a[0] > mid) return false;
    for(int i = 0 ; i < a.size() ;i ++) {
        sum += a[i] ;
        if( sum > mid) {
            cnt ++ ;
            sum = a[i] ;//DOTN SET SUM = 0 AS A[I] IS INCLUDED AND HAS TO BE USED FOR FURTHUR ITERATIONS
            
        }
    }
    if( cnt > k) return false;
    else return true;
    
    
}




int painter_partition(vector<int> &a ,int k, int s) {
    int ans = 0;
    int low = *max_element(a.begin() , a.end());
    int high = s;
    while(low <= high) {
        int mid = (low+high) / 2;
        if(check(mid,k,a)) {
            ans = mid;
            high = mid-1;
        }
        else low = mid + 1;
    }
    return ans ;
     
}

int main() {
    // Write your code here
    int t;
    cin>>t;
    while(t--){
    int N, k;
    cin >> N >> k;
    vector<int> boards(N);
    int sum = 0;
    for (int i = 0; i < N; i++){
        cin >> boards[i];
        sum += boards[i] ;
    }

    cout << painter_partition(boards, k,sum) << endl;
    }
    return 0;
} 