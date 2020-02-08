// https://codeforces.com/problemset/problem/300/C

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000000 + 7;

vector<llint> goodnums;
vector<llint> fac;

llint to_good(llint length, llint value, int a, int b) {
    llint res = 0;
    for (llint i = length - 1; i >= 0; i--) {
        if (value & (1LL << i)) {
            res = res * 10 + b;
        } else {
            res = res * 10 + a;
        }
    }
    return res;
}

llint fastpow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

llint C(int n, int a) {
    llint res = fac[n];
    res *= fastpow(fac[n - a], MOD - 2);
    res %= MOD;
    res *= fastpow(fac[a], MOD - 2);
    res %= MOD;
    return res;
}

llint solve(int a, int b, int n) {
    goodnums.clear();

    fac = vector<llint>(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    for (int i = 1; i <= 7; i++) {
        for (int j = 0; j < (1 << i); j++) {
            llint u = to_good(i, j, a, b);
            if (u > n * 9) {
                break;
            }
            goodnums.push_back(u);
        }
    }

    llint res = 0;
    for (auto g : goodnums) {
        for (int i = 0; i <= n; i++) {
            llint u = i * b + (n - i) * a;
            if (u > g) {
                break;
            }
            if (u == g) {
                res += C(n, i);
                res %= MOD;
                break;
            }
        }
    }
    return res;
}

int main() {
    int a, b, n;

    input(a >> b >> n);
    print(solve(min(a, b), max(a, b), n));

    return 0;
}
