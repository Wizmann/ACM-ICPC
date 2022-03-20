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

vector<int> predef5 = {
    1, 2, 3, 5, 6, 7, 8, 9, 11, 12, 13, 15, 16, 18, 19, 20, 22, 23, 24, 25, 26, 28, 29, 30
};
vector<int> predef6 = {
    2, 3, 5, 6, 7, 11, 13, 15, 16, 19, 22, 23, 24, 25, 26, 37, 38, 39, 40, 41, 44, 47, 48, 50, 52, 56, 57, 58, 60, 61
};

bool solve(const vector<int>& predef, int len, const string& s) {
    // print("pre", len);
    int n = s.size();
    if (n < len) {
        return false;
    }

    vector<int> dp;

    for (auto rule : predef) {
        bool flag = true;
        for (int i = 0; i < len; i++) {
            int p = (rule & (1 << (len - i - 1)))? 1: 0;
            int q = s[i] == '?' ? -1 : s[i] - '0';

            if (q != -1 && p != q) {
                flag = false;
                break;
            }
        }
        if (flag) {
            dp.push_back(rule);
        }
    }

    for (int i = len; i < n; i++) {
        /*
        for (auto num : dp) {
            printf("%d ", num);
        }
        puts("\n---");
        */
        vector<int> dp2;

        int cur = s[i] == '?' ? -1 : s[i] - '0';

        for (auto num : dp) {
            num &= (1 << (len - 1)) - 1;
            num *= 2;

            if (cur != -1) {
                int nxt = num + cur;
                if (binary_search(predef.begin(), predef.end(), nxt)) {
                    dp2.push_back(nxt);
                }
            } else {
                for (int j = 0; j <= 1; j++) {
                    int nxt = num + j;
                    if (binary_search(predef.begin(), predef.end(), nxt)) {
                        dp2.push_back(nxt);
                    }
                }
            }
        }
        dp = dp2;
    }

    return !dp.empty();
}

int main() {
    int T;
    input(T);

    int n;
    string s;
    for (int case_ = 0; case_ < T; case_++) {
        input(n, s);

        printf("Case #%d: ", case_ + 1);

        if (n < 5 || (n == 5 && solve(predef5, 5, s)) || solve(predef6, 6, s)) {
            puts("POSSIBLE");
        } else {
            puts("IMPOSSIBLE");
        }
    }

    return 0;
}

/*
 *
^^^TEST^^^
4
6
0111?1
5
100??
5
001??
6
001?00
-------
Case #1: IMPOSSIBLE
Case #2: POSSIBLE
Case #3: POSSIBLE
Case #4: IMPOSSIBLE
$$$TEST$$$


^^^TEST^^^
2
1
0
5
11111
-------
Case #1: POSSIBLE
Case #2: IMPOSSIBLE
$$$TEST$$$

^^^TEST^^^
5
9
100???001
5
100??
5
?????
5
??1??
5
11111
-----
Case #1: IMPOSSIBLE
Case #2: POSSIBLE
Case #3: POSSIBLE
Case #4: POSSIBLE
Case #5: IMPOSSIBLE
$$$TEST$$$

^^^^^TEST^^^^
2
10
1?010?100?
10
1?01001?01
-------
Case #1: POSSIBLE
Case #2: POSSIBLE
$$$TEST$$$

*/
