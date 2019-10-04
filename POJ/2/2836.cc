#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;
const int N = 15;
const int SIZE = (1 << 15) + 123;

struct MyPoint {
    int x, y;
    MyPoint() {}
    MyPoint(int x_, int y_) : x(x_), y(y_) {}
};

struct Rectangle {
    int area;
    int feature;
};

int n;
int dp[SIZE];
vector<Rectangle> rect;
vector<MyPoint> points;

int dfs(int bitmap) {
    if (dp[bitmap] < INF) {
        return dp[bitmap];
    }

    if (bitmap == 0) {
        return 0;
    }

    int res = INF;

    for (int i = 0; i < rect.size(); i++) {
        int f = rect[i].feature;
        if (!(bitmap & f)) {
            continue;
        }

        res = min(res, rect[i].area + dfs(bitmap & ~f));
    }

    return dp[bitmap] = res;
}

int main() {
    while (scanf("%d", &n) != EOF && n) {
        int a, b;
        points.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            points[i] = MyPoint(a, b);
        }

        memset(dp, INF, sizeof(dp));

        rect.clear();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int minx = min(points[i].x, points[j].x);
                int maxx = max(points[i].x, points[j].x);
                int miny = min(points[i].y, points[j].y);
                int maxy = max(points[i].y, points[j].y);

                rect.push_back(Rectangle());
                int ridx = rect.size() - 1;

                for (int k = 0; k < n; k++) {
                    if (minx <= points[k].x && points[k].x <= maxx &&
                        miny <= points[k].y && points[k].y <= maxy) {
                        rect[ridx].feature |= 1 << k;
                    }
                }

                rect[ridx].area = abs(maxx - minx) * abs(maxy - miny);
                if (rect[ridx].area == 0) {
                    rect[ridx].area = max(maxx - minx, maxy - miny);
                }
            }
        }

        printf("%d\n", dfs((1 << n) - 1));
    }
    return 0;
}
