// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<bool> v(2000001);
    for(int i=0;i<n;i++) {
        v[A[i]+1000000] = true;
    }
    int ans =0;
    for(int i=0;i<v.size();i++) {
        if(v[i] == true) ans++;
    }
    return ans;
}