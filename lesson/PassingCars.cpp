// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt = 0; // east
    int ans = 0;
    for(int i=0;i<A.size();i++) {
        if(A[i] == 0) cnt++;
        else ans += cnt;
        if(ans > 1000000000) {
            ans = -1;
            break;
        }
    }
    return ans;
}