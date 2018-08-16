// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <queue>

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
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    while(!q.empty()) {
        int s = q.front().first;
        int val = q.front().second;
        q.pop();
        for(int i=0;i<cnt;i++) {
            if(s+fibo[i] == end) {
                return val+1;
            }
            else if(s+fibo[i] > end) break;
            else if(A[s+fibo[i]] == 1) {
                q.push(make_pair(s+fibo[i], val+1));   
            }
        }
    }
    return -1;
}