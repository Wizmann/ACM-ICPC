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
    int n;

    input(n);
    vector<int> ns(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    int k, x;
    input(k, x);

    vector<pair<int, int> > ps;
    for (auto num : ns) {
        if (x == num) {
            continue;
        }
        ps.push_back({abs(x - num), num});
    }
    sort(ps.begin(), ps.end());

    vector<int> ms;
    for (int i = 0; i < k; i++) {
        ms.push_back(ps[i].second);
    }
    sort(ms.begin(), ms.end());
    for (int i = 0; i < k; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", ms[i]);
    }

    return 0;
}

/*

^^^^^TEST^^^^
10
1 2 3 4 5 10 9 8 7 6
3 4
---------
2 3 5
$$$TEST$$$


 */
