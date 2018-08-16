// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int gcd(int a, int b) {
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int solution(int N, int M) {
    // write your code in C++14 (g++ 6.2.0)
    long long lcm = (long long)N*M / gcd(N,M);
    return lcm/M;
}