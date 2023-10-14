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

int main() {
    int n;
    input(n);

    map<llint, llint> mp;

    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        mp[a] += b;
    }

    llint tot = 0;
    for (auto& p: mp) {
        llint size = p.first;
        llint cnt = p.second;

        mp[size * 2] += cnt / 2;
        tot += cnt % 2;
    }
    print(tot);

    return 0;
}

/*

^^^TEST^^^
3
3 3
5 1
6 1
-----
3
$$$TEST$$$

^^^TEST^^^
3
1 1
2 1
3 1
-----
3
$$$TEST$$$

^^^TEST^^^
1
1000000000 1000000000
-----
13
$$$TEST$$$

*/
