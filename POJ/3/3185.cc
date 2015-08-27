#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 20;
const int INF = 0x3f3f3f3f;

int main() {
    freopen("input.txt", "r", stdin);
    int t = 0;
    int status = 0;
    for (int i = 0; i < N; i++) {
        input(t);
        status = (status << 1) | t;
    }

    vector<int> dp(1 << 20, INF);
    queue<int> q;
    q.push(status);
    dp[status] = 0;

    while (!q.empty()) {
        int cur = q.front();
        if (cur == 0) {
            break;
        }
        q.pop();

        for (int i = 0; i < N; i++) {
            int next = cur;
            if (i - 1 >= 0) {
                next ^= 1 << (i - 1);
            }
            next ^= (1 << i);
            if (i + 1 < N) {
                next ^= 1 << (i + 1);
            }
            if (dp[next] == INF) {
                dp[next] = dp[cur] + 1;
                q.push(next);
            }
        }
    }
    print(dp[0]);
    return 0;
}


