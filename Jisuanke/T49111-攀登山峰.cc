#pragma G++ optimize("O2")

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <random>
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

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int N = 100010;

vector<int> g[N];
vector<int> ns;
int n, m;
map<int, int> mp;
vector<int> rp;

unsigned long myrand(void) {
    return rand() * RAND_MAX + rand();
}

int do_mycount(int p, int v) {
    return upper_bound(g[v].begin(), g[v].end(), p) - g[v].begin();
}

int mycount(int l, int r, int v) {
    return do_mycount(r, v) - do_mycount(l - 1, v);
}

int TRY[] = {0, 1, 16, 27, 38, 48, 59, 70, 80, 91, 102, 113, 123, 134, 145, 155, 166, 177, 187, 198, 209};

int solve(int l, int r, int t) {
    int m = r - l + 1;
    double q = 1.0 * (r - l + 1) / t;
    int res = -1;

    set<int> st;
    int tot = 0;

    for (int i = 0; i <= TRY[t]; i++) {
        int p = l + myrand() % m;
        assert (l <= p && p <= r);

        int v = ns[p];
        if (v <= res) {
            continue;
        }

        if (st.count(v)) {
            continue;
        }
        st.insert(v);

        if (g[v].size() < q) {
            continue;
        }
        int cnt = mycount(l, r, v);
        tot += cnt;

        if (cnt > q) {
            res = max(res, v);
        }

        if (tot >= m) {
            break;
        }
    }

    if (res == -1) {
        return -1;
    }
    return rp[res];
}

int Scan() {
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + (ch - '0');
    return flag ? -res : res;
}
 
 
void Out(int a) {
    if(a < 0) { putchar('-'); a = -a; }
    if(a >= 10) Out(a / 10);
    putchar(a % 10 + '0');
}


int main() {
    srand(time(NULL));
    n = Scan();
    m = Scan();

    ns.resize(n);
    rp.resize(n);
    for (int i = 0; i < n; i++) {
        ns[i] = Scan();
        mp[ns[i]] = -1;
    }

    int idx = 0;
    for (auto& p: mp) {
        p.second = idx;
        assert(idx < n);
        rp[idx] = p.first;
        ++idx;
    }

    for (int i = 0; i < n; i++) {
        ns[i] = mp[ns[i]];
        g[ns[i]].push_back(i);
    }

    int l, r, t;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &l, &r, &t);
        l -= 1;
        r -= 1;
        Out(solve(l, r, t));
        puts("");
    }
    return 0;
}

/*
^^^TEST^^^
5 3
1 10 100 10 1
1 1 1
1 4 3
1 5 10
----
-1
10
100
$$$TEST$$$
^^^TEST^^^
8 3
1 2 1 4 4 5 3 3 
3 7 5
1 4 3
3 8 6
----
4
1
4
$$$TEST$$$

^^^TEST^^^
8 3
1 2 1 4 4 5 3 3 
3 7 1
1 4 3
3 8 6
----
-1
1
4
$$$TEST$$$

^^^TEST^^^
10 10
0 2 0 4 13 2 20 20 0 18 
3 7 2
4 4 1
1 1 3
4 8 1
4 9 2
3 4 3
3 5 1
5 6 8
1 5 6
3 6 8
---
-1
-1
0
-1
-1
4
-1
13
13
13
$$$TEST$$$

*/
