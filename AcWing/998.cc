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

enum OpType { eAND, eOR, eXOR };

struct Operation {
    OpType type;
    int param;
};

int check(int cur, const vector<Operation> ops) {
    for (const auto& op : ops) {
        switch (op.type) {
            case eAND: {
                cur &= op.param;
            } break;
            case eOR: {
                cur |= op.param;
            } break;
            case eXOR: {
                cur ^= op.param;
            } break;
            default: {
                assert(false);
                break;
            }
        }
    }
    return cur;

}

int main() {
    int n, m;
    input(n, m);

    vector<int> bits;
    for (int i = 0; i <= 32; i++) {
        int bit = (1 << i);
        if (m & bit) {
            bits.push_back(1);
        } else {
            bits.push_back(0);
        }
    }

    int x;
    char cmd[10];
    vector<Operation> ops;

    for (int i = 0; i < n; i++) {
        scanf("%s%d", cmd, &x);
        if (cmd[0] == 'A') {
            ops.push_back({eAND, x});
        } else if (cmd[0] == 'O') {
            ops.push_back({eOR, x});
        } else if (cmd[0] == 'X') {
            ops.push_back({eXOR, x});
        } else {
            assert(false);
        }
    }

    bool flag = true;
    int result = 0;

    int res0 = check(0, ops);
    int res1 = check(-1, ops);

    for (int i = bits.size() - 1; i >= 0; i--) {
        if (res0 & (1 << i)) {
            result |= 1 << i;
            if (bits[i]) {
                flag = false;
            }
        } else if ((bits[i] || flag == false) && (res1 & (1 << i))) {
            result |= 1 << i;
        } else if ((bits[i])) {
            flag = false;
        }
    }

    print(result);

    return 0;
}

/*

^^^TEST^^^
3 10
AND 5
OR 6
XOR 7
-----
1
$$$TEST$$$

^^^TEST^^^
1 0
OR 8
-----
8
$$$TEST$$$

^^^TEST^^^
1 0
XOR 500
-----
500
$$$TEST$$$

*/
