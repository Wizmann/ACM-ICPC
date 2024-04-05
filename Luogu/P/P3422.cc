#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename... T, typename X> void print(X&& x, T... args) {
    cout << x << " ";
    print(args...);
}

int input() { return 0; }

template <typename... T, typename X> int input(X& x, T&... args) {
    if (!(cin >> x))
        return 0;
    return input(args...) + 1;
}

struct Node {
    llint gas, nxt, idx;
};

vector<bool> solve(const vector<Node>& nodes) {
    const int n = nodes.size();
    llint tot = 0;

    deque<pair<llint, int>> dq;

    for (int i = 0; i < n; i++) {
        const auto& node = nodes[i];
        tot += node.gas - node.nxt;

        // printf("<%d, %d> ", node.gas, node.nxt);

        pair<llint, int> p = {tot, i};

        while (!dq.empty() && dq.back().first >= p.first) {
            dq.pop_back();
        }
        dq.push_back(p);
    }
    // puts("");

    vector<bool> res(n, false);

    llint base = 0;
    for (int i = 0; i < n; i++) {
        llint mini = dq.front().first - base;

        if (mini >= 0) {
            res[nodes[i].idx] = true;
        }

        if (!dq.empty() && dq.front().second == i) {
            dq.pop_front();
        }

        base += nodes[i].gas - nodes[i].nxt;
        tot += nodes[i].gas - nodes[i].nxt;

        pair<llint, int> p = {tot, i};

        while (!dq.empty() && dq.back().first >= p.first) {
            dq.pop_back();
        }
        dq.push_back(p);
    }
    return res;
}

int main() {
    int n;
    input(n);

    vector<Node> nodes1(n);
    vector<Node> nodes2(n);

    llint a, b;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a, &b);
        nodes1[i] = {a, b, i};
        nodes2[i].gas = a;
        nodes2[i].idx = i;
        nodes2[(i + 1) % n].nxt = b;
    }
    reverse(nodes2.begin(), nodes2.end());

    vector<bool> res1 = solve(nodes1);
    vector<bool> res2 = solve(nodes2);

    for (int i = 0; i < n; i++) {
        if (res1[i] || res2[i]) {
            puts("TAK");
        } else {
            puts("NIE");
        }
    }

    return 0;
}

/*
 
^^^TEST^^^
3
1 1
1 1
1 1
-----
TAK
TAK
TAK
$$$TEST$$$

^^^TEST^^^
3
1 2
2 1
1 1
-----
TAK
TAK
TAK
$$$TEST$$$

^^^TEST^^^
3
1 100
10000 500
299 200
-----
NIE
TAK
TAK
$$$TEST$$$

^^^TEST^^^
3
1002 1000
999 1000
999 1000
-----
TAK
NIE
NIE
$$$TEST$$$

^^^TEST^^^
3
999 1000
999 1000
1002 1000
-----
NIE
NIE
TAK
$$$TEST$$$

^^^TEST^^^
3
1 100
10000 500
298 200
-----
NIE
TAK
NIE
$$$TEST$$$

^^^TEST^^^
5
3 1
1 2
5 2
0 1
5 4
-----
TAK
NIE
TAK
NIE
TAK
$$$TEST$$$

*/
