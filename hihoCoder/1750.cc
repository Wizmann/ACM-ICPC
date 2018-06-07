#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

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

int main() {
    freopen("input.txt", "r", stdin);
    init();

    int l, r;
    input(l >> r);

    int n = r - l + 1;
    vector<int> rem(n);
    vector<int> cnt(n, 0);

    for (int i = 0; i < n; i++) {
        rem[i] = i + l;
    }

    for (auto prime: primes) {
        int p = (prime - l % prime) % prime;

        while (p < n) {
            while (rem[p] % prime == 0) {
                cnt[p]++;
                rem[p] /= prime;
            }
            p += prime;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        if (rem[i] >= 2) {
            cnt[i]++;
        }

        auto iter = lower_bound(primes.begin(), primes.end(), cnt[i]);
        if (iter != primes.end() && *iter == cnt[i]) {
            res++;
        }
    }

    print(res);

    return 0;
}
