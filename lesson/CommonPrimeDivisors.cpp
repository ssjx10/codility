// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
bool decomposition(int x, int y) {
    int s, b;
    if(x < y) {
        s = x; b = y;
    }
    else {
        s = y; b = x;
    }
    
    if(b%s == 0) {
        int q = b/s;
        if(q > s) return decomposition(q, s);
        else {
            if(s%q == 0) return true;
            else false;
        }
    }
    
    return false;
}

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = 0;
    for(int i=0;i<A.size();i++) {
        if(decomposition(A[i], B[i])) ans++;
    }
    return ans;
}