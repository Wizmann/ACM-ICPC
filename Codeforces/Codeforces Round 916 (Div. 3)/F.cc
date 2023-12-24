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

const int SIZE = 212345;

int n;
vector<int> parents;
vector<int> g[SIZE];
set<int> levels[SIZE];
int ans;

int dfs(int cur, int depth) {
    int maxi = depth;
    levels[depth].insert(cur);
    for (auto nxt : g[cur]) {
        maxi = max(maxi, dfs(nxt, depth + 1));
    }
    return maxi;
}

int main() {
    int T;
    input(T);

    while (T--) {
        input(n);
        parents = vector<int>(n + 1, -1);

        for (int i = 0; i <= n; i++) {
            g[i].clear();
            levels[i].clear();
        }

        for (int i = 2; i <= n; i++) {
            scanf("%d", &parents[i]);
        }

        for (int i = 2; i <= n; i++) {
            g[parents[i]].push_back(i);
        }

        ans = 0;
        int d = dfs(1, 0);
        map<int, int> mp;

        for (int i = d; i >= 0; i--) {
            assert(mp.size() <= 1);
            if (mp.size() == 1) {
                int cur = mp.begin()->first;
                int cnt = mp.begin()->second;
                mp.clear();

                levels[i].erase(levels[i].find(cur));
                cnt++;

                ans += min(cnt, (int)levels[i].size());

                if ((int)levels[i].size() >= cnt) {
                    int rem = levels[i].size() - cnt;
                    ans += rem / 2;
                    if (rem % 2) {
                        cur = *levels[i].begin();
                        mp[parents[cur]] = 1;
                    }
                } else {
                    cnt -= levels[i].size();
                    mp[parents[cur]] = cnt;
                }
            } else {
                int rem = levels[i].size();
                ans += rem / 2;
                if (rem % 2) {
                    int cur = *levels[i].begin();
                    mp[parents[cur]] = 1;
                }
            }
        }

        print(ans);
    }

    return 0;
}

/*

^^^TEST^^^
6
4
1 2 1
2
1
5
5 5 5 1
7
1 2 1 1 3 3
7
1 1 3 2 2 4
7
1 2 1 1 1 3
-----
1
0
1
3
3
3
$$$TEST$$$

*/
