// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int ans = 0;
    for(int i=A.size()-1;i>=2;i--) {
        if((long long)A[i] < (long long)A[i-1] + A[i-2]) ans = 1;
    }
    return ans;
}