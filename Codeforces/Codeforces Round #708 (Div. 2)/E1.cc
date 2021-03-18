#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int SIZE = 12345;

vector<int> sieve;
vector<int> primes;

void init() {
    sieve.resize(SIZE);
    for (int i = 2; i < SIZE; i++) {
        if (sieve[i] != 0) {
            continue;
        }
        for (int j = 2; i * j < SIZE; j++) {
            int u = i * j;
            while (u % i == 0) {
                sieve[i * j]++;
                u /= i;
            }
        }
    }

    for (int i = 2; i < SIZE; i++) {
        if (sieve[i] == 0) {
            primes.push_back(i);
        }
    }
}

int purify(int x) {
    int res = 1;
    for (auto prime : primes) {
        if (x < prime) {
            break;
        }
        int cnt = 0;
        while (x % prime == 0) {
            cnt += 1;
            x /= prime;
        }
        if (cnt % 2 == 1) {
            res *= prime;
        }
    }
    return res * x;
}

int main() {
    init();

    int T;
    input(T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);

        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        set<int> st;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int cur = ns[i];
            // print(cur, purify(cur));
            cur = purify(cur);
            if (st.count(cur) != 0) {
                res++;
                st.clear();
                st.insert(cur);
            } else {
                st.insert(cur);
            }
        }
        if (!st.empty()) {
            res++;
        }
        printf("%d\n", res);
    }

    return 0;
}

/*

^^^TEST^^^
5
5 0
18 6 2 4 1
3 0
2 2 2
3 0
1 1 1
5 0
6 8 1 24 8
1 0
1
-----
3
3
3
2
1
$$$TEST$$$

*/
