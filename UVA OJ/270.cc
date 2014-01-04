//Result: 270   Lining Up   Accepted    C++ 1.675   2013-12-23 07:33:14
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x 

const int SIZE = 720;

struct point
{
    int x, y;
    point(){}
    point(int ix, int iy) : x(ix), y(iy) {}
};

vector<point> vec;
char str[SIZE];

int gcd(int x, int y)
{
    if (x % y == 0) return y;
    else return gcd(y, x % y);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d\n", &T);
    int a, b;

    while (T--) {
        vec = vector<point>();
        while (gets(str) && strlen(str)) {
            sscanf(str, "%d%d", &a, &b);
            vec.push_back(point(a, b));
        }

        int n = vec.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> mp;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int dx = vec[i].x - vec[j].x;
                int dy = vec[i].y - vec[j].y;

                int s = dx * dy > 0? 1 : -1;
                dx = abs(dx);
                dy = abs(dy);
                if (dx == 0 && dy != 0) {
                    dy = s;
                } else if (dy == 0 && dx != 0) {
                    dx = s;
                } else if (dx == 0 && dy == 0) {
                    /* PASS */
                } else {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;
                    dx *= s;
                }
                pair<int, int> p = make_pair<int, int>(int(dx), int(dy));

                mp[p]++;

                if (mp[p] > ans) {
                    ans = mp[p];
                }
            }
        }
        print(ans + 1);
        if (T) puts("");
    }
    return 0;
}
