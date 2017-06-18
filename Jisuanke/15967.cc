#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int HASH = 299;

struct Point {
    int x, y;
    
    int hash() {
        return y * HASH + x;
    }
};

struct Segment {
    int nr;
    Point a, b;
};

int n, m;
vector<Segment> segments;
map<int, int> mp;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

void calc_int_points(const Segment& seg) {
    int y = seg.a.y - seg.b.y;
    int x = seg.a.x - seg.b.x;

    int g = abs(gcd(y, x));

    for (int i = 0; i <= g; i++) {
        int yy = i * y / g;
        int xx = i * x / g;
        Point p = {xx + seg.b.x, yy + seg.b.y};
        mp[p.hash()] = seg.nr;
    }
}

int main() {    
    input(n >> m);
    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        segments.push_back({i + 1, {a, b}, {c, d}});
    }

    for (auto seg: segments) {
        calc_int_points(seg);
    }

    int q;
    input(q);
    while (q--) {
        scanf("%d%d", &a, &b);
        Point p = {a, b};
        printf("%d\n", mp[p.hash()]);
    }
    return 0;
}
