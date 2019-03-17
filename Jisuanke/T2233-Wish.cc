#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 45;

const set<int> primes = { 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

llint dp[N + 1][100];

inline bool is_prime(int u) {
    return primes.count(u) != 0;
}

llint solve(int p, int cur, int pre) {
    assert(0 <= cur && cur < 10);
    assert(0 <= pre && pre < 10);
    
    int u = pre * 10 + cur;

    if (pre != 0 && !is_prime(u)) {
        return 0;
    }

    if (p == 1) {
        return is_prime(u)? 1: 0;
    }

    if (dp[p][u] != -1) {
        return dp[p][u];
    }

    llint res = 0;
    for (int i = 0; i < 10; i++) {
        if (pre == 0 && cur == 0 && i == 0) {
            res += solve(p - 1, i, cur);
        }
        if (i != 0) {
            res += solve(p - 1, i, cur);
        }
    }
    return dp[p][u] = res;
}

int main() {
    memset(dp, -1, sizeof(dp));

    assert(solve(2, 1, 0) == 4);
    assert(solve(2, 2, 0) == 2);
    assert(solve(1, 2, 1) == 0);
    assert(solve(1, 3, 1) == 1);
    assert(solve(3, 0, 0) == primes.size());

    llint n;
    input(n);

    vector<int> num(N, 0);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            int pre = num[i - 1];
            llint cnt = solve(N - i, j, pre);
            if (cnt >= n) {
                num[i] = j;
                break;
            } else {
                n -= cnt;
            }
        }
    }

    llint ans = 0;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (flag == false && num[i] == 0) {
            continue;
        }

        flag = true;
        printf("%d", num[i]);
    }
    puts("");

    return 0;
}
