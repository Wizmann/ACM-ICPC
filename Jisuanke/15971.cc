#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 19;
const int MOD = 1000000007;

int n, k;
int dp[SIZE][1 << SIZE];
vector<int> nums;
vector<int> tmp;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

void solve(const int step, const int mask) {
    if (dp[step][mask] == 0) {
        return;
    }
    if (mask == 0) {
        return;
    }
    tmp = vector<int>(n, -1);
    for (int i = 0; i < n; i++) {
        if ( !(mask & (1 << i)) ) {
            tmp[i] = -1;
        } else {
            tmp[i] = nums[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (tmp[i] == -1) {
            continue;
        }

        int g = -1;
        int mm = mask;
        for (int j = i; j < n; j++) {
            if (tmp[j] == -1) {
                continue;
            }
            if (g == -1) {
                g = tmp[j];
            } else {
                g = gcd(g, tmp[j]);
            }
            // assert (mask & (1 << j));
            mm ^= (1 << j);

            if (g >= k) {
                dp[step + 1][mm] = (dp[step + 1][mm] + dp[step][mask]) % MOD;
            } else {
                break;
            }
        }
    }
}

int main() {   
    input(n >> k);
    nums.resize(n);
    tmp.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    dp[0][(1 << n) - 1] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            solve(i, j);
        }
    }

    llint ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + 1LL * i * dp[i][0]) % MOD;
    }
    print(ans);

    return 0;
}
