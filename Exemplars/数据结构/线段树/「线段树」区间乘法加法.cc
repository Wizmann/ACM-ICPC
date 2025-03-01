/*
已知一个数列，你需要进行下面三种操作：

将某区间每一个数乘上 x；
将某区间每一个数加上 x；
求出某区间每一个数的和。

输入格式
第一行包含三个整数 n,q,m，分别表示该数列数字的个数、操作的总个数和模数。

第二行包含 n 个用空格分隔的整数，其中第 i 个数字表示数列第 i 项的初始值。

接下来 q 行每行包含若干个整数，表示一个操作，具体如下：

操作 1： 格式：1 x y k 含义：将区间 [x,y] 内每个数乘上 k

操作 2： 格式：2 x y k 含义：将区间 [x,y] 内每个数加上 k

操作 3： 格式：3 x y 含义：输出区间 [x,y] 内每个数的和对 m 取模所得的结果

输出格式
输出包含若干行整数，即为所有操作 3 的结果。

题目链接：https://www.luogu.com.cn/problem/P3373
*/

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

int MOD = 19;

class SegmentTree {
    static constexpr int root = 1;

    struct LazyTag {
        llint mul, plus;
    };
public:
    SegmentTree(int m_) : m(m_) {
        tag = vector<LazyTag>(m * 4, {1, 0});
        seg = vector<llint>(m * 4, 0);
    };

    void Plus(int ql, int qr, int k) {
        do_Update(root, 1, m, ql, qr, 1, k);
    }

    void Multiply(int ql, int qr, int k) {
        do_Update(root, 1, m, ql, qr, k, 0);
    }

    int Query(int ql, int qr) {
        return do_Query(root, 1, m, ql, qr);
    }
private:
    inline int left(int x) { return x * 2; }
    inline int right(int x) { return x * 2 + 1; }

    void PushDown(int cur, int l, int r) {
        if (tag[cur].mul != 1 || tag[cur].plus) {
            seg[cur] = ((1LL * seg[cur] * tag[cur].mul) % MOD + tag[cur].plus * (r - l + 1)) % MOD;

            if (l != r) {
                tag[left(cur)].mul = 1LL * tag[left(cur)].mul * tag[cur].mul % MOD;
                tag[right(cur)].mul = 1LL * tag[right(cur)].mul * tag[cur].mul % MOD;
                tag[left(cur)].plus = (1LL * tag[left(cur)].plus * tag[cur].mul) % MOD + tag[cur].plus;
                tag[right(cur)].plus = (1LL * tag[right(cur)].plus * tag[cur].mul) % MOD + tag[cur].plus;
            }

            tag[cur] = {1, 0};
        }
    }

    void do_Update(int cur, int l, int r, int ql, int qr, int mul, int plus) {
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return;
        }

        if (l >= ql && qr >= r) {
            tag[cur].mul = 1LL * tag[cur].mul * mul % MOD;
            tag[cur].plus = (1LL * tag[cur].plus * mul + plus) % MOD;
            PushDown(cur, l, r);
            return;
        }

        assert(l != r);

        do_Update(left(cur), l, (l + r) / 2, ql, qr, mul, plus);
        do_Update(right(cur), (l + r) / 2 + 1, r, ql, qr, mul, plus);
        seg[cur] = (seg[left(cur)] + seg[right(cur)]) % MOD;
    }

    int do_Query(int cur, int l, int r, int ql, int qr) {
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return 0;
        }

        if (l >= ql && qr >= r) {
            return seg[cur];
        }

        assert(l != r);

        llint res = 0;
        res += do_Query(left(cur), l, (l + r) / 2, ql, qr);
        res += do_Query(right(cur), (l + r) / 2 + 1, r, ql, qr);

        return res % MOD;
    }

private:
    int m;

    vector<LazyTag> tag;
    vector<llint> seg;
};

int main() {
    int n, q;
    input(n, q, MOD);

    SegmentTree segTree(n + 1);

    int x;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        segTree.Plus(i, i, x);
        assert(segTree.Query(i, i) == x % MOD);
    }

    int cmd;
    int a, b, c;
    for (int i = 0; i < q; i++) {
        scanf("%d", &cmd);
        
        if (cmd == 1) {
            scanf("%d%d%d", &a, &b, &c);
            segTree.Multiply(a, b, c);
        } else if (cmd == 2) {
            scanf("%d%d%d", &a, &b, &c);
            segTree.Plus(a, b, c);
        } else if (cmd == 3) {
            scanf("%d%d", &a, &b);
            printf("%d\n", segTree.Query(a, b) % MOD);
        } else {
            assert(false);
        }

        /*
        for (int j = 1; j <= n; j++) {
            printf("%d ", segTree.Query(j, j));
        }
        puts("");
        */
    }

    return 0;
}

/*

^^^TEST^^^
5 5 38
1 5 4 2 3
2 1 4 1
3 2 5
1 2 4 2
2 3 5 5
3 1 4
-----
17
2
$$$TEST$$$

*/

