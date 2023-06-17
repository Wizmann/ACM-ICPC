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

template <typename T, class Compare=less<int> >
class BITreeRMQ {
public:
    BITreeRMQ() {}
    BITreeRMQ(int n_, const vector<T>& nums_) : n(n_), nums(nums_), tree(nums_) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < lowbit(i); j <<= 1) {
                tree[i] = cmp(tree[i], tree[i - j]);
            }
        }
    }

    T query(int a, int b) {
        T ans = nums[b];
        while (a != b) {
            for (b = b - 1; b - lowbit(b) >= a; b -= lowbit(b)) {
                ans = cmp(ans, tree[b]);
            }
            ans = cmp(ans, nums[b]);
        }
        return ans;
    }

    void modify(int pos, T val) {
        nums[pos] = val;
        for (int i = pos; i < n; i += lowbit(i)) {
            tree[i] = nums[i];
            for (int j = 1; j < lowbit(i); j <<= 1) {
                tree[i] = cmp(tree[i], tree[i - j]);
            }
        }
    }
private:
    T cmp(T a, T b) {
        return cmp_func(a, b)? a: b;
    }

    inline int lowbit(int x) {
        return x&(-x);
    }

    int n;
    vector<T> nums;
    vector<T> tree;
    Compare cmp_func = Compare();
};


class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        const int n = nums1.size();
        map<int, int> mp;
        vector<int> rmp;
        for (auto num : nums1) {
            mp[num] = -1;
        }
        for (auto num : nums2) {
            mp[num] = -1;
        }
        for (auto q : queries) {
            int a = q[0];
            int b = q[1];
            mp[a] = -1;
            mp[b] = -1;
        }

        int m = mp.size() + 1;
        rmp.resize(m);
        int idx = 1;
        for (auto& p : mp) {
            p.second = idx;
            rmp[idx] = p.first;
            idx++;
        }

        vector<pair<int, int> > ps;
        for (int i = 0; i < n; i++) {
            ps.push_back({ mp[nums1[i]], mp[nums2[i]] });
        }
        sort(ps.begin(), ps.end());
        for (int i = 0; i < (int)queries.size(); i++) {
            auto& q = queries[i];
            q[0] = mp[q[0]];
            q[1] = mp[q[1]];
            q.push_back(i);
        }
        sort(queries.begin(), queries.end(), 
            greater<decltype(queries[0])>());

        vector<int> vinit(m, -1);
        BITreeRMQ<int, greater<int> > rmq(vinit.size(), vinit);

        int ptr = ps.size() - 1;
        vector<int> res(queries.size());
        for (auto& q : queries) {
            while (ptr >= 0 && ps[ptr].first >= q[0]) {
                int v = rmp[ps[ptr].first] + rmp[ps[ptr].second];
                int u = rmq.query(ps[ptr].second, ps[ptr].second);
                // print(v, u, ptr, rmp[ps[ptr].first], rmp[ps[ptr].second]);
                if (v > u) {
                    rmq.modify(ps[ptr].second, v);
                }
                ptr--;
            }
            res[q[2]] = rmq.query(q[1], m - 1);
        }
        return res;
    }
};

