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
        int n;
        input(n);

        if (n > 45) {
            puts("-1");
            continue;
        }

        string s;
        for (int i = 9; i >= 1 && n; i--) {
            if (n < i) {
                s += std::to_string(n);
                break;
            }

            s += std::to_string(i);
            n -= i;
        }
        reverse(s.begin(), s.end());
        print(s);
    }

    return 0;
}

/*

^^^TEST^^^
4
1
5
15
50
-----
1
5
69
-1
$$$TEST$$$

*/
