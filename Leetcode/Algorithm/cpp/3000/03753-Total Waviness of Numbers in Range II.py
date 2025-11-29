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

using llint = long long;

class Solution {
public:
    llint totalWaviness(llint num1, llint num2) {
        return solve(num2) - solve(num1 - 1);
    }

    llint solve(llint num) {
        dp.clear();
        string s = std::to_string(num);
        int n = s.size();

        return dfs(0, n, 0, s, false /* lt */).first;
    }

    pair<llint, llint> dfs(int cur, int n, int pre, const std::string& num, bool lt) {
        if (cur == n) {
            return {0, 1};
        }
        const pair<int, int> key = {pre, cur};

        if (pre && cur >= 2 && lt) {
            if (dp.count(key)) {
                return dp[key];
            }
        }
        const int u = num[cur] - '0';

        pair<llint, llint> res = {0, 0};
        for (int i = 0; i < 10; i++) {
            llint delta = 0;
            if (cur >= 2) {
                delta += calc(pre, i);
            }

            if (lt) {
                auto p = dfs(cur + 1, n, get_next(pre, i), num, lt);
                res.first += p.first + p.second * delta;
                res.second += p.second;
            } else {
                if (i <= u) {
                    auto p = dfs(cur + 1, n, get_next(pre, i), num, i < u);
                    res.first += p.first + p.second * delta;
                    res.second += p.second;
                }
            }
        }

        // print(n, cur, pre, lt, res);

        if (cur >= 2 && lt) {
            dp[key] = res;
        }
        return res;
    }

    int get_next(int pre, int cur) {
        int b = pre % 11;
        if (b == 0 && cur == 0) {
            return 0;
        } else {
            return b * 11 + (cur + 1);
        }
    }

    int calc(int pre, int cur) {
        int a = pre / 11;
        int b = pre % 11;
        if (a == 0 || b == 0) {
            return 0;
        }
        cur += 1;
        return (a < b && b > cur) || (a > b && b < cur);
    }
private:
    map<pair<int, int>, pair<llint, llint> > dp;
};


