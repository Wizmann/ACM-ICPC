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
#include <unordered_map>
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

const int SIZE = 103456 * 2;
const int NUM = 103456 * 2;
const int R = 103;

int n, k, q;
int cnt[SIZE + 12];
int dp[SIZE + 12];
bool res[R + 2][SIZE + 12];

struct Num {
    int i, j, id;
};

vector<Num> digits[NUM + 12];
vector<pair<int, int> > nums;
vector<pair<int, int> > queries;

void solve(const Num& num) {
    int u = num.i;
    int v = num.j;
    int idx = num.id;

    int st = idx;
    int end = idx + min(k - 1, (int)cnt[u] - v - 1);

    dp[st] -= 1;
    dp[end] += 1;
}

int main() {
    int T;
    scanf("%d", &T);

    nums.reserve(SIZE);

    while (T--) {
        nums.clear();

        for (int i = 0; i < NUM; i++) {
            digits[i].clear();
        }

        scanf("%d%d%d", &n, &k, &q);

        int m;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &m);
            cnt[i] = m;

            int x;
            for (int j = 0; j < m; j++) {
                scanf("%d", &x);
                nums.push_back({x, i});
                digits[x].push_back({i, j, idx});
                idx++;
            }
        }

        memset(res, 0, sizeof(res));

        int maxr = 0;
        queries.clear();

        for (int i = 0; i < q; i++) {
            int r, c;
            scanf("%d%d", &r, &c);
            queries.push_back({r, c});
            maxr = max(maxr, r);
        }

        vector<int> mp(NUM, -1);
        mp[1] = INF;
        for (int i = 1; i <= maxr; i++) {
            memset(dp, 0, sizeof(dp));
            for (int j = 0; j < NUM; j++) {
                if (mp[j] == -1) {
                    continue;
                }
                int filter = mp[j];
                for (const auto& num : digits[j]) {
                    if (num.i == filter) {
                        continue;
                    }
                    solve(num);
                }
            }
            mp = vector<int>(NUM, -1);
            for (int j = idx; j >= 0; j--) {
                dp[j] = (dp[j] + dp[j + 1]);
                if (dp[j]) {
                    assert(j < (int)nums.size());
                    assert(dp[j] > 0);
                    int nxt = nums[j].first;
                    int st = nums[j].second;
                    res[i][nxt] = true;
                    
                    if (mp[nxt] == -1 || mp[nxt] == st) {
                        mp[nxt] = st;
                    } else {
                        mp[nxt] = INF;
                    }
                }
            }
        }

        char result[10] = "0";
        for (int i = 0; i < q; i++) {
            int r = queries[i].first;
            int c = queries[i].second;
            result[0] = res[r][c] + '0';
            puts(result);
        }
    }

    return 0;
}

/*

^^^TEST^^^
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
2 4
3 4
6 6
1 1
7 7
-----
1
0
1
0
1
0
0
$$$TEST$$$

*/
