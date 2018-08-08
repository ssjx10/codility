// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
bool b[100001];

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    for(int i=0;i<A.size();i++) {
        if(A[i]<=100001)
            b[A[i]] = true;   
    }
    int ans = 1;
    for(int i=1;i<A.size()+1;i++) {
        if(b[i] == false) {
            ans = 0;
            break;
        }
    }
    return ans;
}