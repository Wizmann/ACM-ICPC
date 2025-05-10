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
#include <bitset>
#include <cmath>
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

const int64_t LIMIT = 10000000;
const int SEGMENT_SIZE = 32768;

std::vector<int> base_primes; // 用于分段筛的基础质数
std::vector<int> all_primes;  // 存储结果：所有小于1e9的质数

// 普通筛法：生成 sqrt(n) 以内的质数
void simple_sieve(int64_t limit) {
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int64_t i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            base_primes.push_back((int)i);
            for (int64_t j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }
}

// 分段筛：将质数加入 all_primes
void segmented_sieve(int64_t n) {
    int64_t sqrt_n = static_cast<int64_t>(std::sqrt(n));
    simple_sieve(sqrt_n);

    int64_t low = 0;
    int64_t high = std::min(SEGMENT_SIZE, (int)n);

    std::vector<bool> is_prime(SEGMENT_SIZE);

    while (low < n) {
        std::fill(is_prime.begin(), is_prime.end(), true);

        for (int p : base_primes) {
            int64_t start = std::max<int64_t>(p * p, ((low + p - 1) / p) * p);
            for (int64_t j = start; j < high; j += p)
                is_prime[j - low] = false;
        }

        for (int64_t i = low; i < high; ++i) {
            if (i > 1 && is_prime[i - low])
                all_primes.push_back((int)i);
        }

        low += SEGMENT_SIZE;
        high = std::min(low + SEGMENT_SIZE, n);
    }
}


int main() {
    segmented_sieve(LIMIT);
    assert(all_primes.size() > 412345);

    int T;
    input(T);
    while (T--) {
        int n;
        input(n);
        vector<int> ns(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }
        sort(ns.begin(), ns.end());
        reverse(ns.begin(), ns.end());

        llint tot = 0;
        llint p = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            tot += ns[i] - 2;
            if (p + all_primes[i] - 2 > tot) {
                break;
            }
            p += all_primes[i] - 2;
            cnt = i + 1;
        }

        printf("%d\n", n - cnt);

    }
    return 0;
}


/*

^^^TEST^^^
5
3
5 5 5
4
2 3 2 4
1
3
3
2 100 2
5
2 4 2 11 2
-----
0
2
0
0
1
$$$TEST$$$

*/
