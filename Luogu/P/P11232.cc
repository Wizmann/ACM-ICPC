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

constexpr double eps = 1e-7;

struct Car {
    int d, v, a;
};

struct Interval {
    int l, r;

    bool operator < (const Interval& other) const {
        return (r < other.l);
    }
};

int n, m, L, V;
vector<Car> cars;
vector<int> pos;
vector<Interval> intervals;

double calculatePosition(double v, double a, double t, double d) {
    return d + v * t + 0.5 * a * t * t;
}

int main() {
    int T;
    input(T);

    while (T--) {
        cars.clear();
        pos.clear();
        intervals.clear();

        scanf("%d%d%d%d", &n, &m, &L, &V);

        cars.resize(n);

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int d, v, a;
            scanf("%d%d%d", &d, &v, &a);
            cars[i] = {d, v, a};
        }

        set<Interval> st1;

        pos.resize(m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &pos[i]);
            st1.insert({pos[i], pos[i]});
        }

        for (int i = 0; i < n; i++) {
            int d = cars[i].d;
            int v = cars[i].v;
            int a = cars[i].a;

            Interval it = {-1, -1};

            if (a == 0) {
                if (v > V) {
                    it = {d, L};
                }
            } else if (a > 0) {
                if (v > V) {
                    it = {d, L};
                } else {
                    double t = 1.0 * (V - v) / a;
                    double startPos = calculatePosition(v, a, t, d);

                    int startPos_ = int(startPos + 1);

                    if (startPos_ <= L) {
                        it = {startPos_, L};
                    }
                }
            } else if (a < 0) {
                if (v > V) {
                    double t = 1.0 * (V - v) / a;
                    double endPos = calculatePosition(v, a, t, d);

                    int endPos_ = int(endPos - eps);

                    if (endPos_ >= d) {
                        it = {d, endPos_};
                    }
                }
            }

            if (it.l == -1) {
                continue;
            }

            if (st1.find(it) != st1.end()) {
                cnt++;
                intervals.push_back(it);
            }
        }


        sort(pos.begin(), pos.end());
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) {
            if (i1.r != i2.r) {
                return i1.r < i2.r;
            } else {
                return i1.l > i2.l;
            }
        });

        int cnt2 = 0;

        int ptr = -1;
        for (auto& it : intervals) {
            int l = it.l;
            int r = it.r;

            if (ptr != -1 && l <= pos[ptr] && pos[ptr] <= r) {
                continue;
            }

            while (ptr + 1 < m && pos[ptr + 1] <= r) {
                ptr++;
            }

            cnt2++;
        }
        printf("%d %d\n", cnt, m - cnt2);
    }

    return 0;
}

/*

^^^TEST^^^
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
-----
3 3
$$$TEST$$$

^^^^^^^^^^^TEST^^^^^^^^
1
10 10 145322 772
10139 897 -47
86524 947 -2
51251 982 -2
12573 962 -2
14068 919 -163
10944 994 -6
35650 999 -9
3804 977 -1
1149 905 -2
43935 932 -2
10519 11805 14747 28890 37732 45509 55779 80531 108392 126659
-----------------
10 6
$$$$$$$$$$$$TEST$$$$

*/
