// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int max_profit = 0;
    int min_price = 200000;
    for(int i=0;i<A.size();i++) {
        min_price = min(min_price, A[i]);
        max_profit = max(max_profit, A[i] - min_price);
    }
    return max_profit;
}