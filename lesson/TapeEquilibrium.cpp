// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum1 = A[0];
    int sum2 = 0;
    for(int i=1;i<A.size();i++) {
        sum2 += A[i];
    }
    int ans = abs(sum1 - sum2);
    if(A.size()>2) {
        for(int i=1;i<A.size();i++) {
            sum1 += A[i];
            sum2 -= A[i];
            int diff = abs(sum1 - sum2);
            if(ans > diff)
                ans = diff;
        }
    }
    return ans;
}