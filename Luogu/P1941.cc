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

const int MAXM = 1234;

int n, m, k;

struct Tap {
    int up, down;
};

struct Tube {
    int lb, ub, id;
};

vector<Tap> taps;
vector<Tube> tubes;

int dp[2][MAXM];

int main() {
    input(n, m, k);

    taps.resize(n + 1);
    tubes.resize(n + 1);

    int a, b, c;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        taps[i] = {a, b};

    }

    for (int i = 0; i <= n; i++) {
        tubes[i] = {0, m + 1, -1};
    }

    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &a, &b, &c);
        assert(tubes[a].id == -1);
        tubes[a] = {b, c, i + 1};
    }

    memset(dp, INF, sizeof(dp));

    for (int i = tubes[0].lb + 1; i < tubes[0].ub; i++) {
        dp[0][i] = 0;
    }

    int maxi = 0;
    int p = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int q = p ^ 1;
        memset(dp[q], INF, sizeof(dp[q]));
        int up = taps[i].up;
        int down = taps[i].down;
        int lb = tubes[i + 1].lb;
        int rb = tubes[i + 1].ub;
        bool flag = false;
        vector<pair<int, int> > xs(up, {INF, INF});
        for (int j = 1; j <= m; j++) {
            if (dp[p][j] < INF) {
                flag = true;
            }
            int nxt = j - down;
            if (lb < nxt && nxt < rb && dp[p][j] < INF) {
                dp[q][nxt] = min(dp[q][nxt], dp[p][j]);
            }

            int pre = INF;
            if (xs[j % up].first != INF) {
                pre = (j - xs[j % up].first) / up + xs[j % up].second;
            }

            int cur = dp[p][j];
            if (cur < pre) {
                xs[j % up] = {j, cur};
            }

            int mini = min(pre, cur) + 1;

            nxt = min(m, j + up);
            if (lb < nxt && nxt < rb && mini < INF) {
                dp[q][nxt] = min(dp[q][nxt], mini);
            }


        }

        if (tubes[i].id != -1) {
            cnt++;
        }

        /*
        for (int j = 1; j <= m; j++) {
            if (dp[q][j] < INF) {
                print(i + 1, j, dp[q][j], cnt);
            }
        }
        */

        if (flag) {
            maxi = cnt;
        }

        p = q;
    }

    int ans = INF;
    for (int i = 1; i <= m; i++) {
        ans = min(ans, dp[p][i]);
    }

    if (ans < INF) {
        print(1);
        print(ans);
    } else {
        print(0);
        print(maxi);
    }

    return 0;
}

/*

^^^TEST^^^
10 10 6 
3 9  
9 9  
1 2  
1 3  
1 2  
1 1  
2 1  
2 1  
1 6  
2 2  
1 2 7 
5 1 5 
6 3 5 
7 5 8 
8 7 9 
9 1 3
-----
1
6
$$$TEST$$$

^^^^^TEST^^^^^
10 10 4 
1 2  
3 1  
2 2  
1 8  
1 8  
3 2  
2 1  
2 1  
2 2  
1 2  
1 0 2 
6 7 9 
9 1 4 
3 8 10
-----
0
3
$$$$TEST$$$$

*/
