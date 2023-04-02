#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

struct Event {
    int p, t;
};

class MiniSum {
public:
    MiniSum(int top_) {
        top = top_;
    }

    void Add(int x) {
        if (!st1.empty() && x <= *st1.rbegin()) {
            st1.insert(x);
            top_sum += x;
        } else {
            st2.insert(x);
        }
        Adjust();
    }

    void Update(int u, int v) {
        if (st1.find(u) != st1.end()) {
            st1.erase(st1.find(u));
            top_sum -= u;
            Add(v);
        } else if (st2.find(u) != st2.end()) {
            st2.erase(st2.find(u));
            Add(v);
        } else {
            assert(false);
        }
        Adjust();
    }

    llint GetSum() {
        return top_sum;
    }
private:
    void Adjust() {
        while (st1.size() > top) {
            auto iter = --st1.end();
            st2.insert(*iter);
            top_sum -= *iter;
            st1.erase(iter);
        }

        while (!st2.empty() && st1.size() < top) {
            auto iter = st2.begin();
            st1.insert(*iter);
            top_sum += *iter;
            st2.erase(iter);
        }
    }


private:
    size_t top = 0;
    llint top_sum = 0;
    multiset<int> st1, st2;
};

int n, k, x, d, m;
vector<Event> events;

int solve() {
    vector<int> p(n + 1, 0);
    MiniSum ps(k);

    for (int i = 1; i <= n; i++) {
        ps.Add(0);
    }

    int res = INF;
    int cur = 0;
    for (auto& e : events) {
        if (e.t != cur && e.p > 0 && e.t >= x) {
            res = min<int>(res, ps.GetSum());
        }

        if (e.p == INF) {
            break;
        }

        if (e.p > 0) {
            int pre = p[e.p];
            p[e.p]++;
            ps.Update(pre, pre + 1);
        } else {
            int pre = p[-e.p];
            p[-e.p]--;
            ps.Update(pre, pre - 1);
        }

        if (e.p > 0) {
            cur = e.t;
        }
    }
    return res;
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        input(n, k, x, d);

        input(m);
        events.clear();

        int p, l, r;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &p, &l, &r);

            events.push_back({p, l});
            events.push_back({-p, r + x});
        }
        events.push_back({INF, d});

        sort(events.begin(), events.end(),
            [](const Event& e1, const Event& e2) {
                if (e1.t != e2.t) {
                    return e1.t < e2.t;
                }
                return e1.p < e2.p;
            });

        int res = solve();
        printf("Case #%d: %d\n", case_ + 1, res);
    }

    return 0;
}

/*
 *
^^^TEST^^^
1
3 3 2 6
5
1 3 5
2 1 3
2 2 6
3 0 1
3 3 6
---------
Case #1: 2
$$$TEST$$$$

^^^TEST^^^
3
3 2 2 6
5
1 3 5
2 1 3
2 2 6
3 0 1
3 3 6
3 3 2 6
5
1 3 5
2 1 3
2 2 6
3 0 1
3 3 6
3 2 3 6
5
1 3 5
2 1 3
2 2 6
3 0 1
3 3 6
-----
Case #1: 0
Case #2: 2
Case #3: 1
$$$TEST$$$

*/
