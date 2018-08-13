// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    int profit = 0;
    int max_end = 0; // ��ġ i���� ������ i(Q) - p(P)�� �ִ�
    for(int i=1;i<n;i++) {
        if(max_end + A[i] - A[i-1] < 0 ) {
            max_end = 0; // P == Q ��� �ǹ�
        }
        else max_end = max_end + A[i] - A[i-1];
        profit = max(profit, max_end);
    }

    return profit;
}