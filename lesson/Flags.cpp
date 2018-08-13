// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<int> peaks;
    for(int i=1;i<n-1;i++) {
        if(A[i] > A[i-1] && A[i] > A[i+1]) {
            peaks.push_back(i);
        }
    }
    int flags = 0;
    for(int i=peaks.size()-1;i>=0;i--) {
        bool check = true;
        for(int j=1;j<peaks.size();j++) {
            if(peaks[j] - peaks[j-1] < i) {
                check = false;
                break;
            }
        }
        if(check) {
            flags = i;
            break;
        } 
    }
    return flags;
}