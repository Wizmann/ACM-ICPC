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

struct Node {
    llint a, c;
    int idx;

    bool operator < (const Node& other) {
        return a < other.a;
    }
};

int main() {
    int n;
    input(n);

    vector<Node> nodes;

    llint tot = 0;
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        nodes.push_back({a, b, i});
        tot += b;
    }

    sort(nodes.begin(), nodes.end());

    int cur = 0;

    while (cur < n) {
        llint maxi = nodes[cur].a + nodes[cur].c;
        while (cur + 1 < n) {
            if (maxi > nodes[cur + 1].a) {
                maxi = max(maxi, nodes[cur + 1].a + nodes[cur + 1].c);
                cur++;
            } else {
                break;
            }
        }

        if (cur + 1 < n) {
            tot += nodes[cur + 1].a - maxi;
            // print(nodes[cur + 1].a, maxi, tot);
            cur++;
        } else {
            break;
        }
    }
    print(tot);

    return 0;
}

/*

^^^TEST^^^
3
1 9
2 1
4 1
-----
11
$$$TEST$$$

^^^TEST^^^
6
4 2
8 4
3 0
2 3
7 1
0 1
----
13
$$$TEST$$$

*/
