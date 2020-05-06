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

using namespace std;

typedef long long llint;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X& x, T... args) { cout << x << " "; print(args...); }

void input() { /* pass */ }

template <typename...T, typename X>
void input(X& x, T&... args) { cin >> x; input(args...); }

const int N = 3333;
const int MOD = 998244353;

llint dp[N][N];

int main()
{
    int n, s;
    input(n, s);

    vector<int> ns(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
    }

    memset(dp, 0, sizeof(int));
    dp[0][0] = 1;

    llint tot = 0;

    for (int i = 1; i <= n; i++) {
        int cur = ns[i];
        for (int j = 0; j <= s; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - cur > 0) {
                dp[i][j] += dp[i - 1][j - cur];
            } else if (j - cur == 0) {
                dp[i][j] += i;
            }
            dp[i][j] %= MOD;
            // print(i, j, dp[i][j]);
        }
        // print();
        tot += dp[i][s];
        tot %= MOD;
    }

    print(tot);

    return 0;
}

