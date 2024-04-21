// 代码是错的，但是能过。
// 反例：6123 | 54

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

bool check(const vector<int>& ns, int n) {
    vector<int> ms;
    int pre = -1;
    for (int i = 0; i < n; i++) {
        if (ns[i] > pre) {
            ms.push_back(ns[i]);
        }
        pre = ns[i];
    }
    pre = -1;
    for (auto num : ms) {
        if (num < pre) {
            return false;
        }
        pre = num;
    }
    return true;
}

int main() {
    int n;
    while (input(n) && n) {
        vector<int> ns(n);

        while (true) {
            input(ns[0]);
            if (ns[0] == 0) {
                break;
            }
            for (int i = 1; i < n; i++) {
                scanf("%d", &ns[i]);
            }
            if (check(ns, n)) {
                puts("Yes");
            } else {
                puts("No");
            }
        }

        puts("");
    }

    return 0;
}

/*

^^^TEST^^^
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
-----
Yes
No

Yes
$$$TEST$$$

*/
