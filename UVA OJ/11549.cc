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

llint square(llint cur, llint limit) {
    cur = cur * cur;
    while (cur >= limit) {
        cur /= 10;
    }
    return cur;
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        int n, k;
        input(n, k);

        llint limit = 1;
        for (int i = 0; i < n; i++) {
            limit *= 10;
        }

        llint fast = k;
        llint slow = k;

        llint maxi = k;

        while (true) { 
            fast = square(fast, limit);
            maxi = max(maxi, fast);
            if (slow == fast) {
                break;
            }
            fast = square(fast, limit);
            maxi = max(maxi, fast);
            if (slow == fast) {
                break;
            }
            slow = square(slow, limit);
            maxi = max(maxi, slow);
        }
        printf("%lld\n", maxi);
    }

    return 0;
}

/*

^^^TEST^^^
2
1 6
2 99
-----
9
99
$$$TEST$$$

*/
