#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;
typedef unsigned long long ullint;

const vector<int> primes = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59
};

llint factor;
ullint ans;

void dfs(ullint n, ullint cur, llint cnt, int ptr, int limit) {
    int t = 0;
    while (true) {
        if (cur > n / primes[ptr]) {
            return;
        }
        if (t > limit) {
            return;
        }
        cur *= primes[ptr];
        t++;

        
        llint next = cnt * (1 + t);
        if (factor < next || (factor == next && cur < ans)) {
            factor = next;
            ans = cur;
        }
        dfs(n, cur, next, ptr + 1, t);
    }
}

void solve(ullint n) {
    ans = numeric_limits<ullint>::max();
    factor = 0;
    dfs(n, 1, 1, 0, 1000);
    print(ans << ' ' << factor);
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    ullint n;
    input(T);
    while (T--) {
        input(n);
        solve(n);
    }
    return 0;
}
