// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) { // 최소 부분합은 0
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<int> sub1(n,0);
    vector<int> sub2(n,0);
    for(int i=1;i<n-1;i++) { //start에서의 각 위치에서의 최대 부분합
        sub1[i] = max(0, sub1[i-1] + A[i]);
    }
    for(int i=n-2;i>0;i--) { //end에서의 각 위치에서의 최대 부분합
        sub2[i] = max(0, sub2[i+1] + A[i]);
    }
    
    int ans = 0;
    for(int i=1;i<n-1;i++) { // i -> Y position
        ans = max(ans, sub1[i-1] + sub2[i+1]);
    }
    return ans;
}