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

int q;
llint k;

struct Interval {
    llint l, r;
    int cnt;

    bool operator < (const Interval& other) const {
        return r + k < other.l;
    }
};

struct Query {
    int cmd;
    llint value;
};

int lowbit(int x) { return x & (-x); }

template <typename T>
class BIT
{
public:
    BIT() {}
    BIT(int n_) : n(n_), nums(n + 1) {}

    void add(int x, T val) {
        while(x < n) {
            nums[x] += val;
            x += lowbit(x);
        }
    }

    T sum(int x) {
        T res = 0;
        while(x > 0) {
            res += nums[x];
            x -= lowbit(x);
        }
        return res;
    }

    T sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int n;
    vector<T> nums;
};


int main() {
    input(q, k);

    set<Interval> intervals;
    set<llint> st;

    vector<Query> qs(q);

    map<llint, int> mp;

    int cmd;
    llint v;
    for (int i = 0; i < q; i++) {
        scanf("%d%lld", &cmd, &v);
        qs[i] = { cmd, v };
        mp[v] = -1;
    }

    int idx = 1;
    for (auto& p : mp) {
        p.second = idx++;
    }

    BIT<int> bit(mp.size() + 1);

    for (int i = 0; i < q; i++) {
        cmd = qs[i].cmd;
        v = qs[i].value;
        int u = mp[v];
        if (cmd == 1) {
            if (st.count(v)) {
                bit.add(u, -1);

                auto it = intervals.find({v, v, -1});
                assert(it != intervals.end());
                auto cur = *it;
                intervals.erase(it);
                st.erase(st.find(v));

                if (v == cur.l) {
                    auto it2 = st.lower_bound(v);
                    if (it2 == st.end()) {
                        // pass
                    } else {
                        if (*it2 <= cur.r) {
                            cur.l = *it2;
                            cur.cnt--;
                            assert(cur.cnt == bit.sum(mp[cur.l], mp[cur.r]));
                            intervals.insert(cur);
                        }
                    }
                } else if (v == cur.r) {
                    auto it2 = st.lower_bound(v);
                    if (it2 == st.begin()) {
                        // pass
                    } else {
                        --it2;
                        if (*it2 >= cur.l) {
                            cur.r = *it2;
                            cur.cnt--;
                            assert(cur.cnt == bit.sum(mp[cur.l], mp[cur.r]));
                            intervals.insert(cur);
                        }
                    }
                } else {
                    auto it2 = st.lower_bound(v);
                    llint r = *it2;
                    llint l = *(--it2);
                    if (r - l <= k) {
                        cur.cnt--;
                        intervals.insert(cur);
                    } else {
                        assert(mp.count(cur.l));
                        assert(mp.count(cur.r));
                        assert(mp.count(l));
                        assert(mp.count(r));

                        Interval nxt1 = {cur.l, l, bit.sum(mp[cur.l], mp[l])};
                        Interval nxt2 = {r, cur.r, bit.sum(mp[r], mp[cur.r])};
                        assert(nxt1.cnt == bit.sum(mp[nxt1.l], mp[nxt1.r]));
                        assert(nxt2.cnt == bit.sum(mp[nxt2.l], mp[nxt2.r]));
                        intervals.insert(nxt1);
                        intervals.insert(nxt2);
                    }
                }
            } else {
                bit.add(u, 1);
                Interval cur = {v, v, 1};

                while (true) {
                    auto it = intervals.find(cur);

                    if (it == intervals.end()) {
                        break;
                    }

                    cur.l = min(cur.l, it->l);
                    cur.r = max(cur.r, it->r);
                    cur.cnt += it->cnt;

                    intervals.erase(it);
                }

                intervals.insert(cur);
                st.insert(v);
            }
        } else if (cmd == 2) {
            if (st.count(v) == 0) {
                assert(false);
                puts("0");
            } else {
                auto it = intervals.find({v, v, -1});
                assert(it != intervals.end());
                assert(it->l <= v && it->r >= v);
                printf("%d\n", it->cnt);
            }
        } else {
            assert(false);
        }
    }

    return 0;
}

/*

^^^TEST^^^
7 5
1 3
1 10
2 3
1 7
2 3
1 10
2 3
-----
1
3
2
$$$TEST$$$

^^^TEST^^^
11 1000000000000000000
1 1
1 100
1 10000
1 1000000
1 100000000
1 10000000000
1 1000000000000
1 100000000000000
1 10000000000000000
1 1000000000000000000
2 1
-----
10
$$$TEST$$$

^^^TEST^^^
8 0
1 1
1 2
2 1
1 1
1 2
1 1
1 2
2 1
-----
1
1
$$$TEST$$$

*/
