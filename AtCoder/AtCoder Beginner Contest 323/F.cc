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

llint xa, ya, xb, yb, xc, yc;

int main() {
    input(xa, ya, xb, yb, xc, yc);

    if (xb > xc) {
        xa *= -1;
        xb *= -1;
        xc *= -1;
    }

    if (yb < yc) {
        ya *= -1;
        yb *= -1;
        yc *= -1;
    }

    // print(xa, ya, xb, yb, xc, yc);

    llint step1 = 0;
    if (xa != xb || (xa == xb && ya > yb)) {
        step1 += abs(xa - xb);
        step1 += abs(ya - (yb + 1));
    } else {
        step1 += abs(ya - (yb - 1));
        step1 += 4;
    }
    step1 += abs(yc - yb);
    if (xb != xc) {
        step1 += 2;
        step1 += abs(xb - xc);
    }

    llint step2 = 0;
    if (ya != yb || (ya == yb && xa < xb)) {
        step2 += abs(xa - (xb - 1));
        step2 += abs(ya - yb);
    } else {
        step2 += abs(xa - (xb + 1));
        step2 += 4;
    }
    step2 += abs(xc - xb);
    if (yb != yc) {
        step2 += 2;
        step2 += abs(yc - yb);
    }

    // print(step1, step2);
    print(min(step1, step2));

    return 0;
}

/*

^^^TEST^^^
1 2 3 3 0 5
-----
9
$$$TEST$$$

^^^TEST^^^
0 0 1 0 -1 0
-----
6
$$$TEST$$$

^^^TEST^^^
-100000000000000000 -100000000000000000 100000000000000000 100000000000000000 -100000000000000000 -100000000000000000
-----
800000000000000003
$$$TEST$$$

*/
