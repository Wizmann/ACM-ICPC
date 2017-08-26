// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

typedef long long llint;

const llint LIMIT = 1000000000LL;

int solution(vector<int> &A) {
    int n = A.size();
    llint ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            cnt++;
        } else {
            ans += cnt;
        }
        if (ans > LIMIT) {
            ans = -1;
            break;
        }
    }
    return ans;
}
