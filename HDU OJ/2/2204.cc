#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int primes[] = {
    2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59
};

const int PRIME_N = sizeof(primes) / sizeof(int);

llint solve(llint n, int p) {
    int cnt1 = 0;
    int cnt2 = 0;
    int pp = p;
    for (int i = 0; i < PRIME_N; i++) {
        if (pp % primes[i] == 0) {
            cnt1++;
            while (pp % primes[i] == 0) {
                pp /= primes[i];
                cnt2++;
            }
        }
    }
    if (cnt1 != cnt2) {
        return 0;
    }
    llint g = cnt1 % 2 == 0? -1: 1;
    return g * ((pow(1.0 * n, 1.0 / p) + 0.00000001) - 1);
}

int main() {
    llint n;
    while (input(n)) {
        llint res = 0;
        for (int i = 2; i <= 60; i++) {
            res += solve(n, i);
        }
        print(res + 1);
    }
    return 0;
}

