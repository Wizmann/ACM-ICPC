#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MAXI = 1000001000;

vector<int> primes = {2, 3, 5};

void init() {
    for (int i = 7; 1LL * i * i <= MAXI; i += 2) {
        bool flag = true;
        for (auto prime: primes) {
            if (i % prime == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            primes.push_back(i);
        }
    }
}

const int N = 1111;

int dp[N][N];

int solve(int n, int m) {
    if (n < 0) {
        return 0;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }
    if (n == 0) {
        return 1;
    }
    if (m == 0) {
        return 0;
    }
    int cnt = 0;
    for (int i = 0; primes[i] <= min(m, n); i++) {
        cnt += solve(n - primes[i], primes[i]);
    }
    // print(n << ' ' << m << ' ' << cnt);
    return dp[n][m] = cnt;
}

int main() {
    init();
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < N; i++) {
        int res = solve(i, i - 1);
        if (res > 5000) {
            print(i << ' ' << res);
            break;
        }
    }
    return 0;
}

