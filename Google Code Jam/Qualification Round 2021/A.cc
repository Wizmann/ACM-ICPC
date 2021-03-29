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
#include <list>
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

    for (int case_ = 0; case_ < T; case_++) {
        int n;
        input(n);

        vector<int> ns(n);

        int num;
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            int mini = INF;
            int minp = -1;
            for (int j = i; j < n; j++) {
                if (ns[j] < mini) {
                    mini = ns[j];
                    minp = j;
                }
            }
            reverse(ns.begin() + i, ns.begin() + minp + 1);
            res += minp + 1 - i;
            /*
            for (auto x : ns) {
                printf("%d ", x);
            }
            puts("");
            */
        }

        printf("Case #%d: %d\n", case_ + 1, res);

    }

    return 0;
}

/*

^^^TEST^^^
3
4
4 2 1 3
2
1 2
7
7 6 5 4 3 2 1
-----
Case #1: 6
Case #2: 1
Case #3: 12
$$$TEST$$$

*/
