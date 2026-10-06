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

const int N = 512345;

inline int lowbit(int x)
{
    return x & (-x);
}

class BITree { // 点更新，区间查询
public:
    BITree() {}
    BITree(int n_): n(n_), tree(n + 1, 0) {}

    void add(int pos, int val) {
        while (pos < n) {
            tree[pos] += val;
            pos += lowbit(pos);
        }
    }

    int sum(int pos) {
        int res = 0;
        while (pos > 0) {
            res += tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    int sum(int a ,int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        const int n = nums.size();
        BITree bit(n + 233);

        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

        for (auto& num : nums) {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        }

        llint inv = 0;
        llint mini = INFLL;
        for (int i = 0; i < n; i++) {
            if (i - k >= 0) {
                int pre = nums[i - k];
                inv -= bit.sum(1, pre - 1);
                bit.add(pre, -1);
            }
            int cur = nums[i];
            inv += bit.sum(cur + 1, n);
            bit.add(cur, 1);

            if (i >= k - 1) {
                mini = min(mini, inv);
            }
        }
        // print(mini);
        return mini;
    }
};
