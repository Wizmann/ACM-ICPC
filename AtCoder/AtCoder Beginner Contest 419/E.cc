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

int main() {
    int N, M, L;
    input(N, M, L);
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        A[i] %= M;
    }

    vector<int> dp(M, INF);
    dp[0] = 0;

    vector<int> h(M, 0);
    vector<int> prefCnt(M, 0);
    vector<int> cost(M, 0);
    vector<int> ndp(M, INF);

    for (int r = 0; r < L; ++r) {
        h = vector<int>(M, 0);
        int tot = 0;
        int sumA = 0;
        for (int i = r; i < N; i += L) {
            h[A[i]]++;
            tot++;
            sumA += A[i];
        }
        prefCnt = vector<int>(M, 0);
        prefCnt[0] = h[0];
        for (int v = 1; v < M; ++v) {
            prefCnt[v] = prefCnt[v-1] + h[v];
        }
        cost = vector<int>(M, 0);
        for (int x = 0; x < M; ++x) {
            int cnt_le = prefCnt[x];
            int cnt_gt = tot - cnt_le;
            cost[x] = x * tot - sumA + cnt_gt * M;
        }

        ndp = vector<int>(M, INF);
        for (int s = 0; s < M; ++s) {
            if (dp[s] < INF) {
                for (int x = 0; x < M; ++x) {
                    int ns = s + x;
                    if (ns >= M) {
                        ns -= M;
                    }
                    int v = dp[s] + cost[x];
                    if (v < ndp[ns]) {
                        ndp[ns] = v;
                    }
                }
            }
        }
        dp.swap(ndp);
    }

    print(dp[0]);
    return 0;
}


/*

^^^TEST^^^
4 5 3
4 2 1 3
-----
4
$$$TEST$$$

^^^TEST^^^
7 10 4
7 0 9 1 6 4 2
-----
10
$$$TEST$$$
*/
