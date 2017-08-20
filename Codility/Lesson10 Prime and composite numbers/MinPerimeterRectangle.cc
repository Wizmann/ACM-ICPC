// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <limits>

const int INF = numeric_limits<int>::max();

int solution(int N) {
    int ans = INF;
    for (int i = 1; 1LL * i * i <= N; i++) {
        if (N % i == 0) {
            ans = min(ans, 2 * (i + (N / i)));
        }
    }
    return ans;
}
