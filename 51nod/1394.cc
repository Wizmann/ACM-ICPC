#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

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

int n, q;
vector<int> nums;
vector<pair<int, int> > queries;
unordered_map<int, int> mp;
unordered_multiset<int> mst;
int idx;
llint ans = 0;
BiTree bit_a;
BiTree bit_b;

// oh that kid is crazy

void calc_add(int num) {
    int u = mp[num];
    bit_a.add(u, 1);
    bit_b.add(u, num);
    mst.insert(num);

    llint l = bit_a.sum(1, u - 1);
    llint r = bit_a.sum(u + 1, idx);

    llint ll = bit_b.sum(1, u - 1);
    llint rr = bit_b.sum(u + 1, idx);

    ans += l * num - ll;
    ans += rr - r * num;
}

void calc_minus(int num) {
    auto iter = mst.find(num);
    if (iter == mst.end()) {
        puts("-1");
        return;
    } else {
        mst.erase(iter);
    }
    int u = mp[num];
    bit_a.add(u, -1);
    bit_b.add(u, -num);

    llint l = bit_a.sum(1, u - 1);
    llint r = bit_a.sum(u + 1, idx);

    llint ll = bit_b.sum(1, u - 1);
    llint rr = bit_b.sum(u + 1, idx);

    ans -= l * num - ll;
    ans -= rr - r * num;
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> q);
    nums.resize(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        st.insert(nums[i]);
    }
    
    int cmd = 0;
    int param = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d", &cmd);
        if (cmd <= 2) {
            scanf("%d", &param);
            st.insert(param);
        }
        queries.push_back({cmd, param});
    }
    
    idx = 1;
    for (auto num: st) {
        mp[num] = idx++;
    }

    ans = 0;
    bit_a = BiTree(idx);
    bit_b = BiTree(idx);

    for (auto num: nums) {
        calc_add(num);
    }

    for (auto query: queries) {
        cmd = query.first;
        param = query.second;
        if (cmd == 1) {
            calc_add(param);
        } else if (cmd == 2) {
            calc_minus(param);
        } else {
            printf("%lld\n", ans);
        }
    }
    return 0;
}
