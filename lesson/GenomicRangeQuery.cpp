// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
struct dna {
  int a, c, g, t;  
  dna() : a(0),c(0),g(0),t(0) {}
};

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<dna> v(S.size());
    if(S[0] == 'A') v[0].a = 1;
    else if(S[0] == 'C') v[0].c = 1;
    else if(S[0] == 'G') v[0].g = 1;
    else if(S[0] == 'T') v[0].t = 1;
    for(int i=1;i<S.size();i++) {
        struct dna factor;
        if(S[i] == 'A') factor.a = 1;
        else if(S[i] == 'C') factor.c = 1;
        else if(S[i] == 'G') factor.g = 1;
        else if(S[i] == 'T') factor.t = 1;
        
        v[i].a = v[i-1].a + factor.a;
        v[i].c = v[i-1].c + factor.c;
        v[i].g = v[i-1].g + factor.g;
        v[i].t = v[i-1].t + factor.t;
    }
    
    vector<int> ans;
    for(int i=0;i<P.size();i++) {
        int s = P[i];
        int e = Q[i];
        if(s != 0) {
            if(v[e].a - v[s-1].a > 0) ans.push_back(1);
            else if(v[e].c - v[s-1].c > 0) ans.push_back(2);
            else if(v[e].g - v[s-1].g > 0) ans.push_back(3);
            else if(v[e].t - v[s-1].t > 0) ans.push_back(4);
        } else {
            if(v[e].a > 0) ans.push_back(1);
            else if(v[e].c > 0) ans.push_back(2);
            else if(v[e].g > 0) ans.push_back(3);
            else if(v[e].t > 0) ans.push_back(4);
        }
    }
    
    return ans;
}