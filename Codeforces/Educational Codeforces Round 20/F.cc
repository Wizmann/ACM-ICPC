#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;
const int MOD = 1000000000 + 7;

int dp[SIZE];
int twos[SIZE];
int cnt[SIZE];

void init() {
    twos[0] = 1;
    for (int i = 1; i < SIZE; i++) {
        twos[i] = (2LL * twos[i - 1]) % MOD;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, x;
    input(n);

    init();

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    for (int i = SIZE - 1; i > 0; i--) {
        int div = 0;

        for (int j = i; j < SIZE; j += i) {
            div += cnt[j];
        }

        dp[i] = twos[div] - 1;

        for (int j = i * 2; j < SIZE; j += i) {
            dp[i] = (dp[i] - dp[j] + MOD) % MOD;
        }
    }

    print(dp[1]);

    return 0;
}
