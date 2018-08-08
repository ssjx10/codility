// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> v(N);
    int max = 0;
    int t_max = 0;
    for(int i=0;i<A.size();i++) {
        if(A[i] <= N) {
            if(v[A[i]-1] < t_max)
                v[A[i]-1] = 1 + t_max;
            else v[A[i]-1] = v[A[i]-1] + 1;
            if(max < v[A[i]-1]) max = v[A[i]-1];
        }
        else if(A[i] == N+1) {
            t_max = max;
        }
            
    }

    for(int i=0;i<v.size();i++) {
        if(v[i] < t_max)
            v[i] = t_max;
    }
    
    return v;
}