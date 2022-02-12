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

const int M = 32;

int n, k;
vector<int> ns;
vector<int> fs[M];

int main() {
    input(n, k);

    ns = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
    }

    if (k == 1) {
        print(1LL * n * (n + 1) / 2);
        return 0;
    }

    vector<pair<int, int> > factors;
    for (llint i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            int cnt = 0;
            while (k % i == 0) {
                k /= i;
                cnt++;
            }
            factors.push_back({i, cnt});
        }
    }
    if (k != 1) {
        factors.push_back({k, 1});
    }

    int m = factors.size();
    for (int i = 0; i < m; i++) {
        fs[i] = vector<int>(n + 1, 0);
    }

    for (int i = 1; i <= n; i++) {
        int cur = ns[i];
        for (int j = 0; j < m; j++) {
            int f = factors[j].first;
            while (cur % f == 0) {
                fs[j][i]++;
                cur /= f;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            fs[i][j] += fs[i][j - 1];
        }
    }

    llint res = 0;
    for (int i = 1; i <= n; i++) {
        int mini = INF;
        for (int j = 0; j < m; j++) {
            int cur = fs[j][i];
            int expected = cur - factors[j].second;
            auto iter = upper_bound(fs[j].begin(), fs[j].end(), expected);

            int u = distance(fs[j].begin(), iter);
            mini = min(mini, u);
        }

        res += mini;
        // print(i, mini);
    }

    print(res);


    return 0;
}

/*

^^^TEST^^^
3 4
6 2 8
-----
4
$$$TEST$$$

^^^TEST^^^
3 6
9 1 14
-----
1
$$$TEST$$$

^^^^^TEST^^^^
10 24
79 4 17 98 67 80 10 50 31 80
----------
0
$$$$$$TEST$$$$


^^^^^TEST^^^^
10 24
77 72 43 68 19 80 1 69 42 51
----------
30
$$$$$$TEST$$$$

^^^^^TEST^^^^
10 24
89 62 99 88 79 14 89 66 3 61
----------
24
$$$$$$TEST$$$$

^^^^^TEST^^^^
10 24
69 50 53 92 97 38 41 17 32 92
----------
7
$$$$$$TEST$$$$


^^^^^TEST^^^^
10 456
48 74 65 55 80 90 100 91 18 80
----------
0
$$$$$$TEST$$$$

^^^^^TEST^^^^
10 168
14 18 19 84 14 47 75 63 98 45
----------
26
$$$$$$TEST$$$$

^^^^^TEST^^^^
100 168
69 64 83 46 12 95 93 65 7 63 52 11 30 93 99 12 36 97 80 24 76 32 79 28 53 22 6 54 77 42 68 55 4 38 97 57 8 46 86 16 63 52 58 34 42 73 99 63 12 96 63 48 78 76 11 15 87 82 94 90 50 58 40 67 81 98 36 54 29 19 21 60 84 10 91 87 48 37 5 30 6 8 5 94 27 40 91 37 69 12 31 85 42 47 69 25 64 6 85 50
----------
4529
$$$$$$TEST$$$$

^^^^^TEST^^^^
100 8
1 2 2 1 1 2 1 2 1 1 1 1 2 1 2 1 2 1 2 1 1 1 2 2 2 2 1 2 2 2 2 2 1 1 2 1 2 1 1 1 2 1 2 2 1 2 1 2 2 1 1 2 1 1 2 1 1 1 1 2 1 1 1 1 1 1 1 1 2 1 1 1 2 1 1 2 2 2 2 1 1 1 2 1 1 1 1 2 1 2 1 2 2 1 2 1 1 2 1 2
----------
4407
$$$$$$TEST$$$$

^^^^^TEST^^^^
100 8
2 1 2 1 2 2 2 2 1 2 2 1 2 1 1 1 1 1 1 2 2 2 1 2 1 1 2 2 2 2 2 1 2 1 1 2 1 2 1 2 2 1 2 2 2 2 1 2 1 1 1 1 2 2 2 1 1 2 2 2 2 1 1 1 1 1 2 1 1 1 2 1 2 1 2 1 1 2 2 2 1 2 2 2 2 2 2 2 1 1 1 1 2 1 1 2 1 1 1 1
----------
4578
$$$$$$TEST$$$$

^^^^TEST^^^
5 1
1 3 1 3 1
-----
15
$$$TEST$$$


*/
