#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;

struct Point {
    int x, y;
};

struct Rectangle {
    Point p1, p2;

    Point getP1() const {
        return p1;
    }

    Point getP2() const {
        return {p1.x, p2.y};
    }

    Point getP3() const {
        return p2;
    }

    Point getP4() const {
        return {p2.x, p1.y};
    }
};

int w, h, n;
vector<Rectangle> recs;
vector<int> g[SIZE];

bool rec_contain(const Rectangle& r, Point p) {
    return (r.p1.x < p.x && p.x < r.p2.x &&
        r.p1.y < p.y && p.y < r.p2.y);
}

int intersect(const Rectangle& r1, const Rectangle& r2) {
    int res = 0;
    if (rec_contain(r2, r1.getP1())) {
        res |= 1;
    }
    if (rec_contain(r2, r1.getP2())) {
        res |= 2;
    }
    if (rec_contain(r2, r1.getP3())) {
        res |= 4;
    }
    if (rec_contain(r2, r1.getP4())) {
        res |= 8;
    }
    return res;
}

bool do_cover(const Rectangle& r1, const Rectangle& r2) {
    int minx = max(r1.p1.x, r2.p1.x);
    int maxx = min(r1.p2.x, r2.p2.x);
    int miny = max(r1.p1.y, r2.p1.y);
    int maxy = min(r1.p2.y, r2.p2.y);

    return minx < maxx && miny < maxy;
}


int main() {
    int a, b, c, d;
    input(w >> h >> n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        recs.push_back({{a, b}, {c, d}});
    }

    vector<bool> fully_covered(n, false);
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = i + 1; j < n; j++) {
            x |= intersect(recs[i], recs[j]);

            if (do_cover(recs[i], recs[j])) {
                g[i].push_back(j);
            }
        }
        if (x == 15) {
            fully_covered[i] = true;
        }
    }

    int ans = 0;
    int mark = 0;
    for (int i = 0; i < n; i++) {
        if (fully_covered[i]) {
            continue;
        }
        set<int> s;
        queue<int> q;
        q.push(i);
        vector<bool> visit(n, false);
        s.insert(i);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (visit[cur]) {
                continue;
            } else {
                visit[cur] = 1;
            }

            for (auto child: g[cur]) {
                s.insert(child);
                q.push(child);
            }
        }
        if (s.size() > ans) {
            mark = i;
            ans = s.size();
        }
    }

    print(ans << ' ' << mark + 1);
    return 0;
}
