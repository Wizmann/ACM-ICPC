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

inline void write(__int128 x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

__int128 dfs(llint k, const vector<int>& ns, int& cur, int n) {
    if (ns[cur] == 0) {
        cur++;
        return __int128(k) * k;
    } else if (ns[cur] == 1) {
        cur++;
        return 0;
    }

    assert(ns[cur] == 2);
    __int128 res = 0;
    cur++;
    for (int i = 0; i < 4; i++) {
        res += dfs(k / 2, ns, cur, n);
    }
    return res;
}

int main() {
    llint k;
    input(k);
    k = 1LL << k;

    string s;
    input(s);

    vector<int> ns;
    for (auto c : s) {
        ns.push_back(c - '0');
    }

    int cur = 0;
    write(dfs(k, ns, cur, (int)s.size()));

    return 0;
}

/*

^^^TEST^^^
2
2021010210001
-----
9
$$$TEST$$$

*/
