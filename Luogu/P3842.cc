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

struct Line {
    int st, end;
};

vector<Line> lines;

int main() {
    int n;
    input(n);

    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        lines.push_back({a, b});
    }

    vector<pair<int, int> > pre = { { 1, 0 } };
    for (int i = 0; i < n; i++) {
        int st = lines[i].st;
        int end = lines[i].end;

        vector<pair<int, int>> nxt;

        for (auto p : pre) {
            const int pos = p.first;
            const int cost = p.second;

            if (pos <= st) {
                int npos = end;
                int ncost = cost + end - pos;
                nxt.push_back({npos, ncost});
            } else if (pos >= end) {
                int npos = st;
                int ncost = cost + pos - st;
                nxt.push_back({npos, ncost});
            } else {
                int ncost1 = cost + pos - st + end - st;
                int npos1 = end;
                nxt.push_back({npos1, ncost1});

                int ncost2 = cost + end - pos + end - st;
                int npos2 = st;
                nxt.push_back({npos2, ncost2});
            }
        }

        map<int, int> mp;
        mp[st] = INF;
        mp[end] = INF;

        for (auto p : nxt) {
            if (i < n - 1) {
                mp[p.first] = min(mp[p.first], p.second + 1);
            } else {
                mp[p.first] = min(mp[p.first], p.second + 1 + n - p.first);
            }
        }

        pre.clear();
        for (auto p : mp) {
            if (p.second < INF) {
                pre.push_back(p);
            }
        }
    }

    int mini = INF;
    for (auto p : pre) {
        mini = min(mini, p.second);
    }
    print(mini - 1);

    return 0;
}

/*

^^^TEST^^^
1
1 1
-----
0
$$$TEST$$$

^^^TEST^^^
2
1 1
2 2
-----
2
$$$TEST$$$

^^^TEST^^^
4
1 1
2 2
3 3
1 4
-----
10
$$$TEST$$$

^^^TEST^^^
6
2 6
3 4
1 3
1 2
3 6
4 5
-----
24
$$$TEST$$$

*/
