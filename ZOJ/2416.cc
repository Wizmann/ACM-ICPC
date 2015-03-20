// Result: 2015-03-20 14:21:28	Accepted	2416	C++0x	50	320	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 12345;
const int INF = 0x3f3f3f3f;

int dp[SIZE];
int a, b;

void bfs(int st) {
    queue<pair<int, int> > q;
    q.push({st, 0});

    while (!q.empty()) {
        int num  = q.front().first;
        int step = q.front().second;
        q.pop();
        
        if (dp[num] > step) {
            dp[num] = step;
        } else {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nums[4] = {
                (num / 1000) % 10,
                (num / 100 ) % 10,
                (num / 10  ) % 10,
                (num / 1   ) % 10
            };
            
            nums[i] = (nums[i] + 1) % 9;
            int new_num = (nums[0] * 1000 +
                           nums[1] * 100  +
                           nums[2] * 10   +
                           nums[3] * 1);
            if (dp[new_num] <= step + 1) {
                continue;
            }
            q.push({new_num, step + 1});
        }

        for (int i = 0; i < 4; i++) {
            int nums[4] = {
                (num / 1000) % 10,
                (num / 100 ) % 10,
                (num / 10  ) % 10,
                (num / 1   ) % 10
            };
            
            nums[i] = (nums[i] + 8) % 9;
            int new_num = (nums[0] * 1000 +
                           nums[1] * 100  +
                           nums[2] * 10   +
                           nums[3] * 1);
            if (dp[new_num] <= step + 1) {
                continue;
            }
            q.push({new_num, step + 1});
        }

        for (int i = 0; i < 3; i++) {
            int nums[4] = {
                (num / 1000) % 10,
                (num / 100 ) % 10,
                (num / 10  ) % 10,
                (num / 1   ) % 10
            };

            swap(nums[i], nums[i + 1]);
            int new_num = (nums[0] * 1000 +
                           nums[1] * 100  +
                           nums[2] * 10   +
                           nums[3] * 1);
            if (dp[new_num] <= step + 1) {
                continue;
            }
            q.push({new_num, step + 1});
        }
    }
}

int solve(int a, int b) {
    memset(dp, INF, sizeof(dp));
    bfs(a);
    return dp[b];
}


int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    while (T--) {
        input(a >> b);
        a -= 1111;
        b -= 1111;
        print(solve(a, b));
    }
    return 0;
}
