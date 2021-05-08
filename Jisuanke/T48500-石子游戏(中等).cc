#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int INF = 0x3f3f3f3f;
const int M = 64;
const int LOGN = 20;
const int SIZE = 1234567;
const int QUERY = 51234;

class BITree {
public:
    BITree() {}
    BITree(size_t size_): _size(size_ + 100) {
        _bitree = vector<int>(_size, 0);
    }

    void add(int pos, int value) {
        while (pos < _size) {
            _bitree[pos] += value;
            pos += lowbit(pos);
        }
    }

    int sum(int pos) {
        int res = 0;
        while (pos > 0) {
            res += _bitree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    int sum(size_t a, size_t b) {
        return sum(b) - sum(a - 1);
    }
private:
    int lowbit(int x) {
        return x & (-x);
    }
private:
    vector<int> _bitree;
    size_t _size;
};

template <typename T, class Compare=less<int> >
class BITreeRMQ {
public:
    BITreeRMQ() {}
    BITreeRMQ(int n_, const vector<T>& nums_) : n(n_), nums(nums_), tree(nums_) {
        assert(nums.size() == n);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < lowbit(i); j <<= 1) {
                tree[i] = cmp(tree[i], tree[i - j]);
            }
        }
    }

    T query(int a, int b) {
        T ans = nums[b];
        while(a != b) {
            for (b = b - 1; b - lowbit(b) >= a; b -= lowbit(b)) {
                ans = cmp(ans, tree[b]);
            }
            ans = cmp(ans, nums[b]);
        }
        return ans;
    }

    void modify(int pos, T val) {
        nums[pos] = val;
        for(int i = pos; i < n; i += lowbit(i)) {
            tree[i] = nums[i];
            for(int j = 1; j < lowbit(i); j <<= 1) {
                tree[i] = min(tree[i], tree[i - j]);
            }
        }
    }
private:
    T cmp(T a, T b) {
        return cmp_func(a, b)? a: b;
    }

    inline int lowbit(int x) {
        return x&(-x);
    }

    vector<T> tree;
    vector<T> nums;
    Compare cmp_func = Compare();
    int n;
};

struct Stone {
    int a, v;
};

int n, m, q;

BITreeRMQ<int, greater<int> > rmqs;
BITreeRMQ<int, less<int> >    rmqs2;
BITree bitrees;
BITree bitrees2;

vector<int> ans[QUERY];

void solve(const vector<Stone>& stones, int idx, int v, int l, int r, int x) {
    vector<int> dis[2];

    dis[0] = ans[idx];

    int p = 0;
    dis[1] = vector<int>(m, -INF);
    {
        auto maxp = rmqs.query(l, r);
        auto minp = rmqs2.query(l, r);

        auto maxi = maxp;
        auto mini = minp;

        auto toti = bitrees.sum(l, r) - maxi - mini;
        int cnti = bitrees2.sum(l, r);
        
        vector<Stone> newstones;

        if (maxi != -INF && cnti >= 1) {
            newstones.push_back({v, maxi});
        }
        if (mini != INF && cnti >= 2) {
            newstones.push_back({v, mini});
        }
        if (cnti >= 3) {
            cnti -= 2;
            newstones.push_back({cnti % 2 == 0? 0: v, toti});
        }

        if (!newstones.empty()) {
            for (auto stone: newstones) {
                int q = p ^ 1;
                fill(dis[q].begin(), dis[q].end(), -INF);
                for (int j = 0; j < m; j++) {
                    if (dis[p][j] >= 0) {
                        dis[q][j] = max(dis[q][j], dis[p][j]);

                        int u = j ^ stone.a;
                        assert(0 <= u && u < m);
                        dis[q][u] = max(dis[q][u], dis[p][j] + stone.v);
                    }
                }
                p = q;
            }
        } else {
            int q = p ^ 1;
            fill(dis[q].begin(), dis[q].end(), -INF);
            for (int j = 0; j < m; j++) {
                if (dis[p][j] >= 0) {
                    dis[q][j] = max(dis[q][j], dis[p][j]);
                }
            }
            p = q;
        }

    }
    ans[idx] = dis[p];
}

unsigned int getans(int x, int idx) {
    unsigned int tot = 0;
    for (int i = 0; i < m; i++) {
        int cur = ans[idx][i];
        if (cur < 0) {
            cur = -1;
        }
        // printf("%d %d %d\n", idx, i, cur);
        cur *= x ^ i;
        tot += (unsigned int)cur;
    }
    return tot ^ (unsigned int)(idx + 1);
}

struct Query {
    int a, b, c;
};

int main() {
    input(n >> m >> q);

    vector<Stone> stones(n + 1);

    int a, b, c;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        stones[i] = {a, b};
    }

    vector<Query> qs;

    unsigned int res = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d", &a, &b, &c);
        qs.push_back({a, b, c});

        ans[i] = vector<int>(m, -INF);
        ans[i][0] = 0;
    }

    for (int i = 0; i < m; i++) {
        vector<int> ms(n + 1, -INF);
        bitrees = BITree(n + 1);
        bitrees2 = BITree(n + 1);
        for (int j = 1; j <= n; j++) {
            if (stones[j].a == i) {
                ms[j] = stones[j].v;
                bitrees.add(j, stones[j].v);
                bitrees2.add(j, 1);
            }
        }

        rmqs = BITreeRMQ<int, greater<int> >(n + 1, ms);
        for (int j = 1; j <= n; j++) {
            if (ms[j] == -INF) {
                ms[j] = INF;
            }
        }
        rmqs2 = BITreeRMQ<int, less<int> >(n + 1, ms);

        for (int j = 0; j < q; j++) {
            const auto& q = qs[j];
            solve(stones, j, i, q.a + 1, q.b + 1, q.c);
        }
    }

    for (int i = 0; i < q; i++) {
        res += getans(qs[i].c, i);
    }

    print(res);


    return 0;
}

/*
^^TEST^^
5 8 5
3 5
0 1
1 8
5 3
0 9
3 4 2
3 3 1
1 2 3
0 1 7
1 4 7
---
340
$$TEST$$

^^TEST^^
10 64 5
22 168
42 986
59 17
59 162
59 477
59 638
53 1188
53 855
53 626
53 878
2 9 28994501
1 9 59288943
3 9 99304514
1 9 51072664
0 9 4383713
--
380158232
$$TEST$$

^^TEST^^
20 4 20
2 7
3 77
1 79
3 88
3 105
2 79
0 107
1 76
3 103
2 23
1 76
0 28
1 116
0 96
1 26
2 10
2 50
2 82
1 118
3 97
0 1 47133441
5 7 18969419
1 6 2422740
5 10 53208222
6 14 87688691
8 17 42621943
6 6 77855857
4 6 48153610
9 18 3897132
3 7 6464327
1 5 38656595
3 11 28834712
9 14 44578879
5 8 94127076
4 11 79891594
7 16 42457664
3 3 38169881
4 5 20978789
8 12 60428499
4 10 7566734
--
2137762174
$$TEST$$

^^TEST^^
9 4 1
3 88
3 105
2 79
0 107
1 76
3 103
2 23
1 76
0 28
0 8 47133441
---
72591827
$$TEST$$
*/
