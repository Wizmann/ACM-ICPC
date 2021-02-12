#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
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

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int n;
vector<int> ns;
set<int> factors;
map<int, int> gcds;

void find_factors(int num, int mini) {
    for (int i = 1; 1LL * i * i <= num; i++) {
        if (i > mini) {
            break;
        }
        if (num % i == 0) {
            factors.insert(i);
            if (num / i <= mini) {
                factors.insert(num / i);
            }
        }
    }
}

void find_gcd(int factor) {
    for (const auto& num : ns) {
        if (num % factor != 0) {
            continue;
        }

        if (gcds.count(factor) == 0) {
            gcds[factor] = num;
        } else {
            gcds[factor] = gcd(gcds[factor], num);
        }
    }
}

int main() {
    input(n);
    ns.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    int mini = *min_element(ns.begin(), ns.end());

    for (const auto& num : ns) {
        find_factors(num, mini);
    }


    for (const auto& factor : factors) {
        find_gcd(factor);
    }

    int cnt = 0;
    for (const auto& kv : gcds) {
        if (kv.first == kv.second) {
            // print(kv.first);
            cnt++;
        }
    }
    print(cnt);

    return 0;
}

/*

^^^TEST^^^
3
6 9 12
-----
2
$$$TEST$$$

^^^TEST^^^
4
8 2 12 6
-----
1
$$$TEST$$$

^^^TEST^^^
7
30 28 33 49 27 37 48
-----
7
$$$TEST$$$

*/
