#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
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

const int ALPHA = 26;
const int N = 111;

const int char2int(char c) {
    return c - 'a' + 1;
}

int dp[N][N];

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int skip) {
        const int n = s.size();
        memset(dp, INF, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> cs = {0, char2int(s[i - 1])};
            for (auto c : cs) {
                int cnt = 0;
                for (int j = i; j <= n; j++) {
                    int m = j - i + 1;
                    if (char2int(s[j - 1]) == c) {
                        cnt++;
                    }
                    if (m - cnt > skip) {
                        break;
                    }
                    int delta = m - cnt;
                    for (int k = 0; k + delta <= skip; k++) {
                        dp[j][k + delta] = min(dp[j][k + delta], dp[i - 1][k] + get_length(cnt));
                    }
                }
            }
        }

        int ans = INF;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, dp[n][i]);
        }
        return ans;
    }

    int get_length(int cnt) {
        if (cnt == 0) {
            return 0;
        } else if (cnt == 1) {
            return 1;
        } else if (cnt < 10) {
            return 2;
        } else if (cnt < 100) {
            return 3;
        } else {
            return 4;
        }
    }
};


/*
^^^TEST^^^
a
2
---
0
$$$TEST$$$

^^^TEST^^^
aabbaa
2
---
2
$$$TEST$$$

^^^TEST^^^
aaaaaaaaaaaaa
0
---
3
$$$TEST$$$
*/
