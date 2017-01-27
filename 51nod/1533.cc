#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class BITree {
public:
    BITree(size_t size_): _size(size_ + 100) {
        _bitree = vector<int>(_size, 0);
    }

    void add(int pos, int value) {
        while (pos < _size) {
            _bitree[pos] += value;
            pos += lowbit(pos);
        }
    }

    int sum(int pos) {
        int res = 0;
        while (pos > 0) {
            res += _bitree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    int sum(size_t a, size_t b) {
        return sum(b) - sum(a - 1);
    }
private:
    int lowbit(int x) {
        return x & (-x);
    }
private:
    vector<int> _bitree;
    size_t _size;
};

class Solution {
public:
    Solution(size_t n_, vector<int> ns_): _n(n_) {
        for (size_t i = 1; i <= _n; i++) {
            _ns.push_back({ns_[i - 1], i});
        }
        _ans = vector<int>(_n, 0);
        sort(_ns.begin(), _ns.end());
    }

    int solve() {
        BITree bitree(_n);
        int ans = 0;
        for (auto p: _ns) {
            int pos = p.second;
            
            for (int i = 1; i <= _n - 1; i++) {
                size_t l = i * (pos - 1) + 2;
                size_t r = i * pos + 1;

                if (l <= _n) {
                    _ans[i] += bitree.sum(l, min(_n, r));
                } else {
                    break;
                }
            }
            
            bitree.add(pos, 1);
        }
        return ans;
    }
    
    void show() {
        for (int i = 1; i < _n; i++) {
            printf("%d ", _ans[i]);
        }
        puts("");
    }
private:
    size_t _n;
    vector<int> _ans;  
    vector<pair<int, int> > _ns;
};

int main() {
    freopen("input.txt", "r", stdin);
    
    int n;
    input(n);

    vector<int> ns(n, 0);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
        mp[ns[i]] = -1;
    }
    
    int idx = 1;
    for (auto& p: mp) {
        p.second = idx++;
    }
    for (auto& item: ns) {
        item = mp[item];
    }
    
    auto sol = Solution(n, ns);
    sol.solve();
    sol.show();

    return 0;
}
