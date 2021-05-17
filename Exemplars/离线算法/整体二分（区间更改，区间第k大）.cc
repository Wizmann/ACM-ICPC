#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

const int N = 55555;

inline int lowbit(int x)
{
    return x&(-x);
}

class BITree { // 点更新，点查询
public:
    BITree() {}
    BITree(int n_): n(n_), tree(n + 1, 0) {}

    void add(int pos, int val) {
        while (pos < n) {
            tree[pos] += val;
            pos += lowbit(pos);
        }
    }

    int sum(int pos) {
        int res = 0;
        while (pos > 0) {
            res += tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    int sum(int a ,int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int n;
    vector<int> tree;
};

class SegBIT { // 区间更新，点查询
public:
    SegBIT() {}
    SegBIT(int n_): n(n_), tree(n + 1, 0) {}

    void add(int pos, int val) {
        while (pos > 0) {
            tree[pos] += val;
            pos -= lowbit(pos);
        }
    }

    void addseg(int a, int b, int val) {
        add(a - 1, -val);
        add(b, val);
    }

    //点查询
    int sum(int pos) {
        int res = 0;
        while (pos < n) {
            res += tree[pos];
            pos += lowbit(pos);
        }
        return res;
    }
private:
    int n;
    vector<int> tree;
};

class SegSegBIT { // 区间更新，区间查询
public:
    SegSegBIT(int n_) : n(n_), A(n), B(n) {}
    
    void addseg(int a, int b, int val) { // 区间更新
        update(b, val);
        if (a > 1) {
            update(a - 1, -val);
        }
    }

    int sum(int x) {
        if (x) {
            return A.sum(x) * x + B.sum(x - 1);
        } else {
            return 0;
        }
    }

    int sum(int a, int b) { //区间查询
        return sum(b) - sum(a - 1);
    }
private:
    void update(int pos, int val) {
        A.add(pos,val);
        B.add(pos,pos*val);
    }

    int n;
    SegBIT A;
    BITree B;
};


struct Operation {
    int type;
    int id;
    int l, r, v;
};

vector<Operation> ops;
vector<int> ans;
SegSegBIT ssbit(N);
vector<Operation> t1, t2;

void OfflineBinarySearch(int vl, int vr, int ql, int qr) {
    if (ql + 1 >= qr) {
        return;
    }

    if (vl + 1 == vr) {
        for (int i = ql; i < qr; i++) {
            if (ops[i].type == 2) {
                ans[ops[i].id] = vl;
            }
        }
        return;
    }

    t1.clear();
    t2.clear();

    int vm = (vl + vr) / 2;
    for (int i = ql; i < qr; i++) {
        Operation op = ops[i];
        if (op.type == 2) { // query
            int v = ssbit.sum(op.l, op.r);
            if (v < op.v) {
                op.v -= v;
                t1.push_back(op);
            } else {
                t2.push_back(op);
            }
        } else if (op.type == 1) { // add
            if (op.v < vm) {
                t1.push_back(op);
            } else {
                ssbit.addseg(op.l, op.r, 1);
                t2.push_back(op);
            }
        } else {
            assert(false);
        }
    }

    for (int i = 0; i < t2.size(); i++) {
        const Operation& op = t2[i];
        if (op.type == 1) {
            ssbit.addseg(op.l, op.r, -1);
        }
    }

    for (int i = 0; i < t1.size(); i++) {
        ops[ql + i] = t1[i];
    }
    for (int i = 0; i < t2.size(); i++) {
        ops[ql + t1.size() + i] = t2[i];
    }

    int c1 = t1.size();
    int c2 = t2.size();

    OfflineBinarySearch(vl, vm, ql, ql + c1);
    OfflineBinarySearch(vm, vr, ql + c1, qr);
}

int main() {
#ifndef __CPRUN__
    freopen("toy.in", "r", stdin);
    freopen("toy.out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);

    int tp, a, b, c;

    int qcnt = 0;

    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &tp, &a, &b, &c);
        Operation op;
        {
            op.type = tp;
            op.id = (tp == 1? 0: ++qcnt);
            op.l = a;
            op.r = b;
            op.v = c;
        }
        ops.push_back(op);
    }

    ans.resize(qcnt + 1);

    OfflineBinarySearch(0, INF, 0, ops.size());

    for (int i = 1; i <= qcnt; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}

/*
^^^^TEST^^^^
2 6
1 1 1 1
1 1 2 2
2 1 1 1
2 1 1 2
2 1 2 1
2 1 2 3
-----
2
1
2
1
$$$TEST$$$
*/
