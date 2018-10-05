#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int MAXPRIME = 12345;

vector<int> get_prime_factor(int n) {
    vector<int> res;

    for (int i = 2; i < MAXPRIME; i++) {
        if (n % i == 0) {
            res.push_back(i);
        }
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

llint fastpow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

llint solve(int n, int m) {
    llint res = fastpow(m, n);
    vector<int> fs = get_prime_factor(m);
    int f = fs.size();

    for (int i = 1; i < (1 << f); i++) {
        int cnt = 0;
        llint fac = 1;
        for (int j = 0; j < f; j++) {
            if (i & (1 << j)) {
                cnt++;
                fac *= fs[j];
            }
        }
        res -= (cnt % 2 == 0? -1: 1) * fastpow(m / fac, n);
    }
     
    return res;
}

int main() {
    int n, m;
    input(n >> m);
    print(solve(n, m));
    return 0;
}
