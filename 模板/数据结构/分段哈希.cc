// Result: 2014-07-11 20:07:01  Wizmann  E - DZY Loves Colors    GNU C++0x  Accepted     592 ms  2500 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

#define TLE_ASSERT(exp)  \
    do {                 \
        while (!(exp)) { \
            /* pass */   \
        }                \
    } while(0)

typedef long long llint;

const int PURE = 0;
const int MIXED = -1;

const int NODE = 199;
const int SIZE = 123456;

struct Cell {
    int color;
    llint value;
    Cell(){}
    Cell(int icolor, llint ivalue): color(icolor), value(ivalue) {}
};

struct Summary {
    int color; 
    llint lazy, sum;
    Summary(){}
    Summary(int icolor, llint ilazy, llint isum): color(icolor), \
            lazy(ilazy), sum(isum) {}
};

vector<Cell> ribbons[SIZE / NODE];
vector<Summary> summary;

int n, m, q;

void init_ribbon(int p, int num)
{
    int nr = p * NODE;
    for (int i = 0; i < num; i++) {
        ribbons[p].push_back(Cell(nr + 1, 0));
        nr++;
    }
}

void do_paint(int p, int l, int r, int c)
{
    int ll = p * NODE, rr = ll + ribbons[p].size() - 1;
    if (ll == l && rr == r) { // 全覆盖
        if (summary[p].color != MIXED) {
            llint sz = ribbons[p].size();
            summary[p].lazy += abs(c - summary[p].color);
            summary[p].sum += sz * abs(c - summary[p].color);
            summary[p].color = c;
            return;
        } else {
            summary[p].color = c;
            TLE_ASSERT(summary[p].lazy == 0);
        }
    } else if (summary[p].color != MIXED) {
        for (auto iter = ribbons[p].begin(); iter != ribbons[p].end(); ++iter) {
            iter -> value += summary[p].lazy;
            iter -> color = summary[p].color;
        }
        summary[p].lazy = 0;
        summary[p].color = MIXED;
    }
    int nr = p * NODE;
    for (auto iter = ribbons[p].begin(); iter != ribbons[p].end(); ++iter) {
        if (nr < l || nr > r) {
            nr++;
            continue;
        }
        
        Cell& cell = *iter;
        cell.value += abs(cell.color - c);
        summary[p].sum += abs(cell.color - c);
        cell.color = c;

        nr++;
    }
}

void paint(int l, int r, int v)
{
    for (int i = 0; i < m; i++) {
        int ll = i * NODE, rr = ll + ribbons[i].size() - 1;
        if (rr < l || ll > r) {
            continue;
        }
        do_paint(i, max(ll, l), min(rr, r), v);
    }
}

llint do_sumup(int p, int l, int r)
{
    llint res = 0;
    int ll = p * NODE, rr = ll + ribbons[p].size() - 1;
    if (l == ll && r == rr) {
        return summary[p].sum;
    }
    if (summary[p].color != MIXED) {
        for (auto iter = ribbons[p].begin(); iter != ribbons[p].end(); ++iter) {
            iter -> value += summary[p].lazy;
        }
        summary[p].lazy = 0;
    }
    int nr = p * NODE;
    for (auto iter = ribbons[p].begin(); iter != ribbons[p].end(); ++iter) {
        if (nr < l || nr > r) {
            nr++;
            continue;
        }
        res += iter -> value;
        nr++;
    }
    return res;
}


llint sumup(int l, int r)
{
    llint res = 0;
    for (int i = 0; i < m; i++) {
        int ll = i * NODE, rr = ll + ribbons[i].size() - 1;
        if (rr < l || ll > r) {
            continue;
        }
        res += do_sumup(i, max(ll, l), min(rr, r));
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int cmd, l, r, v;
    input(n >> q);
    m = (n + NODE - 1) / NODE;
    for (int i = 0, remain = n; i < m; i++) {
        if (remain > NODE) {
            init_ribbon(i, NODE);
            remain -= NODE;
        } else {
            init_ribbon(i, remain);
            remain -= remain;
            TLE_ASSERT(i == m - 1);
        }
        summary.push_back(Summary(MIXED, 0, 0));
    }
    while (q--) {
        scanf("%d%d%d", &cmd, &l, &r);
        l--; r--;
        if (cmd == 1) {
            scanf("%d", &v);
            paint(l, r, v);
            // print(">> " << sumup(l, r));
        } else {
            print(sumup(l, r));
        }
    }
    return 0;
}
