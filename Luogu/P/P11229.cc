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

map<int, int> mp;

bool dfs(int n, int len, std::string& res) {
    if (len == 0) {
        return n == 0;
    }
    if (len * 7 < n) {
        return false;
    }
    for (auto p : mp) {
        if (p.first == 0 && res.empty()) {
            continue;
        }

        res.push_back('0' + p.first);
        if (dfs(n - p.second, len - 1, res)) {
            return true;
        }
        res.pop_back();
    }
    return false;
}

std::string solve(int n) {
    int len = (n + 6) / 7;

    std::string res;

    if (!dfs(n, len, res)) {
        return "-1";
    }

    return res;
}

int main() {
    int T;
    input(T);

    mp[0] = 6;
    mp[1] = 2;
    mp[2] = 5;
    mp[4] = 4;
    mp[6] = 6;
    mp[7] = 3;
    mp[8] = 7;

    int n;
    while (T--) {
        input(n);

        print(solve(n));
    }

    return 0;
}

/*

^^^TEST^^^
5
1
2
3
6
18
-----
-1
1
7
6
208
$$$TEST$$$

^^^^^^TEST^^^^^
1
123456
--------
<ignore>
$$$TEST$$$

*/
