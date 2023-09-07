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
#include <unordered_set>
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

const llint PRIME = 3;
const llint MOD = 0xdeadbeefcafeb;
const int N = 212345;

int n, m;
vector<int> ns;
vector<int> cs;
vector<llint> hs;
vector<llint> fs;
vector<llint> ps;
unordered_set<llint> st;

llint mymul(llint a, llint b) {
    llint res = 0;
    while (b) {
        if (b & 1) {
            res = (res + a) % MOD;
        }
        a = (a * 2) % MOD;
        b >>= 1;
    }
    return res;
}

llint mypow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = mymul(res, a);
        }
        a = mymul(a, a);
        b >>= 1;
    }
    return res;
}

llint get_hash(int a, int b) {
    llint h = 0;
    if (a - 1 >= 0) {
        h += hs[a - 1];
    }

    h += ((hs[n - 1] - hs[b]) % MOD + MOD) % MOD;
    h %= MOD;

    int ones = cs[b] - (a - 1 >= 0? cs[a - 1]: 0);
    int zeros = (b - a + 1) - ones;
    llint base = mymul(fs[ones], ps[a + zeros]);
    // print(">>", a + zeros, mypow(PRIME, a + zeros), fs[ones], ones, base, h);

    return (h + base) % MOD;
}

int main() {
    int T;
    input(T);

    fs = vector<llint>(N, 0);
    fs[0] = 0;
    for (int i = 1; i < N; i++) {
        fs[i] = (fs[i - 1] * PRIME + 1) % MOD;
    }

    ps = vector<llint>(N, 0);
    ps[0] = 1;
    for (int i = 1; i < N; i++) {
        ps[i] = mymul(ps[i - 1], PRIME);
    }

    while (T--) {
        input(n, m);
        string s;
        input(s);

        ns = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            ns[i] = s[i] - '0';
        }

        cs = ns;
        for (int i = 1; i < n; i++) {
            cs[i] += cs[i - 1];
        }

        hs = vector<llint>(n, 0);
        llint pre = 1;

        for (int i = 0; i < n; i++) {
            hs[i] = ((i - 1 >= 0? hs[i - 1]: 0) + pre * ns[i]) % MOD;
            pre = (pre * PRIME) % MOD;
        }

        st.clear();

        int a, b;
        while (m--) {
            scanf("%d%d", &a, &b);
            llint h = get_hash(a - 1, b - 1);
            // print(h);
            st.insert(h);
        }
        print(st.size());
       //  print("---");
    }

    return 0;
}

/*

^^^TEST^^^
3
6 5
101100
1 2
1 3
2 4
5 5
1 6
6 4
100111
2 2
1 4
1 3
1 2
1 1
0
1 1
-----
3
3
1
$$$TEST$$$

*/
