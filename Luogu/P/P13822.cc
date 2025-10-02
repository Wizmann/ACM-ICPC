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

    vector<int> a, b;

    while (T--) {
        int n;
        scanf("%d", &n);
        a.resize(n);
        b.resize(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }

        bool flag = true;
        for (int i = 0; i < n && n != 1; i++) {
            int diff = a[i] - b[i];
            if (diff % 2) {
                flag = false;
                break;
            }
        }

        puts(flag ? "Yes" : "No");
    }

    return 0;
}

/*

^^^TEST^^^
3
1
1
2
4
1 2 3 4
3 2 3 2
2
1 2
2 1
-----
Yes
Yes
No
$$$TEST$$$

*/
