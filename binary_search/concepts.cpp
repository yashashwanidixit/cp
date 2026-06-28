 /*
When the problem says "find minimum/maximum X such that some condition holds" — binary search on X, and write a check(X) function.


Check Function
In more advanced binary search problems, you are not directly searching for a number in the array. Instead, you're trying to find the minimum or maximum value that satisfies certain conditions.
So instead of checking if arr[mid] == x,

you write a check(mid) function that tells you whether the current mid is a valid solution or not.


 */


#include <bits/stdc++.h>
using namespace std;

bool check(int mid) {
    // return true if mid satisfies the condition
    // return false otherwise
}

int binary_search(int low, int high) {
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = mid;        // mid is valid, try for better answer
            high = mid - 1;   // for minimum: go left
            // low = mid + 1; // for maximum: go right
        } else {
            low = mid + 1;    // not valid, go right
            // high = mid - 1 // for maximum: go left
        }
    }
    return ans;
}

int main() {
    int low = 1, high = 1e9; // define your search space
    cout << binary_search(low, high);
}


/*
USES = >
1. find the min possbile maximum kinda
2. what is the least number of steps
3.divide allocate distribute 
4. think of a range if i guess and answer x caan i check if its valid
5. 






*/