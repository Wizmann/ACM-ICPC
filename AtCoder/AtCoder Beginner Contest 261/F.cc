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

int lowbit(int x) { return x & (-x); }

class Bitree {
public:
    Bitree(int n_) : n(n_), tree(n_ + 1, 0) {
        // pass
    }

    void add(int pos, int x) {
        assert(pos > 0);
        while (pos <= n) {
            tree[pos] += x;
            pos += lowbit(pos);
        }
    }

    int sum(int pos) {
        int res = 0;
        while (pos) {
            res += tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    int sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }

private:
    int n;
    vector<int> tree;
};

struct Ball {
    int color;
    int value;
};

llint solve(vector<int>& nums) {
    const int n = nums.size();
    map<int, int> mp;

    for (auto num : nums) {
        mp[num] = -1;
    }

    int idx = 1;
    for (auto& p : mp) {
        p.second = idx++;
    }

    for (int i = 0; i < n; i++) {
        nums[i] = mp[nums[i]];
    }

    map<int, vector<int> > mp2;
    for (int i = 0; i < n; i++) {
        mp2[nums[i]].push_back(i + 1);
    }

    Bitree bitree(n + 1);

    llint res = 0;
    for (auto iter = mp2.rbegin(); iter != mp2.rend(); ++iter) {
        const auto& ps = iter->second;

        for (auto pos : ps) {
            res += bitree.sum(pos);
        }

        for (auto pos : ps) {
            bitree.add(pos, 1);
        }
    }

    return res;
}

llint solve1(const vector<Ball>& balls) {
    vector<int> vs;
    for (const auto& ball : balls) {
        vs.push_back(ball.value);
    }
    return solve(vs);
}

llint solve2(const vector<Ball>& balls) {
    const int n = balls.size();
    map<int, vector<int> > mp;

    for (int i = 0; i < n; i++) {
        const auto& ball = balls[i];
        mp[ball.color].push_back(ball.value);
    }

    llint res = 0;
    for (auto& p : mp) {
        res += solve(p.second);
    }

    return res;
}

int main() {
    int n;
    input(n);

    vector<Ball> balls(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &balls[i].color);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &balls[i].value);
    }

    print(solve1(balls) - solve2(balls));

    return 0;
}

/*

^^^TEST^^^
5
1 5 2 2 1
3 2 1 2 1
-----
6
$$$TEST$$$

^^^TEST^^^
3
1 1 1
3 2 1
-----
0
$$$TEST$$$

^^^TEST^^^
3
3 1 2
1 1 2
-----
0
$$$TEST$$$

*/
