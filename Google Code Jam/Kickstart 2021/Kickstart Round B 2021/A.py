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

vector<int> solve(int n, const string& s) {
    deque<char> dq;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (dq.empty()) {
            dq.push_back(c);
        } else if (c > *dq.rbegin()) {
            dq.push_back(c);
        } else {
            dq.clear();
            dq.push_back(c);
        }
        res[i] = dq.size();
    }
    return res;
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        int n;
        string s;

        input(n, s);

        printf("Case #%d:", case_ + 1);

        vector<int> res = solve(n, s);
        for (auto num : res) {
            printf(" %d", num);
        }
        puts("");
    }

    return 0;
}

/*

^^^TEST^^^
2
4
ABBC
6
ABACDA
-----
Case #1: 1 2 1 2
Case #2: 1 2 1 2 3 1
$$$TEST$$$

*/
