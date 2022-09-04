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

const int MAX_N = 2555;
const int MAX_M = 2555;

int n, m;
vector<int> word;
vector<int> keyboard;

vector<set<int> > ps;
vector<int> dp[2];

int solve() {
    dp[0] = vector<int>(MAX_M, 0);
    dp[1] = vector<int>(MAX_M, INF);

    int p = 0;
    for (int i = 0; i < n; i++) {
        int q = p ^ 1;
        fill(dp[q].begin(), dp[q].end(), INF);

        int c = word[i];

        for (int j = 0; j < m; j++) {
            if (c == keyboard[j]) {
                dp[q][j] = min(dp[q][j], dp[p][j]);
                continue;
            }

            do {
                auto iter_l = ps[c].upper_bound(j);
                if (iter_l == ps[c].begin()) {
                    break;
                }
                int l = *(--iter_l);
                dp[q][l] = min(dp[q][l], dp[p][j] + abs(l - j));
            } while (0);

            do {
                auto iter_r = ps[c].upper_bound(j);
                if (iter_r == ps[c].end()) {
                    break;
                }
                int r = *(iter_r);
                dp[q][r] = min(dp[q][r], dp[p][j] + abs(r - j));
            } while (0);
        }

        p = q;
    }

    int mini = INF;
    for (int i = 0; i < m; i++) {
        mini = min(mini, dp[p][i]);
    }
    return mini;
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {

        input(n);
        word.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &word[i]);
        }

        input(m);
        keyboard.resize(m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &keyboard[i]);
        }

        ps.clear();
        ps.resize(MAX_N);

        for (int i = 0; i < m; i++) {
            int c = keyboard[i];
            ps[c].insert(i);
        }

        printf("Case #%d: %d\n", case_ + 1, solve());
    }

    return 0;
}

/*

^^^TEST^^^
2
5
1 2 3 2 1
3
1 2 3
3
1 1 1
2
2 1
-------
Case #1: 4
Case #2: 0
$$$TEST$$$

^^^TEST^^^
2
4
2 1 4 1
8
4 1 5 2 1 3 5 4
3
1 2 3
8
2 3 5 1 4 6 7 2
-----
Case #1: 4
Case #2: 4
$$$TEST$$$

*/
