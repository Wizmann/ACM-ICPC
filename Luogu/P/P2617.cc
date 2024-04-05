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

class BiTree {
public:
    BiTree(int n): _n(n + 1), _tree(n + 1, 0) {}
    
    void add(int pos, int val) {
        while (pos < _n) {
            _tree[pos] += val;
            pos += lowbit(pos);
        }
    }
    
    int sum(int pos) {
        int res = 0;
        while (pos) {
            res += _tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
    
    int sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int lowbit(int x) {
        return x & (-x);
    }
private:
    int _n;
    vector<int> _tree;
};

struct Query {
    char type;
    int id;
    int pos1, pos2, k;
};

vector<int> ans;
vector<int> ns;

vector<Query> t1, t2, Q;

const int N = 123456;
BiTree bitree(N);

void solve(int l, int r, int ql, int qr) {
    // query set is empty
    if (ql >= qr) {
        return;
    }

    if (l + 1 == r) {
        for (int i = ql; i < qr; i++) {
            ans[Q[i].id] = l;
        }
        return;
    }

    t1.clear();
    t2.clear();

    int m = (l + r) / 2;
    int c1 = 0;
    int c2 = 0;
    for (int i = ql; i < qr; i++) {
        Query q = Q[i];
        if (q.type == 'Q') {
            int v = bitree.sum(q.pos1, q.pos2);
            if (q.k <= v) {
                t1.push_back(q);
            } else {
                q.k -= v;
                t2.push_back(q);
            }
        } else {
            int delta = q.type == 'D'? -1: 1;
            if (q.k < m) {
                t1.push_back(q);
                bitree.add(q.pos1, delta);
            } else {
                t2.push_back(q);
            }
        }
    }
    for (const auto& q : t1) {
        if (q.type == 'Q') {
            continue;
        }
        int delta = q.type == 'D'? -1: 1;
        bitree.add(q.pos1, -delta);
    }

    for (int i = 0; i < t1.size(); i++) {
        Q[ql + i] = t1[i];
    }
    for (int i = 0; i < t2.size(); i++) {
        Q[ql + t1.size() + i] = t2[i];
    }

    // t1 and t2 will be modified during recursion
    int cnt1 = t1.size();
    int cnt2 = t2.size();
    solve(l, m, ql, ql + cnt1);
    solve(m, r, ql + cnt1, qr);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    ns.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
        Q.push_back({'I', 0, i, -1, ns[i]});
    }

    char cmd[10];
    int a, b, c;
    int qcnt = 0;
    for (int i = 0; i < m; i++) {
        scanf("%s", cmd);
        if (cmd[0] == 'Q') {
            scanf("%d%d%d", &a, &b, &c);
            Q.push_back({'Q', ++qcnt, a, b, c});
        } else {
            scanf("%d%d", &a, &b);

            Q.push_back({'D', 0, a, -1, ns[a]});
            Q.push_back({'I', 0, a, -1, b});
            ns[a] = b;
        }
    }

    ans.resize(qcnt + 1);

    solve(0, INF, 0, Q.size());

    for (int i = 1; i <= qcnt; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}

/*

^^^TEST^^^
5 3
3 2 1 4 7
Q 1 4 3
C 2 6
Q 2 5 3
-----
3
6
$$$TEST$$$

*/
