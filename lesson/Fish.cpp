#include <stack>

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    stack<pair<int, int>> s;
    for(int i=0;i<A.size();i++) {
        if(B[i] == 1) {
            s.push(make_pair(A[i], B[i]));
        }
        else if(B[i] == 0) {
            if(s.size() !=0) {
                while(s.size() != 0 && s.top().second == 1 && A[i] > s.top().first) {
                    s.pop();
                }
                if(s.size()==0 || s.top().second == 0) s.push(make_pair(A[i], B[i]));
            } else s.push(make_pair(A[i], B[i]));
        }
    }
    int ans = s.size();
    return ans;
}