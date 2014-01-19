#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 7010;
const int LINE = 501000;

struct node {
    int l, r;
    int val;

    node(){}
    node(int il, int ir, int ival): l(il), r(ir), val(ival) {}
};

int n, m;
int ls[LINE], rs[LINE];
vector<node> ins[SIZE];

bool intersect(int a, int b, int c, int d) {
    if (b < c || a > d) return false;
    return true;
}

void init()
{
    ls[1] = 1;
    rs[1] = 2;
    int cnt, p = 3;
    for (int i = 2; i < LINE; i++) {
        if ((1 << cnt) == i) {
            cnt++;
            ls[i] = p++;
            rs[i] = p++;
        } else {
            ls[i] = -1;
            rs[i] = p++;
        }
    }
}

int query(int a, int b) {
    set<int> s;
    int ll = b, rr = b;
    for (int level = a; level <= n; level++) {
        for (int i = 0; i < (int)ins[level].size(); i++) {
            if (intersect(ll, rr, ins[level][i].l, ins[level][i].r)) {
                s.insert(ins[level][i].val);
            }
        }
        ll = ls[ll] == -1? rs[ll]: ls[ll];
        rr = rs[rr];
    }
    return s.size();
}

int main()
{
    freopen("input.txt", "r", stdin);
    int tp;
    int l, r;
    int a, b;
    init();
    input(n >> m);
    while (m--) {
        input(tp);
        if (tp == 1) {
            input(a >> l >> r >> b);
            ins[a].push_back(node(l, r, b));
        } else {
            input(a >> b);
            print(query(a, b));
        }
    }
    return 0;
}

