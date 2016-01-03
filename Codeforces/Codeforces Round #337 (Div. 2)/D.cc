#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 666666;
const int INF = 0x3f3f3f3f;

inline int lowbit(int x) { return x & (-x); }

struct BIT//点更新，区间查询
{
    llint baum[SIZE];
    inline void init()
    {
        memset(baum,0,sizeof(baum));
    }
    void add(int x,int val)
    {
        while(x<SIZE)
        {
            baum[x]+=val;
            x+=lowbit(x);
        }
    }
    llint sum(int x)
    {
        llint res=0;
        while(x>0)
        {
            res+=baum[x];
            x-=lowbit(x);
        }
        return res;
    }
    llint sum(int a,int b)//查询区间和
    {
        return sum(b)-sum(a-1);
    }
};

struct Point {
    int x, y;
};

struct Node {
    int idx;
    int cmd; // 0 - query, 1 - add, 2 - remove

    int l;
    int r;

    bool operator < (const Node& node) const {
        if (idx != node.idx) {
            return idx < node.idx;
        }
        return cmd > node.cmd;
    }
};



int n;
llint ans;
vector<pair<Point, Point> > segments;

map<int, int> map_xy;
map<int, int> map_re;

vector<pair<int, int> > para[SIZE];
vector<pair<int, int> > hori[SIZE];

void do_clean_data(vector<pair<int, int> >& s) {
    s.push_back({INF, INF});
    vector<pair<int, int> > res;
    int pre = -1;
    int st = -1;
    for (const auto& seg: s) {
        if (seg.first > pre) {
            if (pre != -1) {
                res.push_back({st, pre});
            }
            st = seg.first;
            pre = seg.second;
        } else {
            pre = max(pre, seg.second);
        }
    }
    s = res;
    for (const auto& seg: s) {
        llint l = map_re[seg.first];
        llint r = map_re[seg.second];

        ans += r - l + 1;
    }
}

void clean_data() {
    for (int i = 0; i < SIZE; i++) {
        sort(para[i].begin(), para[i].end());
        do_clean_data(para[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        sort(hori[i].begin(), hori[i].end());
        do_clean_data(hori[i]);
    }
}

int main() {
    int a, b, c, d;
    ans = 0;
    input(n);
    map<int, int> map_xy;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        segments.push_back({
            {a, b}, {c, d}
        });
        map_xy.insert({a, -1});
        map_xy.insert({a + 1, -1});
        map_xy.insert({a - 1, -1});
        map_xy.insert({c, -1});
        map_xy.insert({c + 1, -1});
        map_xy.insert({c - 1, -1});
        map_xy.insert({b, -1});
        map_xy.insert({b + 1, -1});
        map_xy.insert({b - 1, -1});
        map_xy.insert({d, -1});
        map_xy.insert({d + 1, -1});
        map_xy.insert({d - 1, -1});
    }

    {
        int idx = 1;
        for (auto& p: map_xy) {
            p.second = idx++;
        }

        for (auto& p: map_xy) {
            map_re[p.second] = p.first;
        }
    }

    for (auto& p: segments) {
        auto& p1 = p.first;
        auto& p2 = p.second;

        p1.x = map_xy[p1.x];
        p1.y = map_xy[p1.y];

        p2.x = map_xy[p2.x];
        p2.y = map_xy[p2.y];
    }

    for (const auto& p: segments) {
        const auto& p1 = p.first;
        const auto& p2 = p.second;

        if (p1.x == p2.x) {
            hori[p1.x].push_back({min(p1.y, p2.y), max(p1.y, p2.y)});
        } else {
            para[p1.y].push_back({min(p1.x, p2.x), max(p1.x, p2.x)});
        }
    }

    clean_data();

    multiset<Node> st;
    for (int i = 0; i < SIZE; i++) {
        for (const auto& seg: para[i]) {
            st.insert({seg.first,  1, i, i});
            st.insert({seg.second + 1, 2, i, i});
        }

        for (const auto& seg: hori[i]) {
            st.insert({i, 0, seg.first, seg.second});
        }
    }

    BIT bitree;
    bitree.init();
    for (auto node: st) {
        if (node.cmd == 0) {
            ans -= bitree.sum(node.l, node.r);
        } else if (node.cmd == 2) {
            bitree.add(node.l, -1);
        } else {
            bitree.add(node.l, 1);
        }
    }

    print(ans);

    return 0;
}
