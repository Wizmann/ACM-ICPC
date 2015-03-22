#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class CombinationLockDiv2 {
public:
    int minimumMoves(string S, string T) {
        n = S.length();
        vec.clear();
        vec.resize(n);
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            vec[i] = (T[i] - S[i] + 10) % 10;
        }
        return dfs(0, 0, 0);
    }
private:
    static const int SIZE = 52;
    static const int MAXOP = SIZE * 9;
    static const int DIR_NUM = 2;
    static const int INF = 0x3f3f3f3f;
private:
    int dfs(int pre_dir, int pre_op, int ptr) {
        if (dp[pre_dir][pre_op][ptr] != -1) {
            return dp[pre_dir][pre_op][ptr];
        }
        int ans = INF;
        for (int i = 0; i <= 1; i++) { // 2 directions
            for (int j = 0; j < MAXOP; j++) {
                if (i == 0 && (vec[ptr] + j) % 10 != 0) {
                    continue;
                }
                if (i == 1 && (vec[ptr] - j) % 10 != 0) {
                    continue;
                }
                int step = 0;
                if (i == pre_dir) {
                    step = max(0, j - pre_op);
                } else {
                    step = j;
                }
                if (ptr + 1 < n) {
                    step += dfs(i, j, ptr + 1);
                }
                ans = min(ans, step);
            }
        }
        return dp[pre_dir][pre_op][ptr] = ans;
    }
private:
    int n;
    int dp[DIR_NUM][MAXOP][SIZE];
    vector<int> vec;
};

#define TEST(S, T, ans) do { \
    auto _S = S; \
    auto _T = T; \
    auto _ans = ans; \
 \
    auto cl = CombinationLockDiv2(); \
    int res = cl.minimumMoves(_S, _T); \
 \
    if (res != _ans) { \
        printf("Wrong Answer on test (%s, %s)\n", S, T); \
        printf("Answer is: %d, but your result is %d\n", _ans, res); \
    } \
} while (0)

int main() {
    TEST("1", "7", 4);
    TEST("123", "112", 1);
    TEST("607", "607", 0);
    TEST("1234", "4567", 3);
    TEST("020", "909", 2);
    TEST("4423232218340", "6290421476245", 18);
    return 0;
}
