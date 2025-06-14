/*
题目：Luogu P2572 [SCOI2010] 序列操作

题目描述：

lxhgww 最近收到了一个 01 序列，序列里面包含了 n 个数，下标从 0 开始。这些数要么是 0，要么是 1。现在对于这个序列有五种变换操作和询问操作：

* 操作 `0 l r`：把 \[l, r] 区间内的所有数全变成 0；
* 操作 `1 l r`：把 \[l, r] 区间内的所有数全变成 1；
* 操作 `2 l r`：把 \[l, r] 区间内的所有数全部取反，也就是说把所有的 0 变成 1，所有的 1 变成 0；
* 操作 `3 l r`：询问 \[l, r] 区间内总共有多少个 1；
* 操作 `4 l r`：询问 \[l, r] 区间内最多有多少个连续的 1。

对于每一种询问操作，lxhgww 都需要给出回答。聪明的程序员们，你们能帮助他吗？

输入格式：

第一行两个正整数 n 和 m，表示序列长度与操作个数。
第二行包括 n 个数，表示序列的初始状态。
接下来 m 行，每行三个整数，表示一次操作。

输出格式：

对于每一个询问操作，输出一行一个数，表示其对应的答案。

输入输出样例：

输入：
10 10
0 0 0 1 1 0 1 0 1 1
1 0 2
3 0 5
2 2 2
4 0 4
0 3 6
2 3 7
4 2 8
1 0 5
0 5 6
3 3 9

输出：
5
2
6
5

说明/提示：

数据范围：

* 对于 30% 的数据，1 ≤ n, m ≤ 1000；
* 对于 100% 的数据，1 ≤ n, m ≤ 100000。

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

class SegmentTree {
    static constexpr int root = 1;

    struct LazyTag {
        int tag;
        int rev;
        int sum[2];
        int pre[2];
        int suf[2];
        int seq[2];
    };
public:
    SegmentTree(int m_) : m(m_) {
        tag = vector<LazyTag>(m * 4, {0, 0, {0, 0}, {0, 0}, {0, 0}, {0, 0}});
    };

    void Build() {
        do_Build(root, 1, m);
    }

    void Assign(int ql, int qr, int k) {
        return do_Assign(root, 1, m, ql, qr, k);
    }

    void Not(int ql, int qr, int k) {
        return do_Not(root, 1, m, ql, qr, k);
    }

    int Count(int ql, int qr) {
        return do_Count(root, 1, m, ql, qr);
    }

    int Count2(int ql, int qr) {
        int pre = 0;
        int suf = 0;
        int seq = 0;
        do_Count2(root, 1, m, ql, qr, pre, suf, seq);
        return seq;
    }
private:
    inline int left(int x) { return x * 2; }
    inline int right(int x) { return x * 2 + 1; }

    void do_Build(int cur, int l, int r) {
        assert(cur < (int)tag.size());
        tag[cur].tag = -1;
        tag[cur].rev = 0;
        tag[cur].sum[0] = r - l + 1;
        tag[cur].pre[0] = r - l + 1;
        tag[cur].suf[0] = r - l + 1;
        tag[cur].seq[0] = r - l + 1;
        if (l != r) {
            do_Build(left(cur), l, (l + r) / 2);
            do_Build(right(cur), (l + r) / 2 + 1, r);
        }
    }

    void PushDown(int cur, int l, int r) {
        assert(cur < (int)tag.size());
        if (tag[cur].tag != -1) {
            if (l != r) {
                AssignTag(left(cur), l, (l + r) / 2, tag[cur].tag);
                AssignTag(right(cur), (l + r) / 2 + 1, r, tag[cur].tag);
            }
            tag[cur].tag = -1;
        }
        if (tag[cur].rev) {
            if (l != r) {
                NotTag(left(cur));
                NotTag(right(cur));
            }
            tag[cur].rev = 0;
        }
    }

    void PushUp(int cur, int l, int r) {
        assert(cur < (int)tag.size());
        assert(l != r);
        for (int i = 0; i <= 1; i++) {
            tag[cur].sum[i] = tag[left(cur)].sum[i] + tag[right(cur)].sum[i];

            tag[cur].pre[i] = tag[left(cur)].pre[i];
            if (tag[left(cur)].pre[i] == (l + r) / 2 - l + 1) {
                tag[cur].pre[i] = tag[left(cur)].pre[i] + tag[right(cur)].pre[i];
            }

            tag[cur].suf[i] = tag[right(cur)].suf[i];
            if (tag[right(cur)].suf[i] == r - ((l + r) / 2 + 1) + 1) {
                tag[cur].suf[i] = tag[right(cur)].suf[i] + tag[left(cur)].suf[i];
            }

            tag[cur].seq[i] = max(tag[left(cur)].seq[i], tag[right(cur)].seq[i]);
            tag[cur].seq[i] = max(tag[cur].seq[i], tag[left(cur)].suf[i] + tag[right(cur)].pre[i]);
        }
    }

    void AssignTag(int cur, int l, int r, int k) {
        assert(cur < (int)tag.size());
        if (k == 0) {
            tag[cur].tag = 0;
            tag[cur].rev = 0;
            tag[cur].sum[0] = tag[cur].pre[0] = tag[cur].suf[0] = tag[cur].seq[0] = r - l + 1;
            tag[cur].sum[1] = tag[cur].pre[1] = tag[cur].suf[1] = tag[cur].seq[1] = 0;
        } else if (k == 1) {
            tag[cur].tag = 1;
            tag[cur].rev = 0;
            tag[cur].sum[0] = tag[cur].pre[0] = tag[cur].suf[0] = tag[cur].seq[0] = 0;
            tag[cur].sum[1] = tag[cur].pre[1] = tag[cur].suf[1] = tag[cur].seq[1] = r - l + 1;
        } else {
            assert(false);
        }
    }

    void NotTag(int cur) {
        assert(cur >= 0);
        assert(cur < (int)tag.size());
        if (tag[cur].tag != -1) {
            tag[cur].tag ^= 1;
            tag[cur].rev = 0;
        } else {
            tag[cur].rev ^= 1;
        }
        swap(tag[cur].sum[0], tag[cur].sum[1]);
        swap(tag[cur].pre[0], tag[cur].pre[1]);
        swap(tag[cur].suf[0], tag[cur].suf[1]);
        swap(tag[cur].seq[0], tag[cur].seq[1]);
    }

    void do_Assign(int cur, int l, int r, int ql, int qr, int k) {
        assert(cur < (int)tag.size());
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return;
        }

        if (l >= ql && qr >= r) {
            AssignTag(cur, l, r, k);
            return;
        }

        assert(l != r);

        do_Assign(left(cur), l, (l + r) / 2, ql, qr, k);
        do_Assign(right(cur), (l + r) / 2 + 1, r, ql, qr, k);
        PushUp(cur, l, r);
    }

    void do_Not(int cur, int l, int r, int ql, int qr, int k) {
        assert(cur < (int)tag.size());
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return;
        }

        if (l >= ql && qr >= r) {
            NotTag(cur);
            return;
        }

        assert(l != r);

        do_Not(left(cur), l, (l + r) / 2, ql, qr, k);
        do_Not(right(cur), (l + r) / 2 + 1, r, ql, qr, k);
        PushUp(cur, l, r);
    }

    int do_Count(int cur, int l, int r, int ql, int qr) {
        assert(cur < (int)tag.size());
        if (l > qr || r < ql) {
            return 0;
        }

        if (l >= ql && qr >= r) {
            return tag[cur].sum[1];
        }

        PushDown(cur, l, r);

        assert(l != r);

        return do_Count(left(cur), l, (l + r) / 2, ql, qr) +
               do_Count(right(cur), (l + r) / 2 + 1, r, ql, qr);
    }

    void do_Count2(int cur, int l, int r, int ql, int qr, int& pre, int& suf, int& seq) {
        assert(cur < (int)tag.size());
        if (l > qr || r < ql) {
            pre = suf = seq = 0;
            return;
        }

        if (l >= ql && qr >= r) {
            pre = tag[cur].pre[1];
            suf = tag[cur].suf[1];
            seq = tag[cur].seq[1];
            return;
        }

        PushDown(cur, l, r);

        assert(l != r);

        int mid = (l + r) / 2;
        if (qr <= mid) {
            do_Count2(left(cur), l, mid, ql, qr, pre, suf, seq);
            return;
        } else if (ql > mid) {
            do_Count2(right(cur), mid + 1, r, ql, qr, pre, suf, seq);
            return;
        }

        int pre1 = 0, suf1 = 0, seq1 = 0;
        do_Count2(left(cur), l, mid, ql, qr, pre1, suf1, seq1);

        int pre2 = 0, suf2 = 0, seq2 = 0;
        do_Count2(right(cur), mid + 1, r, ql, qr, pre2, suf2, seq2);

        pre = pre1;
        suf = suf2;
        seq = max(seq1, seq2);
        
        if (pre1 == mid - l + 1) {
            pre = pre1 + pre2;
        }

        if (suf2 == r - (mid + 1) + 1) {
            suf = suf2 + suf1;
        }

        seq = max(seq, suf1 + pre2);
    }

private:
    int m;

    vector<LazyTag> tag;
    vector<int> seg;
};

int main() {
    int n, m;
    input(n, m);

    SegmentTree segTree(n);
    segTree.Build();
    int a, b, c;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        segTree.Assign(i, i, a);
    }

    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        b++;
        c++;
        if (a == 0) {
            segTree.Assign(b, c, 0);
        } else if (a == 1) {
            segTree.Assign(b, c, 1);
        } else if (a == 2) {
            segTree.Not(b, c, 1);
        } else if (a == 3) {
            printf("%d\n", segTree.Count(b, c));
        } else if (a == 4) {
            printf("%d\n", segTree.Count2(b, c));
        } else {
            assert(false);
        }

        // for (int i = 1; i <= n; i++) {
        //     printf("%d ", segTree.Count(i, i));
        // }
        // puts("");
    }
    return 0;
}

/*

^^^^^^TEST^^^^
10 10
0 0 0 1 1 0 1 0 1 1
1 0 2
3 0 5
2 2 2
4 0 4
0 3 6
2 3 7
4 2 8
1 0 5
0 5 6
3 3 9
----------
5
2
6
5
$$$$$$TEST$$$$$

*/
