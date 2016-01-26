#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

bool OK = false;

struct Datetime {
    int yy, mm, dd;

    Datetime(int y, int m, int d): yy(y), mm(m), dd(d) {}
    int to_int() {
        return yy * 10000 + mm * 100 + dd;
    }

    // the input time should be later than the current one
    bool ge_one_nature_month(const Datetime& dt) {
        int a = yy * 100 + mm;
        int b = dt.yy * 100 + dt.mm;

        if (b - a > 1) {
            return true;
        }
        if (b - a == 1) {
            return dd <= dt.dd;
        }
        return false;
    }
};

struct Timestamp {
    int stamp;
    int cmd;

    friend bool operator < (const Timestamp& ts1, const Timestamp& ts2) {
        if (ts1.stamp != ts2.stamp) {
            return ts1.stamp < ts2.stamp;
        }
        return ts1.cmd > ts2.cmd;
    }
};

void test() {
    assert(Datetime(2010, 1, 1).ge_one_nature_month(Datetime(2010, 2, 1)));
    assert(!Datetime(2010, 1, 2).ge_one_nature_month(Datetime(2010, 2, 1)));
    assert(Datetime(2010, 12, 31).ge_one_nature_month(Datetime(2011, 12, 31)));
    assert(Timestamp({1, 2}) < Timestamp({2, 3}));
}

int n, q;
vector<Timestamp> tsvec;
map<int, vector<int> > mp;

void prepare() {
    sort(tsvec.begin(), tsvec.end());
    tsvec.push_back({INF, -1});
    unordered_set<int> st;

    int pre = -1;
    for (auto& item: tsvec) {
        int s = item.stamp;
        if (pre != s && pre != -1) {
            mp[pre] = vector<int>();
            copy(st.begin(), st.end(), back_inserter(mp[pre]));
            sort(mp[pre].begin(), mp[pre].end());
        }
        pre = s;
        if (s == INF) {
            break;
        }
        
        int idx = item.cmd;
        if (idx > 0) {
            st.insert(idx);
        } else {
            st.erase(st.find(abs(idx)));
        }
    }
    mp[INF] = vector<int>();
}

void get_result(int ts) {
    auto iter = mp.upper_bound(ts);
    if (iter == mp.begin()) {
        puts("0");
        return;
    }
    --iter;
    printf("%d", (int)iter->second.size());
    for (auto i: iter->second) {
        printf(" %d", i);
    }
    if (iter->second.size() > 200) {
        OK = false;
    }
    puts("");
}

int main() {
    test();
    input(n);

    for (int i = 0; i < n; i++) {
        int y1, m1, d1;
        int y2, m2, d2;
        int idx;

        scanf("%d%d%d", &y1, &m1, &d1);
        scanf("%d%d%d", &y2, &m2, &d2);
        scanf("%d", &idx);

        auto D1 = Datetime(y1, m1, d1);
        auto D2 = Datetime(y2, m2, d2);

        OK = true;

        if (!D1.ge_one_nature_month(D2)) {
            // OK = true;
            continue;
        }

        tsvec.push_back({D1.to_int(), idx});
        tsvec.push_back({D2.to_int() + 1, -idx});
    }

    prepare();

    input(q);
    while (q--) {
        int y, m, d;
        scanf("%d%d%d", &y, &m, &d);
        auto D = Datetime(y, m, d);
        get_result(D.to_int());
    }
    return 0;
}
