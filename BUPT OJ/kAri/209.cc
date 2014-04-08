// Result: 3443 209  通过 1785 ms 1064 KB GNU C++  2493 B 2014-03-18 21:01:01 test#wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

#define pii pair<int, int>
#define mpii(a, b) make_pair<int, int>(int(a), int(b))


struct Point {
    int x, y;
    Point(){}
    Point(int ix, int iy): x(ix), y(iy){}
};

int gcd(int a, int b)
{
    if (a % b == 0) return b;
    else {
        return gcd(b, a % b);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T, a, b, n;
    input(T);

    vector<Point> points;
    points.reserve(1024);

    while (T--) {
        input(n);
        points.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            points.push_back(Point(a, b));
        }
        bool flag = false;
        try {
            for (int i = 0; i < n; i++) {
                vector<pair<int, int> > vp;
                for (int j = i + 1; j < n; j++) {
                    int dy = points[i].y - points[j].y;
                    int dx = points[i].x - points[j].x;

                    if (!dy && !dx) continue;
                    pii p;
                    if (!dy) {
                        p = mpii(0, 1);
                    } else if (!dx) {
                        p = mpii(1, 0);
                    } else {
                        int sig = dx * dy >= 0? 1: -1;
                        dx = abs(dx);
                        dy = abs(dy);
                        int g = gcd(dx, dy);
                        dx /= g; dy /= g;
                        p = mpii(dy * sig, dx);
                    }
                    vp.push_back(p);                  
                }
                sort(vp.begin(), vp.end());
                for (int j = 0; j + 1 < vp.size(); j++) {
                    //print (j + 1 << ' '<< vp.size());
                    if (vp[j] == vp[j + 1]) {
                        flag = true;
                        throw flag;
                    }
                }
            }
        } catch(...) {
            // pass
        }

        if (flag) {
            puts("Yummy! Thanks, study brothers memeda!");
        } else {
            puts("T_T, long live my slim figure!");
        }
    }
    //printf("%.4lf\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}


