#include <bits/stdc++.h>

using namespace std;

const int N = 111;
const int MAGIC = 2;
const int INF = 0x3f3f3f3f;

int dp[4];

int to_int(char x) {
    return x - '0';
}

int bit_diff(int x, int y) {
    int z = x ^ y;
    int res = 0;
    while (z) {
        res += z & 1;
        z >>= 1;
    }
    return res;
}

int minSteps(int n, string B){
    if (n <= 2) {
        return 0;
    }
    memset(dp, INF, sizeof(INF));
    int u = (to_int(B[0]) << 1) + to_int(B[1]);
    
    for (int i = 0; i < 4; i++) {
        int diff = bit_diff(i, u);
        dp[i] = diff;
    }

    for (int i = 2; i < n; i++) {
        int next[4] = {INF, INF, INF, INF};
        int cur = to_int(B[i]);
        for (int j = 0; j < 4; j++) {
            u = (j << 1) + cur;
            if (u != MAGIC) {
                next[u & 3] = min(next[u & 3], dp[j]);
            }
            u = (j << 1) + (cur ^ 1);
            if (u != MAGIC) {
                next[u & 3] = min(next[u & 3], dp[j] + 1);
            }
        }
        for (int j = 0; j < 4; j++) {
            dp[j] = next[j];
        }
    }
    int ans = INF;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, dp[i]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    string B;
    cin >> B;
    int result = minSteps(n, B);
    cout << result << endl;
    return 0;
}
