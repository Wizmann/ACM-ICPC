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


namespace FastIO {
    char buf[1 << 21], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p1 = buf, p2 = (p1 + fread(buf, 1, 1 << 21, stdin))) == p1 ? EOF : *p1++)
    template <typename T> inline T read() { T x = 0, w = 0; char ch = getchar(); while (ch < '0' || ch > '9') w |= (ch == '-'), ch = getchar(); while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar(); return w ? -x : x; }
    template <typename T> inline void write(T x) { if (!x) return; write<T>(x / 10), putchar((x % 10) ^ '0'); }
    template <typename T> inline void print(T x) { if (x > 0) write<T>(x); else if (x < 0) putchar('-'), write<T>(-x); else putchar('0'); }
    template <typename T> inline void print(T x, char en) { print<T>(x), putchar(en); }
}; using namespace FastIO;
#undef getchar


const int SIZE = 212345;

vector<int> g[SIZE];
vector<int> ptr;
vector<int> mergebuffer;
int n, m, q;

void merge(int a, int b) {
    int la = g[ptr[a]].front();
    int ra = g[ptr[a]].back();
    int lb = g[ptr[b]].front();
    int rb = g[ptr[b]].back();

    if (ra <= lb) {
        return;
    }

    if (la >= rb) {
        swap(ptr[a], ptr[b]);
        return;
    }

    int pa = 0;
    int pb = 0;
    int p = 0;

    while (p < m * 2) {
        int va = pa < m ? g[ptr[a]][pa] : INF;
        int vb = pb < m ? g[ptr[b]][pb] : INF;

        if (va <= vb) {
            mergebuffer[p++] = va;
            pa++;
        } else {
            mergebuffer[p++] = vb;
            pb++;
        }
    }

    std::copy(mergebuffer.begin(), mergebuffer.begin() + m, g[ptr[a]].begin());
    std::copy(mergebuffer.begin() + m, mergebuffer.end(), g[ptr[b]].begin());
}

int main() {
    input(m, n, q);

    ptr.resize(n);
    mergebuffer.resize(m * 2);
    for (int i = 0; i < n; i++) {
        g[i].resize(m);
        for (int j = 0; j < m; j++) {
            g[i][j] = FastIO::read<int>();
        }
        ptr[i] = -1;
    }

    int a, b, c;
    while (q--) {
        a = FastIO::read<int>();
        b = FastIO::read<int>();
        c = FastIO::read<int>();
        b--;
        c--;

        if (a == 1) {
            if (ptr[b] == -1) {
                sort(g[b].begin(), g[b].end());
                ptr[b] = b;
            }

            if (ptr[c] == -1) {
                sort(g[c].begin(), g[c].end());
                ptr[c] = c;
            }

            merge(b, c);
        } else {
            assert(a == 2);

            int p = ptr[b];
            if (p == -1) {
                p = b;
            }
            FastIO::print(g[p][c], '\n');
        }

        /*
        puts(">>");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", g[i][j]);
            }
            puts("");
        }
        puts("<<");
        */

    }

    return 0;
}

/*

^^^TEST^^^
5 3 6
1 3 2 5 6
2 7 8 2 2
3 5 3 4 8
2 1 5
1 1 2
2 2 4
1 1 3
1 2 1
2 2 3
-----
6
7
2
$$$TEST$$$

^^^TEST^^^
6 5 20
5 14 13 1 15 17
7 7 19 3 8 6
16 13 13 6 14 2
12 5 4 17 12 3
19 19 4 6 3 3
2 5 3
1 4 3
2 1 1
1 2 5
2 4 6
2 2 2
1 4 2
1 2 4
2 1 1
2 3 3
2 3 3
1 4 2
1 4 1
2 3 5
1 3 4
1 4 1
1 1 4
1 5 1
2 2 4
2 4 2
-----
4
5
12
3
5
13
13
16
6
14
$$$TEST$$$

*/
