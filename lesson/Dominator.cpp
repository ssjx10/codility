// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = 0;
    int value;
    for(int i=0;i<A.size();i++) { // leader�� N/2���� Ŀ���ϹǷ� ������ ������ �̿� O(N)
        if(size == 0) {
            size++;
            value = A[i];
        }
        else {
            if(value != A[i])
                size--;
            else size++;
        }
    }
    int cand = -1;
    if(size > 0) cand = value; // ������ �ĺ� ����
    int dom = -1;
    int cnt = 0;
    int ans = -1;
    for(int i=0;i<A.size();i++) {
        if(A[i] == cand) {
            cnt++;
            ans = i;
        }
    }
    if(cnt > A.size()/2) dom = cand; // ���� Ȯ��
    if(dom == -1) ans = -1;
    
    return ans;
}