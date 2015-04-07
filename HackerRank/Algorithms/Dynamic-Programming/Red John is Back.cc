#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 52;
const int PRIME = 5555555;

int dp[SIZE];
int prime_cnt[PRIME];

void init() {
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = dp[2] = dp[3] = 1;
    for (int i = 4; i < SIZE; i++) {
        dp[i] = dp[i - 4] + dp[i - 1];
    }
    dp[0] = 0;
}

void sieve() {
    memset(prime_cnt, 0, sizeof(prime_cnt));

    for (int i = 2; i < PRIME; i++) {
        if (prime_cnt[i] != 0) {
            continue;
        }
        for (int j = 2; i * j < PRIME; j++) {
            prime_cnt[i * j] = -1;
        }
    }
    
    int cnt = 0;
    for (int i = 2; i < PRIME; i++) {
        if (prime_cnt[i] == 0) {
            cnt++;
        }
        prime_cnt[i] = cnt;
    }
}

int main() {
    int T, n;
    input(T);
    init();
    sieve();
    while (T--) {
        input(n);
        print(prime_cnt[dp[n]]);
    }
    return 0;
}

