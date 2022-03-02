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

int main() {
    int T;
    input(T);

    while (T--) {
        llint a, b, c;
        input(a, b, c);

        int step = 0;
        while (a <= c && b <= c) {
            if (a < b) {
                swap(a, b);
            }
            b += a;
            step++;
        }
        print(step);
    }

    return 0;
}

/*

^^^TEST^^^
2
1 2 3
5 4 100
-----
2
7
$$$TEST$$$

*/
