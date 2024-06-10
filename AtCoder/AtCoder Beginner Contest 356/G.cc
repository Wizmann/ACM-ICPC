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
#include <cmath>
#include <set>
#include <deque>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;

typedef long long llint;
typedef uint32_t uint;

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

const double eps=1e-12;

struct CPoint
{
    llint x, y;
};

llint cross(CPoint p1, CPoint p2){
    return p1.x * p2.y - p1.y * p2.x;
}
CPoint sub(CPoint p1,CPoint p2){
    return {p1.x - p2.x, p1.y - p2.y};
}

void getConvexHull(std::vector<CPoint> &points) {
    int n = static_cast<int>(points.size());
    if (n <= 2) {
        return;
    }
    std::vector<CPoint> g1, g2;
    g1.push_back(points[0]);
    g1.push_back(points[1]);
    g2.push_back(points[0]);
    g2.push_back(points[1]);
    for(int i = 2;i < n;i++){
        while(g1.size() >= 2 && cross(sub(g1[g1.size() - 1], g1[g1.size() - 2]), sub(points[i], g1[g1.size() - 1])) <= 0) {
            g1.pop_back();
        }
        while(g2.size() >= 2 && cross(sub(g2[g2.size() - 1], g2[g2.size() - 2]), sub(points[i], g2[g2.size() - 1])) >= 0) {
            g2.pop_back();
        }
        g1.push_back(points[i]);
        g2.push_back(points[i]);
    }
    points.clear();
    for(auto & i : g1) {
        points.push_back(i);
    }
    for(int i= static_cast<int>(g2.size()) - 2;i>=1;i--) {
        points.push_back(g2[i]);
    }
}

int main() {
    int n;
    input(n);

    llint a, b;
    set<pair<llint, llint> > st;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &b, &a);
        auto p = pair<llint, llint>(a, b);
        st.insert(p);
    }

    vector<CPoint> ps;
    for (auto p : st) {
        ps.push_back({p.first, p.second});
    }

    getConvexHull(ps);
    int m = ps.size();

    int p0 = 0;
    int p1 = 0;
    for (int i = 0; i < m; i++) {
        if (ps[p0].x < ps[i].x) {
            p0 = i;
        }
        if (ps[i].y * ps[p1].x < ps[i].x * ps[p1].y) {
            p1 = i;
        }
    }

    vector<CPoint> ps2;
    for (int i = p1; /* pass */; i = (i + 1) % m) {
        ps2.push_back(ps[i]);
        if (i == p0) {
            break;
        }
    }

    m = ps2.size();
    assert(m > 0);

    int q;
    input(q);

    llint c, d;
    while (q--) {
        scanf("%lld%lld", &c, &d);

        if (c * ps2.begin()->x < d * ps2.begin()->y) {
            puts("-1");
            continue;
        } else if (c * ps2.rbegin()->x >= ps2.rbegin()->y * d) {
            printf("%.12lf\n", 1.0 * d / ps2.rbegin()->x);
            continue;
        }

        int idx1, idx2;
        {
            int l = 1;
            int r = m - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (ps2[mid].x * c >= ps2[mid].y * d) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            idx1 = r;
            idx2 = l;
        }

        double x0 = ps2[idx1].x;
        double y0 = ps2[idx1].y;
        double x1 = ps2[idx2].x;
        double y1 = ps2[idx2].y;

        double answer = (y0 - x0 * (y1 - y0) / (x1 - x0)) / (1.0 * c / d - (y1 - y0) / (x1 - x0));
        printf("%.12lf\n", 1.0 * d / answer);
    }

    return 0;
}

/*
^^^^TEST^^^^
4
1 2
2 3
3 3
4 4
5
4 7
7 7
49 100
1000 500
4 5
--------------
3.000000000000000000
1.750000000000000000
-1
125.000000000000000000
1.500000000000000000
$$$$TEST$$$$


^^^^TEST^^^^
10
7 10
2 2
4 8
9 7
7 3
3 2
3 6
8 3
1 10
3 1
3
7 8
3 4
9 10
-----------------
0.800000000000
0.400000000000
1.000000000000
$$$TEST$$$

^^^^TEST^^^
4
9 7
4 7
5 6
8 4
3
8 2
6 4
10 1
---------------
0.285714285714
0.571428571429
0.142857142857
$$$TEST$$$

^^^TEST^^^
4
1 8
4 5
5 5
3 4
3
6 1
3 9
4 8
------------
0.125000000000
1.125000000000
1.000000000000
$$$$TEST$$$$

^^^^TEST^^^^
20
5 8
8 7
6 1
6 4
9 1
10 10
2 9
4 10
3 7
5 4
7 2
6 1
6 3
8 5
9 6
6 5
3 4
1 5
7 9
10 5
3
9 8
7 8
3 8
---------------
0.800000000000
0.800000000000
0.812500000000
$$$TEST$$$



 */
