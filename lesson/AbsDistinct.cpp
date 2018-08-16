// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int left = 0;
    int right = A.size()-1;
    int cnt = 0;
    while(left <= right) {
        long long x = abs((long long)A[left]);
        long long y = abs((long long)A[right]);
        if(x > y) {
            left++;
            cnt++;
        }
        else if(x < y) {
            right--;
            cnt++;
        }
        else {
            right--;
            left++;
            cnt++;
        }
        while(left <= right && left > 0 && A[left] == A[left-1]) {
            left++;
        }
        while( left <= right && right < A.size()-1 && A[right] == A[right+1]) {
            right--;
        }
    }
    return cnt;
}