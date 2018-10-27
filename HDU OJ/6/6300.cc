#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

struct Point {
    int x, y, nr;

    Point(int x_, int y_, int nr_): x(x_), y(y_), nr(nr_) {
        // pass
    }

    bool operator < (const Point& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};

int main() {
    int T;
    input(T);
    while (T--) {
        int n;
        int x, y;
        vector<Point> points;

        input(n);
        n *= 3;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            points.push_back(Point(x, y, i + 1));
        }

        sort(points.begin(), points.end());

        for (int i = 0; i < n; i += 3) {
            printf("%d %d %d\n", 
                    points[i].nr,
                    points[i + 1].nr,
                    points[i + 2].nr);
        }
    }
    return 0;
}
