// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int lower = -987654321;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    int m = 0;
    int sum = 0;
    for(int i=0;i<n;i++) {
        A[i] = abs(A[i]);
        m = max(A[i], m);
        sum += A[i];
    }
    
    vector<int> cnt(m+1, 0);
    for(int i=0;i<n;i++) {
        cnt[A[i]] += 1;
    }
    
    vector<int> d(sum+1,-1);
    d[0] = 0;
    for(int i=1;i<=m;i++) {
        if(cnt[i] > 0) {
            for(int j=0;j<sum;j++) {
                if(d[j] >= 0) d[j] = cnt[i];
                else if(j >= i && d[j-i] > 0)
                    d[j] = d[j-i] - 1;
            }
        }
    }
    int ans = sum;
    for(int i=0;i<sum/2+1;i++) {
        if(d[i] >= 0)
            ans = min(ans, sum - 2*i);
    }
    return ans;
}