#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 333;
const int DEPTH = 31;
const int INIT_POS = SIZE / 2;

llint dp[SIZE][SIZE][DEPTH];

/* 
directions
 7 0 1
 6   2
 5 4 3
*/

const int mx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int my[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int get_hash(int dir, int t_remains) {
    return t_remains * 8 + dir;
}

class Solution {
public:
    Solution(const vector<int>& ts_): ts(ts_) {
        memset(dp, 0, sizeof(dp));
    }

    int solve() {
        dfs(INIT_POS, INIT_POS, 0, 0);
        int res = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int cur = 0;
                for (int k = 0; k < DEPTH; k++) {
                    cur += dp[i][j][k]? 1: 0;
                    if (cur) {
                        break;
                    }
                }
                assert(cur == 0 || cur == 1);
                // printf("%c", cur? 'X': ' ');
                res += cur;
            }
            // puts("");
        }
        return res;
    }
private:
    void dfs(int y, int x, int dir, size_t idx) {
        if (idx == ts.size()) {
            return;
        }
        int t = ts[idx];

        for (int i = 0; i < t; i++) {
            y += my[dir];
            x += mx[dir];
            int hash = get_hash(dir, t - i);
            if (dp[y][x][idx] & (1LL << hash)) {
                return;
            }
            dp[y][x][idx] |= (1LL << hash);
        }
        dfs(y, x, (dir + 1) % 8, idx + 1);
        dfs(y, x, (dir + 7) % 8, idx + 1);
    }
private:
    vector<int> ts;
};

void test() {
    vector<int> v1 = {4, 2, 2, 3};
    assert(Solution(v1).solve() == 39);

    vector<int> v2 = {1, 1, 1, 1, 1, 3};
    assert(Solution(v2).solve() == 85);

    vector<int> v3 = {3};
    assert(Solution(v3).solve() == 3);
}

int main() {
    test();
    int n;
    vector<int> v;
    input(n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        input(v[i]);
    }
    print(Solution(v).solve());
    return 0;
}
