// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

const int MAXI = 111111;
const int INF = 0x3f3f3f3f;

vector<int> fibs;

void init() {
    fibs.push_back(1);
    int a = 1;
    int b = 1;
    
    while (a < MAXI) {
        int c = a + b;
        fibs.push_back(c);
        a = b;
        b = c;
    }
}

int solution(vector<int> &A) {
    init();
    int n = A.size();
    A.push_back(1);
    
    vector<int> dp(n + 1, INF);
        
    for (auto fib: fibs) {
        if (fib - 1 <= n && A[fib - 1] == 1) {
            dp[fib - 1] = 1;
        }
    }
    
    for (int i = 0; i <= n; i++) {
        if (A[i] == 0 || dp[i] == INF) {
            continue;
        }
        
        for (auto fib: fibs) {
            int next = i + fib;
            if (next > n) {
                break;
            }
            if (A[next] == 1) {
                dp[next] = min(dp[next], dp[i] + 1);
            }
        }
    }
    return dp[n] == INF? -1: dp[n];
}
