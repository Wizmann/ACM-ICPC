#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;
typedef unsigned long long ullint;

const ullint MAXI = 1000000000000000000LL;
const vector<int> primes = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53
};

void dfs(int n, int ptr, llint factor, ullint cur, ullint& ans) {
    if (factor > n || cur > MAXI) {
        return;
    }
    int cnt = 0;
    while (cur < MAXI) {
        cur *= primes[ptr];
        cnt++;
        llint next = factor * (1 + cnt);
        if (next > n) {
            return;
        }
        if (next == n) {
            ans = min(ans, cur);
            return;
        }
        dfs(n, ptr + 1, next, cur, ans);
    }
}

ullint solve(int n) {
    if (n == 1) {
        return 1;
    }
    ullint ans = numeric_limits<llint>::max();
    dfs(n, 0, 1, 1, ans);
    return ans;
}

int main() {
    int n;
    input(n);
    print(solve(n));
    return 0;
}
