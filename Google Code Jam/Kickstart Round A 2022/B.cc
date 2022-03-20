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

int main() {
    int T;
    input(T);

    string s;
    for (int case_ = 0; case_ < T; case_++) {
        input(s);

        int n = s.size();

        int tot = 0;
        for (int i = 0; i < n; i++) {
            tot += s[i] - '0';
            tot %= 9;
        }

        printf("Case #%d: ", case_ + 1);
        if (tot == 0) {
            puts(s.c_str());
        } else {
            int rem = 9 - tot;

            vector<char> res;

            bool flag = false;
            for (int i = 0; i < n; i++) {
                if (flag) {
                    res.push_back(s[i]);
                    continue;
                }

                int c = s[i] - '0';
                if (c <= rem) {
                    res.push_back(s[i]);
                } else {
                    res.push_back('0' + rem);
                    res.push_back(s[i]);
                    flag = true;
                }
            }
            if (!flag) {
                res.push_back('0' + rem);
            }
            for (auto c : res) {
                printf("%c", c);
            }
            puts("");
        }
    }

    return 0;
}

/*

^^^TEST^^^
3
5
33
12121
-----
Case #1: 45
Case #2: 333
Case #3: 121212
$$$TEST$$$

^^^TEST^^^
5
9
9990888
888
11111111
222
-----
Case #1: 9
Case #2: 39990888
Case #3: 3888
Case #4: 111111111
Case #5: 2223
$$$TEST$$$

*/
