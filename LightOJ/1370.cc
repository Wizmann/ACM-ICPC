#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 1234567;

vector<bool> sieve(SIZE, true);
vector<int> primes;

void init() {
    for (int i = 2; i < SIZE; i++) {
        if (sieve[i] == false) {
            continue;
        }
        for (int j = 2; 1LL * i * j < SIZE; j++) {
            sieve[i * j] = false;
        }
    }

    for (int i = 2; i < SIZE; i++) {
        if (sieve[i] == false) {
            continue;
        }
        primes.push_back(i);
    }
}

llint solve(vector<int>& ns) {
    llint ans = 0;
    for (auto num: ns) {
        ans += *upper_bound(primes.begin(), primes.end(), num);
    }
    return ans;
}

int main() {
    init();

    int T;
    input(T);

    int case_ = 0;
    while (T--) {
        printf("Case %d: ", ++case_);

        int n;
        input(n);

        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        llint ans = solve(ns);
        printf("%lld Xukha\n", ans);
    }

    return 0;
}

