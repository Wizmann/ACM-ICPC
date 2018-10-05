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

const int primes[] = {
 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523};

const int PRIMESIZE = sizeof(primes) / sizeof(int);

vector<int> get_prime_factor(int n) {
    vector<int> res;

    for (int i = 0; i < PRIMESIZE; i++) {
        if (n % primes[i] == 0) {
            res.push_back(primes[i]);
        }
        while (n % primes[i] == 0) {
            n /= primes[i];
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

llint solve(int n, int m) {
    llint res = n;
    for (int i = 2; i <= m; i++) {
        vector<int> fs = get_prime_factor(i);
        int f = fs.size();

        for (int j = 0; j < (1 << f); j++) {
            int cnt = 0;
            llint fac = 1;
            for (int k = 0; k < f; k++) {
                if (j & (1 << k)) {
                    cnt++;
                    fac *= fs[k];
                }
            }
            llint t = (cnt % 2 == 0? -1: 1) * (n / fac);
            res -= t;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    while (T--) {
        int n, m;
        input(n >> m);
        print(solve(n, m));
    }
    return 0;
}
