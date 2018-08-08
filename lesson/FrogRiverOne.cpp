// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <cstring>

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int pos[X+1];
    memset(pos, -1, sizeof(pos));
    for(int i=0;i<A.size();i++) {
        if(A[i] <= X && pos[A[i]] == -1)
            pos[A[i]] = i;
    }
    int ans=0;
    for(int i=1;i<sizeof(pos)/sizeof(pos[0]);i++) {
        if(pos[i] == -1) {
            ans = -1;
            break;
        } else {
            if(ans < pos[i]) ans = pos[i];
        }
            
    }
    return ans;
    
}