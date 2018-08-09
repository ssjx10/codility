// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> st;
    for(int i=0;i<S.size();i++) {
        if(S[i] == '(')
            st.push(S[i]);
        else if(S[i] == ')') {
            if(st.top() == '(')
                st.pop();
            else st.push(S[i]);
        }
        else if(S[i] == '[')
            st.push(S[i]);
        else if(S[i] == ']') {
            if(st.top() == '[')
                st.pop();
            else st.push(S[i]);
        }
        else if(S[i] == '{')
            st.push(S[i]);
        else if(S[i] == '}') {
            if(st.top() == '{')
                st.pop();
            else st.push(S[i]);
        }
    }
    int ans = 0;
    if(st.size() == 0) ans=1;
    return ans;
}