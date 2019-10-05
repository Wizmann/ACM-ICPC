#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <list>
#include <cassert>

using namespace std;

#define print(x) cout << x << '\n'
#define input(x) cin >> x
#define FOR(i, n) for (int i = 0; i < n; i++)

typedef long long llint;

const int SIZE= 5'555'555;

char sieve[SIZE];
llint cnt[SIZE];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    for (int i = 2; i < SIZE; i++) {
        if (sieve[i]) {
            continue;
        }
        for (int j = 2; 1LL * i * j < SIZE; j++) {
            sieve[i * j] = 1;
        }
        llint cur = i;
        while (cur < SIZE) {
            for (int j = 1; 1LL * cur * j < SIZE; j++) {
                cnt[1LL * cur * j]++;
            }
            cur *= i;
        }
    }

    for (int i = 2; i < SIZE; i++) {
        cnt[i] += cnt[i - 1];
    }

    int T;
    input(T);

    /*
    for (int i = 0; i < 10; i++) {
        print(cnt[i]);
    }
    */

    int a, b;
    while (T--) {
        input(a >> b);
        print(cnt[a] - cnt[b]);
    }

    return 0;
}