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

struct Record {
    int l, r;
};

struct Item {
    int temp, pos;
};

int main() {
    int n;
    input(n);

    vector<Record> records(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &records[i].l, &records[i].r);
    }
    records.push_back({-INF, -INF});
    n++;

    int ans = 1;

    deque<Item> dq;

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front().temp > records[i].r) {
            ans = max(ans, i - dq.front().pos);
            dq.pop_front();
        }
        Item nxt = { records[i].l, i };
        while (!dq.empty() && dq.back().temp < nxt.temp) {
            nxt.pos = dq.back().pos;
            dq.pop_back();
        }
        dq.push_back(nxt);
    }
    print(ans);

    return 0;
}

/*

^^^TEST^^^
2
1 2
3 4
-----
2
$$$TEST$$$

^^^TEST^^^
2
3 4
1 2
-----
1
$$$TEST$$$

^^^TEST^^^
3
3 4
1 2
4 4
-----
2
$$$TEST$$$

^^^TEST^^^
6
6 10
1 5
4 8
2 5
6 8
3 5
-----
4
$$$TEST$$$

*/
