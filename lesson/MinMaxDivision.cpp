// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool blockCheck(int mid, int k, vector<int> &a) {
    int sum = 0;
    int cnt = 0;
    for (int elem : a) {
        sum += elem;
        if (sum > mid) {
            sum = elem;
            cnt++;
        }
        if (cnt >= k) return false;
    }
    
    return true;
}

int solution(int K, int M, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int l_bound = 0;
    int u_bound = 0;
    for (int i = 0; i < A.size(); i++) {
        u_bound += A[i];
        l_bound = max(l_bound, A[i]);
    }
    int result = u_bound;
    while(l_bound <= u_bound) {
        int mid = (l_bound+u_bound)/2;
        if(blockCheck(mid, K, A)) {
            u_bound = mid - 1;
            result = mid;
        }
        else l_bound = mid + 1;
    }
    return result;
}
