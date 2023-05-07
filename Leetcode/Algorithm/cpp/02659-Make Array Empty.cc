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

struct BiTree {
    BiTree() {}

    BiTree(int size) {
        _tree.resize(size + 1);
    }

    inline int lowbit(int x) {
        return x & (-x);
    }

    void clear() {
        fill(_tree.begin(), _tree.end(), 0);
    }

    void add(size_t pos, int value) {
        while (pos < _tree.size()) {
            _tree[pos] += value;
            pos += lowbit(pos);
        }
    }

    llint sum(size_t pos) {
        llint res = 0;
        while (pos) {
            res += _tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    llint sum(size_t a, size_t b) {
        return sum(b) - sum(a - 1);
    }

    vector<llint> _tree;
};

class Solution {
public:
    llint countOperationsToEmptyArray(vector<int>& nums) {
        const int n = nums.size();
        BiTree bitree(n + 123);

        for (int i = 0; i < n; i++) {
            mp_numidx[nums[i]] = i;
            mp_idxnum[i] = nums[i];
            bitree.add(i + 1, 1);
        }

        llint res = 0;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            int nxt = mp_numidx.begin()->first;
            int nxtidx = mp_numidx.begin()->second;

            if (nxtidx != idx) {
                if (idx <= nxtidx) {
                    res += bitree.sum(idx + 1, nxtidx);
                } else {
                    res += bitree.sum(idx + 1, n + 1);
                    res += bitree.sum(1, nxtidx);
                }
                idx = nxtidx;
            }

            res++;
            mp_numidx.erase(mp_numidx.find(nxt));
            mp_idxnum.erase(mp_idxnum.find(nxtidx));

            auto iter = mp_idxnum.lower_bound(idx);
            if (iter == mp_idxnum.end()) {
                idx = mp_idxnum.begin()->first;
            } else {
                idx = iter->first;
            }
            bitree.add(nxtidx + 1, -1);
            // print(res);
        }
        print(res);
        return res;
    }
private:
    map<int, int> mp_numidx;
    map<int, int> mp_idxnum;
};


int _main() {
    {
        vector<int> v = {3,4,-1};
        assert(Solution().countOperationsToEmptyArray(v) == 5);
    }

    {
        vector<int> v = {1,2,4,3};
        assert(Solution().countOperationsToEmptyArray(v) == 5);
    }

    {
        vector<int> v = {1,2,3};
        assert(Solution().countOperationsToEmptyArray(v) == 3);
    }

    return 0;
}
