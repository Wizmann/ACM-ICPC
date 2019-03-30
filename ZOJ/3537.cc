#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

struct CPoint {
    int x, y;
};

const int N = 333;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;

int dp[N][N];

class Solution {
public:
    Solution(int n_, int p_) : n(n_), p(p_) {
        // pass
    }

    void add_point(int x, int y) {
        points.push_back({x, y});
    }

    llint solve() {
        memset(dp, -1, sizeof(dp));

        llint ans = do_solve(0, n - 1);
        if (ans == INF) {
            return 0;
        }
        return ans;
    }

    llint cost(int a, int b) {
        if (diff(a, b) <= 2) {
            return 0;
        }
        return 1LL * abs(points[a].x + points[b].x) * abs(points[a].y + points[b].y) % p;
    }

    int diff(int l, int r) {
        return ((r - l) % n + n) % n + 1;
    }

    llint do_solve(int l, int r) {
        assert(l >= 0 && l < n);
        assert(r >= 0 && r < n);

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        if (diff(l, r) < 3) {
            return INF;
        }

        if (diff(l, r) == 3) {
            return 0;
        }

        llint ans = INF;
        for (int i = l; i % n != r; i++) {
            int ii = i % n;
            if (diff(l, ii) < 2 || diff(ii, r) < 2) {
                continue;
            }
            llint res = 0;
            res += cost(l, ii);
            res += cost(ii, r);
            if (diff(l, ii) >= 3) {
                res += do_solve(l, ii);
            }
            if (diff(ii, r) >= 3) {
                res += do_solve(ii, r);
            }
            ans = min(res, ans);
        }
        return dp[l][r] = ans;
    }
private:
    int n, p;
    vector<CPoint> points;
};

class ConvexHull {
public:
    double xmult(CPoint sp, CPoint ep, CPoint op) {
        return ((sp.x - op.x) * (ep.y - op.y) - (sp.y - op.y) * (ep.x - op.x));
    }

    double pntDis(const CPoint& p1, const CPoint& p2) {
        return sqrt(1.0 * (p1.x - p2.x) * (p1.x - p2.x) + 1.0 * (p1.y - p2.y) * (p1.y - p2.y));
    }

    bool cmp(CPoint p1, CPoint p2) {
        if (xmult(p1, p2, points[0]) > 0) {
            return true;
        } else if (xmult(p1, p2, points[0]) == 0 && pntDis(p1, points[0]) < pntDis(p2, points[0])) {
            return true;
        } else {
            return false;
        }
    }

    void add_point(int x, int y) {
        points.push_back({x, y});
    }

    int findtop() {
        int res = 0;
        for(int i = 1; i < points.size(); i++) {
            if (points[i].y < points[res].y) {
                res = i;
            } else if(points[i].y == points[res].y && points[i].x < points[res].x) {
                res=i;
            }
        }
        return res;
    }

    const vector<CPoint> graham() {
        int top = findtop();
        pstack.push_back(points[top]);
        swap(points[0], points[top]);
        sort(points.begin() + 1, points.end(), [&](CPoint p1, CPoint p2) -> bool {
            if (xmult(p1, p2, points[0]) > 0) {
                return true;
            } else if (xmult(p1, p2, points[0]) == 0 && pntDis(p1, points[0]) < pntDis(p2, points[0])) {
                return true;
            } else {
                return false;
            }
        });

        pstack.push_back(points[1]);
        pstack.push_back(points[2]);
        for(int i = 3; i < points.size(); i++) {
            while (xmult(points[i], pstack[pstack.size() - 1], pstack[pstack.size() - 2]) >= 0) {
                pstack.pop_back();//有等号时，不包括点都在一条直线的情况
            }
            pstack.push_back(points[i]);
        }
        return pstack;
    }
private:
    vector<CPoint> points;
    vector<CPoint> pstack;
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, p;

    int a, b;
    while (input(n >> p)) {
        auto C = ConvexHull();
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            C.add_point(a, b);
        }
        const auto& points = C.graham();
        if (points.size() != n) {
            puts("I can't cut.");
        } else {

            auto S = Solution(points.size(), p);
            for (auto p: points) {
                S.add_point(p.x, p.y);
            }
            print(S.solve());
        }
    }
    return 0;
}
