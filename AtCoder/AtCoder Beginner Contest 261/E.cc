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

struct Operator {
    int type;
    int C;
};

int n, c;
vector<int> res;

void solve(int p, const vector<Operator>& ops, int base) {
    vector<int> ms[2];
    ms[0] = vector<int>(n, 0);
    ms[1] = vector<int>(n, 0);

    for (int i = 0; i <= 1; i++) {
        int pre = i;
        for (int j = 0; j < n; j++) {
            int u = (ops[j].C & (1 << p)) ? 1 : 0;
            if (ops[j].type == 1) {
                pre &= u;
            } else if (ops[j].type == 2) {
                pre |= u;
            } else if (ops[j].type == 3) {
                pre ^= u;
            } else {
                assert(false);
            }

            ms[i][j] = pre;
        }
    }

    for (int i = 0; i < n; i++) {
        base = ms[base][i];
        res[i] |= base << p;
    }
}

int main() {
    input(n, c);

    vector<Operator> ops(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ops[i].type, &ops[i].C);
    }

    res = vector<int>(n, 0);
    for (int i = 0; i <= 30; i++) {
        solve(i, ops, (c & (1 << i)) ? 1 : 0);
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}

/*

^^^TEST^^^
3 10
3 3
2 5
1 12
-----
9
15
12
$$$TEST$$$

^^^TEST^^^
9 12
1 1
2 2
3 3
1 4
2 5
3 6
1 7
2 8
3 9
-----
0
2
1
0
5
3
3
11
2
$$$TEST$$$

*/
