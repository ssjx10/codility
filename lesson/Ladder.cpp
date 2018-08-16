#include <cmath>

int d[50001];

vector<int> solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<int> b(n,0);
    int max = 0;
    for(int i=0;i<n;i++) {
        b[i] = pow(2, B[i]);
        if(max<b[i]) max = b[i];
    }
    d[1] = 1;
    d[2] = 2;
    for(int i=3;i<=n;i++) {
        d[i] = (d[i-1] + d[i-2])%max;
    }
    vector<int> ans;
    for(int i=0;i<n;i++) {
        ans.push_back(d[A[i]]%b[i]);
    }
    return ans;
}