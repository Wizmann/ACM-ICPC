#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const double eps = 1e-7;

struct Point {
    Point() {}
    Point(int x_, int y_): x(x_), y(y_) {}
    int x, y;
};

int n;
vector<Point> points;
map<pair<int, int>, int> pmp;

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    while (input(n)) {
        points = vector<Point>(n);
        pmp.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            points[i] = Point(a, b);
            while (pmp.count(pair<int, int>(a, b))) {}
            pmp[pair<int, int>(a, b)] = i;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int deltax = points[i].x - points[j].x;
                int deltay = points[i].y - points[j].y;

                int p1x1 = points[i].x + deltay;
                int p1y1 = points[i].y - deltax;

                int p1x2 = points[j].x + deltay;
                int p1y2 = points[j].y - deltax;

                if (pmp.count(pair<int, int>(p1x1, p1y1)) &&
                        pmp.count(pair<int, int>(p1x2, p1y2))) {
                    cnt++;
                }

                int p2x1 = points[i].x - deltay;
                int p2y1 = points[i].y + deltax;

                int p2x2 = points[j].x - deltay;
                int p2y2 = points[j].y + deltax;

                if (pmp.count(pair<int, int>(p2x1, p2y1)) &&
                        pmp.count(pair<int, int>(p2x2, p2y2))) {
                    cnt++;
                }
            }
        }
        print(cnt / 4);
    }
    return 0;
}
