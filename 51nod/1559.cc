#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 100011;

struct BiTreeRMQ
{
    int baum[SIZE],num[SIZE];
    inline int lowbit(int x)
    {
        return x&(-x);
    }
    void init()
    {
        for(int i=1;i<SIZE;i++)
        {
            baum[i]=num[i];
            for(int j=1;j<lowbit(i);j<<=1)
            {
                baum[i]=min(baum[i],baum[i-j]);
            }
        }
    }
    int query(int a,int b)
    {
        int ans=num[b];
        while(a != b)
        {
            for (b = b - 1; b - lowbit(b) >= a; b -= lowbit(b))
            {
                ans=min(ans,baum[b]);
            }
            ans = min(ans, num[b]);
        }
        return ans;
    }

    void modify(int pos,int val)
    {
        num[pos]=val;
        for(int i=pos;i<SIZE;i+=lowbit(i))
        {
            baum[i]=num[i];
            for(int j=1;j<lowbit(i);j<<=1)
            {
                baum[i]=min(baum[i],baum[i-j]);
            }
        }
    }
};

struct Point {
    int y;
    int x;
};

struct Zone {
    int y1;
    int x1;
    int y2;
    int x2;
};

enum ActionType {
    POINT = 0,
    ZONE_ENTER = 1,
    ZONE_LEAVE = 2,
};


struct Action {
    ActionType type;
    int nr;
    int cmp;
};

class Solution {
public:
    Solution(int n_, int m_, int k_, int q_): 
            n(n_), m(m_), k(k_), q(q_) {
        // pass
    }

    void add_point(int y, int x) {
        assert(1 <= y && y <= n);
        assert(1 <= x && x <= m);
        points.push_back({y, x});
    }

    void add_zone(int y1, int x1, int y2, int x2) {
        assert(1 <= y1 && y1 <= n);
        assert(1 <= y2 && y2 <= n);
        assert(1 <= x1 && x1 <= m);
        assert(1 <= x2 && x2 <= m);
        zones.push_back({y1, x1, y2, x2});
    }

    set<int> solve() {
        set<int> res;
        actions.reserve(n + m);
        for (int i = 0; i < k; i++) {
            actions.push_back({POINT, i, points[i].y});
        }

        for (int i = 0; i < q; i++) {
            actions.push_back({ZONE_LEAVE, i, zones[i].y2});
        }

        sort(actions.begin(), actions.end(), 
            [](const Action& aa, const Action& ab) {
                if (aa.cmp != ab.cmp) {
                    return aa.cmp < ab.cmp;
                } else {
                    return aa.type < ab.type;
                }
        });

        BiTreeRMQ tree;
        
        for (int i = 0; i < SIZE; i++) {
            tree.num[i] = 0;
        }
        
        tree.init();

        for (const auto& action: actions) {
            if (action.type == POINT) {
                const auto& p = points[action.nr];
                tree.modify(p.x, p.y);
            } else if (action.type == ZONE_LEAVE) {
                const auto& z = zones[action.nr];
                int mini = tree.query(z.x1, z.x2);
                if (z.y2 >= mini && mini >= z.y1) {
                    res.insert(action.nr);
                }
            } else {
                print("fuck");
            }
        }
        return res;
    }
private:
    vector<Point> points;
    vector<Zone>  zones;
    vector<Action> actions;
    int n, m, k, q;
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, m, k, q;
    input(m >> n >> k >> q);
    Solution S1(n, m, k, q);
    Solution S2(m, n, k, q);

    int a, b, c, d;
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        S1.add_point(b, a);
        S2.add_point(a, b);
    }

    for (int i = 0; i < q; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        S1.add_zone(b, a, d, c);
        S2.add_zone(a, b, c, d);
    }
    
    
    auto r1 = S1.solve();
    auto r2 = S2.solve();

    r1.insert(r2.begin(), r2.end());

    for (int i = 0; i < q; i++) {
       if (r1.count(i) == 0) {
           puts("NO");
        } else {
           puts("YES");
        }
    }
    return 0;
}
