// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <set>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<int> fibo(n+2, 0);
    fibo[0] = 1; fibo[1] = 1;
    int cnt = 2;
    for(int i=2;fibo[i-1]+fibo[i-2]<n+2;i++) {
        fibo[i] = fibo[i-1]+fibo[i-2];
        cnt++;
    }
    
    int start = -1;
    int end = n;
    set<int> pos;
    pos.insert(end);
    int ans = 1;
    while(1) {
        set<int> index;
        for(int e:pos) {
            for(int i=0;i<cnt;i++) {
                if(e-fibo[i] == start) {
                    return ans;
                }
                else if(e-fibo[i] < start) break;
                else if(A[e-fibo[i]] == 1) {
                    index.insert(e-fibo[i]);   
                }
            }
        }
        if(index.size() == 0) return -1;
        pos = index;
        ans++;
    }
 
    return -1;
}