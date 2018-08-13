// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
const int min_range = -1000000;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int max_end = min_range;
    int max_slice = min_range;
    for(int i=0;i<A.size();i++) {
        max_end = max(A[i], max_end + A[i]);
        max_slice = max(max_slice, max_end);
    }
    
    return max_slice;
}