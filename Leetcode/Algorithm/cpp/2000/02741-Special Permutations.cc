#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int MOD = 1000000000 + 7;

struct Node {
    int pre;
    int status;
    int cnt;
};

class Solution {
public:
    int specialPerm(const vector<int>& nums_) {
        nums = nums_;
        int n = nums.size();

        vector<Node> dp[2];
        dp[0].push_back({-1, 0, 1});

        int p = 0;
        for (int i = 0; i < n; i++) {
            int q = p ^ 1;
            dp[q].clear();
            for (int j = 0; j < n; j++) {
                unordered_map<int, int> mp;
                for (const auto& u : dp[p]) {
                    int pre = u.pre;
                    int status = u.status;
                    int cnt = u.cnt;

                    if (pre == j) {
                        continue;
                    }
                    if (status & (1 << j)) {
                        continue;
                    }

                    if (pre == -1 ||
                            nums[pre] % nums[j] == 0 ||
                            nums[j] % nums[pre] == 0) {
                        int nxt = status | (1 << j);
                        mp[nxt] = (mp[nxt] + cnt) % MOD;
                    }
                }

                for (const auto& kv: mp) {
                    dp[q].push_back({j, kv.first, kv.second});
                }
            }
            p = q;
        }

        int tot = 0;
        for (const auto& u : dp[p]) {
            tot = (1LL * tot + u.cnt) % MOD;
        }
        return tot;
    }

private:
    vector<int> nums;
};

