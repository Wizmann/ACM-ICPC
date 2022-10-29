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

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
//

int dp[2][4][30];

void myfill(int p) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 30; j++) {
            dp[p][i][j] = -INF;
        }
    }
}

int solution(string &S) {
    myfill(0);
    myfill(1);

    dp[0][0][0] = 0;

    int n = S.size();
    int p = 0;
    for (int i = 0; i < n; i++) {
        int q = p ^ 1;
        myfill(q);

        int c = S[i] - 'a' + 1;
        for (int j = 0; j <= 3; j++) {
            for (int k = 0; k <= 26; k++) {
                dp[q][j][k] = max(dp[q][j][k], dp[p][j][k]);
                if (k == c) {
                    dp[q][j][c] = max(dp[q][j][c], dp[p][j][c] + 1);
                }
                if (j + 1 <= 3) {
                    dp[q][j + 1][c] = max(dp[q][j + 1][c], dp[p][j][k] + 1);
                }
            }
        }
        p = q;
    }

    int maxi = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 26; j++) {
            maxi = max(maxi, dp[p][i][j]);
        }
    }
    return maxi;
}
