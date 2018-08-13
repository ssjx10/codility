// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<bool> isPrime(N+1, true);
    for(int i=2;i*i<=N;i++) { 
        if(isPrime[i] == false) continue;
        for(int j=i*i;j<=N;j+=i)
            isPrime[j] = false;
    }
    vector<bool> isSemiPrime(N+1, false); 
    for(int i=2;i*i<=N;i++) { 
        if(isPrime[i] == false) continue;
        for(int j=i*i;j<=N;j+=i) {
            if(j%i == 0 && isPrime[j/i]) {
                isSemiPrime[j] = true;
            }
        }
    }
    vector<int> semi(N+1, 0); // i까지의 갯수 누적합
    int cnt = 0;
    for(int i=1;i<isSemiPrime.size();i++) {
        if(isSemiPrime[i]) {
            cnt++;
        }
        semi[i] = cnt;
    }
    vector<int> ans;
    for(int i=0;i<P.size();i++) {
        int s = P[i];
        int e = Q[i];
        int val = semi[e] - semi[s];
        if(isSemiPrime[s]) val++;
        ans.push_back(val);
    }
    return ans;
}