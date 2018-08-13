// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int value;
    int size = 0;
    int n = A.size();
    for(int i=0;i<n;i++) {
        if(size == 0) {
            size++;
            value = A[i];
        }
        else {
            if(value != A[i])
                size--;
            else size++;
        }
    }
    int cand = -1;
    if(size > 0) cand = value;
    int leader = -1;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(A[i] == cand) cnt++;
    }
    if(cnt > n/2) leader = cand;
    int ans = 0;
    int c_cnt = 0;
    if(size >0 && cnt > n/2) {
        for(int i=0;i<n;i++) {
            if(A[i] == leader) c_cnt++;
            if(c_cnt > (i+1)/2 && (cnt-c_cnt) > (n-i-1)/2)
                ans++;
        }
    }
    
    return ans;
}