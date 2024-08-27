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

struct MyPoint {
    int x, y;
};

llint dis2(const MyPoint& p1, const MyPoint& p2) {
    llint dx = (p1.x - p2.x);
    llint dy = (p1.y - p2.y);
    return dx * dx + dy * dy;
}

int main() {
    int x1, y1, x2, y2;
    input(x1, y1, x2, y2);

    MyPoint pa{x1, y1};
    MyPoint pb{x2, y2};

    int n;
    input(n);

    vector<MyPoint> points;

    int x, y;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        points.push_back({x, y});
    }

    sort(points.begin(), points.end(),
         [&](const MyPoint& p1, const MyPoint& p2) {
            return dis2(p1, pa) < dis2(p2, pa);
         });

    vector<llint> ds(n);
    for (int i = n - 1; i >= 0; i--) {
        ds[i] = dis2(pb, points[i]);
        if (i + 1 < n) {
            ds[i] = max(ds[i], ds[i + 1]);
        }
    }

    llint mini = min(dis2(pa, points[n - 1]), ds[0]);

    for (int i = 0; i + 1 < n; i++) {
        mini = min(mini, dis2(pa, points[i]) + ds[i + 1]);
    }
    print(mini);

    return 0;
}

/*

^^^TEST^^^
0 0 10 0
2
-3 3
10 0
-----
18
$$$TEST$$$

^^^TEST^^^
0 0 6 0
5
-4 -2
-2 3
4 0
6 -2
9 1
-----
30
$$$TEST$$$

*/
