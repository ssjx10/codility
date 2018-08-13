// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<int> cnt(2*n+1, 0);
    for(int i=0;i<n;i++) {
        cnt[A[i]]++;
    }
    vector<int> ans;
    for(int i=0;i<n;i++) {
        int divisor = 0;
        for(int j=1;j*j<=A[i];j++) {
            if(A[i]%j == 0) {
                divisor += cnt[j];
                if(A[i]/j != j) divisor += cnt[A[i]/j];
            }
        }
        ans.push_back(n-divisor);   
    }
    return ans;
}