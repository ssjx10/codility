// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<int> fibo(n+2, 0);
    fibo[0]  = 0; 
    fibo[1] = 1;
    int cnt = 2;
    for(int i=2;fibo[i-1]+fibo[i-2]<=A.size()+1;i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        cnt++;
    }
    int s = -1;
    int e = n;
    int ans = 0;
    while(s < e) {
        for(int i=cnt-1;i>=0;i--) {
            if(A[s+fibo[i]] == 1 || e == s+fibo[i]) {
                s = s + fibo[i];
                ans++;
                break;
            }
        }
    }
    return ans;
}