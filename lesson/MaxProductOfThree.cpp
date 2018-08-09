// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int n = A.size()-1;
    int ans = 0;
    if(A[0]<0 && A[1]<0 && A[n]>0) {
        ans = A[n-2]*A[n-1]*A[n];
        if(ans < A[0]*A[1]*A[n]) ans = A[0]*A[1]*A[n];
    }
    else ans = A[n-2]*A[n-1]*A[n];
    return ans;
}