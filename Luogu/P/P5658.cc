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

const int SIZE = 512345;

std::string marks;
vector<int> g[SIZE];
vector<llint> ans;
map<int, int> mp;

void dfs(int cur, int base, llint cnt) {
    int pre = base;
    if (marks[cur] == '(') {
        base += 1;
    } else {
        base -= 1;
    }

    vector<pair<int, int>> removed;

    while (!mp.empty()) {
        if (pre - mp.rbegin()->first < 0) {
            removed.push_back(*mp.rbegin());
            mp.erase(--mp.end());
        } else {
            break;
        }
    }

    if (mp.count(base)) {
        cnt += mp[base];
    }
    ans[cur] = cnt;

    mp[pre] += 1;

    for (auto nxt : g[cur]) {
        dfs(nxt, base, cnt);
    }

    mp[pre] -= 1;
    if (mp[pre] == 0) {
        mp.erase(mp.find(pre));
    }

    assert(removed.size() <= 1);
    for (auto& r : removed) {
        mp.emplace(r);
    }
}

int main() {
    int n;
    input(n);

    input(marks);

    int a;
    for (int i = 1; i < n; i++) {
        scanf("%d", &a);
        a--;
        g[a].push_back(i);
    }

    ans = vector<llint>(n, 0);

    dfs(0, 0, 0);

    llint res = 0;
    for (int i = 0; i < n; i++) {
        res ^= 1LL * (i + 1) * ans[i];
        // print(i + 1, ans[i]);
    }

    print(res);

    return 0;
}

/*

^^^TEST^^^
5
(()()
1 1 2 2
-----
6
$$$TEST$$$

^^^TEST^^^
8
()(()))(
1 2 3 4 5 6 7
-----
43
$$$TEST$$$

^^^TEST^^^
8
()(()))(
1 2 3 4 5 6 7
-----
43
$$$TEST$$$

^^^TEST^^^
8
)(()((()
1 2 1 4 5 4 7
-----
8
$$$TEST$$$

^^^TEST^^^
9
(())((())
1 2 1 4 5 4 7 3
-----
9
$$$TEST$$$

*/
