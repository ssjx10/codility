// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<bool> peaks(n, false);
    int size = 0; // max blocks
    for(int i=1;i<n-1;i++) {
        if(A[i] > A[i-1] && A[i] > A[i+1]) {
            peaks[i] = true;
            size++;
        }
    }
    
    while(size) {
        int factor = n/size;
        bool divided;
        if(n%size == 0) {
            for(int i=0;i<size;i++) {
                divided = false;
                for(int j=factor*i;j<factor*(i+1);j++) { // each block
                    if(peaks[j]) divided = true;
                }
                if(!divided) break; // each block check
            }
            if(divided) break; // all blocks check
        }
        size--;
    }
    return size;
}